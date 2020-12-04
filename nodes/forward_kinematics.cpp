#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "nav_msgs/Odometry.h"
#include <ros/console.h>
#include <opencv2/highgui.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#define JointNum 7


// we know difference in wheel left, wheel rigt, Last Position, Last Orientation, Last Postion Wheel left, Last Postion Wheel right, and want:
// current Postion, current Velocity, current Orientation, current Wheel left, current wheel right
// we need atleast 3 Functions

// distance between two Point2ds
double distance_A_B( cv::Point2d A, cv::Point2d B);

// Angle betweeen two vectors
double angle( cv::Point2d A,  cv::Point2d B);

// Given Orientation and Point2d and length of vector construct vector into Orientation
cv::Point2d angle_vector( double orientation_angle, cv::Point2d A, double length);

// Given Radius and Distance travelled, returns an angle
double angle_ICR_Wheel( double radius, double bogenmas);

// using this angle to create new Point2d from ICR - simple geometrics really
cv::Point2d new_Wheel_Point2d( double radius, cv::Point2d ICR_Point2d,  cv::Point2d Wheel, double angle_ICR);

// its a match - function to find where two vectors would intersect
cv::Point2d ICR_calculater( cv::Point2d A, cv::Point2d B,double orientation_angle, double wheel_left, double wheel_right);

// function to find a Point2d betweeen two Point2ds - The MidPoint2d Formula
cv::Point2d center_finder( cv::Point2d A,  cv::Point2d B);

// start values, Center, Orientation, Wheel_diameter, Car_breite
int Car_breite = 200;
double Wheel_diameter = 30;

double distance_A_B( cv::Point2d A, cv::Point2d B){ //needed for velocity

    cv::Point2d diff = A - B;
    return cv::sqrt(diff.x*diff.x + diff.y*diff.y);
}

double angle( cv::Point2d A,  cv::Point2d B){  //needed for Orientation update - TEST for 90° Orientation - should not change fast...

	double zahler = (A.x * B.x) + (A.y * B.y);
	double A_abs = sqrt(A.x*A.x + A.y*A.y);
	double B_abs = sqrt(B.x*B.x + B.y*B.y);
	double nenner = A_abs*B_abs;

	return acos( zahler/ nenner);
};

cv::Point2d angle_vector( double orientation_angle, cv::Point2d A, double length){ //given an angle calculates a vector that goes from provided Point2d into direction of angle

	cv::Point2d B;
	double xx = 1*cos( orientation_angle);
	double yy = 1* sin( orientation_angle);
	B = A + cv::Point2d( xx, yy);
	double nenner = sqrt(B.x*B.x + B.y*B.y);
	B = length/nenner * B;
	return B;
};

double angle_ICR_Wheel( double radius, double bogenmas){

	double nenner = 2 * M_PI * radius;

	return bogenmas/nenner;
};

cv::Point2d new_Wheel_Point2d( double radius, cv::Point2d ICR_Point2d,  cv::Point2d Wheel, double bogenmas){
	std::cout << radius << " " << ICR_Point2d << " " << Wheel << " " << bogenmas << std::endl;

	double add_angle = Wheel.x - ICR_Point2d.x; //angle we have to add

	double angle_ICR = angle_ICR_Wheel(radius , bogenmas);

	double xx = ICR_Point2d.x + radius * cos( angle_ICR + acos( add_angle));
	double yy = ICR_Point2d.y + radius * sin( angle_ICR + acos( add_angle));

	std::cout << add_angle << " " << angle_ICR << " " << xx << " " << yy << std::endl;

	return cv::Point2d(xx, yy);

};

cv::Point2d ICR_calculater( cv::Point2d A, cv::Point2d B,double orientation_angle, double wheel_A, double wheel_B){
						//Prius.Wheel_left, Prius.Wheel_right, Prius.Orientation, Prius.joint_positions[4] ,Prius.joint_positions[5]

	//first construct vectors into direction of ICR
	cv::Point2d vectorA = angle_vector( orientation_angle + wheel_A + (M_PI/2) , A, 1 );
	cv::Point2d vectorB = angle_vector( orientation_angle + wheel_B + (M_PI/2) , B,  1 );
	// A + var_1* vectorA = B+ var_2*vectorB

	double var_1_nenner = vectorA.y*vectorB.x - vectorA.x* vectorB.y;
	double var_1_zahler  = B.y*vectorB.x + vectorB.y *A.x - vectorB.y*B.x - B.y*vectorB.x;

	double var_1 = var_1_zahler / var_1_nenner;

	//std::cout << A << " and " << B << std::endl;
	// std::cout << vectorA << " and " << vectorB << std::endl;
	// std::cout << "var_1 = " << var_1_zahler << " / " << var_1_nenner << std::endl;

	cv::Point2d ICR = A + var_1*vectorA;
	return ICR;
};

cv::Point2d center_finder( cv::Point2d A,  cv::Point2d B){

	double xx = (A.x + B.x)/2;
	double yy = (A.y + B.y)/2;

	return cv::Point2d(xx, yy);
};


class ForwardKinemtatics{
public:
	void joint_statesCallback(const sensor_msgs::JointState::ConstPtr& msg);

	cv::Point2d Center_now;
	cv::Point2d Center_past = cv::Point2d(0.0 ,0.0);

	double velocity;

	double Orientation = 0;

	cv::Point2d Wheel_left;
	cv::Point2d Wheel_right;

	double Wheel_left_last_angle = 0;
	double Wheel_right_last_angle = 0;


//private:
	std::string joint_names[JointNum];
	float joint_positions[JointNum];
	float joint_velocity[JointNum];
	int seq;
	int msg_cnt;
};

void ForwardKinemtatics::joint_statesCallback(const sensor_msgs::JointState::ConstPtr& msg){
	seq = msg->header.seq;
	for(int i=0; i<JointNum; i++){
		joint_names[i] = msg->name[i].c_str();
		joint_positions[i] = msg->position[i];
		joint_velocity[i] = msg->velocity[i];
	}
	msg_cnt++;
}

int main(int argc, char **argv)
{
	// Init Prius
	ForwardKinemtatics Prius;
	Prius.msg_cnt = 0;
	Prius.Wheel_left.x = 0.0;
	Prius.Wheel_left.y = -Car_breite/2;
	Prius.Wheel_right.x = 0.0;
	Prius.Wheel_right.y = Car_breite/2;


	ros::init(argc, argv, "joint_statesListener");
	//ros::NodeHandle nh("~");
	ros::NodeHandle nh;
	ros::Subscriber joint_states_sub = nh.subscribe("/joint_states", 1, &ForwardKinemtatics::joint_statesCallback, &Prius);
	ros::Publisher odom_pub = nh.advertise<nav_msgs::Odometry>("/odom", 1);

	while(ros::ok()){
		//std::cout << Prius.seq << std::endl;
		std::cout << "joint_names: joint_positions joint_velocity" << std::endl;
		for(int i=0; i<JointNum; i++){
			std::cout << i <<" "<< Prius.joint_names[i] << ": " << Prius.joint_positions[i] << " " << Prius.joint_velocity[i] << std::endl;
		}
		std::cout << std::endl;

		//Filter of orst Frame -> causes NAN
		if(Prius.msg_cnt != 0){

			// instert calculations here ...
		    //	if ( Prius.joint_positions[4] > 0.1 || Prius.joint_positions[4] < -0.01) // sonst fahren wir nur geradeaus -> changed to NAN detector

			// is nan? // nan means we got a zero in a calculation ... which we dont want
			// Prius.seq or start at Prius.seq > 5 or similar or when we get  input from simulation...
			std::string nan_detector = "NO";

			//std::cout << Prius.Wheel_left << " and " << Prius.Wheel_right << std::endl;
			cv::Point2d ICR = ICR_calculater( Prius.Wheel_left, Prius.Wheel_right, Prius.Orientation, Prius.joint_positions[4] ,Prius.joint_positions[5]);
			std::cout <<" ICR is at " << ICR <<std::endl;
			double radius_right_wheel_to_icr = distance_A_B(  Prius.Wheel_right, ICR);
			std::cout <<" radius_right_wheel_to_icr is at " << radius_right_wheel_to_icr <<std::endl;
			double radius_left_wheel_to_icr =   distance_A_B(  Prius.Wheel_left,   ICR);
			std::cout <<" radius_left_wheel_to_icr is at " << radius_left_wheel_to_icr <<std::endl;
			double bogenmass_left = (Prius.Wheel_left_last_angle - Prius.joint_positions[2])*Wheel_diameter; //alternativ über geschwindigkeit
			std::cout <<" bogenmass_left is at " << bogenmass_left <<std::endl;
			double bogenmass_right = (Prius.Wheel_right_last_angle - Prius.joint_positions[3])*Wheel_diameter;
			std::cout <<" bogenmass_right is at " << bogenmass_right <<std::endl;

			// nan abfrage bevor wir updaten // frage ist ob das alle fälle abfängt ...  to-be-seen ...  oder wir jede funktion überprüfen müssen ..... möglich ist auch das wir in der Funktion selbst was ändern müssen wie Werte auf max zu setzten...
			if ( isnan( ICR.x) or  isnan( ICR.y) )
			{
				nan_detector = "YES";
				std::cout <<" nan_detector is at" << nan_detector <<std::endl;
			}

			//if( nan_detector == "NO")
			//{
				Prius.Wheel_left_last_angle = Prius.joint_positions[2];  // um den unterschied zu sehen wieviel sich ein rad gedreht hat
				Prius.Wheel_right_last_angle = Prius.joint_positions[3];

				Prius.Wheel_left = new_Wheel_Point2d ( radius_left_wheel_to_icr, ICR, Prius.Wheel_left, bogenmass_left);
				std::cout <<" Wheel_left is at" << Prius.Wheel_left <<std::endl;
				// cv::Point2d tmp1 = new_Wheel_Point2d ( radius_left_wheel_to_icr, ICR, Prius.Wheel_left, bogenmass_left);
				// std::cout <<" NEW Wheel_left is at" << tmp1 <<std::endl;
				// cv::Point2d tmp2 = new_Wheel_Point2d ( radius_left_wheel_to_icr, ICR, Prius.Wheel_left, bogenmass_left);
				// std::cout <<" NEW Wheel_left is at" << tmp2 <<std::endl;

				Prius.Wheel_right = new_Wheel_Point2d ( radius_right_wheel_to_icr, ICR, Prius.Wheel_right, bogenmass_right);
				std::cout <<" Wheel_right is at" << Prius.Wheel_right <<std::endl;

				// new position ist zwischen Wheel left und wheel right in der mitte
				Prius.Center_now = center_finder( Prius.Wheel_left, Prius.Wheel_right);
				std::cout <<" Center_now is at" << Prius.Center_now <<std::endl;
				Prius.velocity = distance_A_B(Prius.Center_now, Prius.Center_past);
				std::cout <<" velocity is at" << Prius.velocity <<std::endl;

				Prius.Orientation = angle( Prius.Center_now, Prius.Center_past); // might be wrong
				std::cout <<" Orientation is at" << Prius.Orientation <<std::endl;
				Prius.Center_past = Prius.Center_now;
			//}

			if( nan_detector == "YES")
			{
				// geradeausfahren
				// Orientation unchanged
				double way_travelled =  (Prius.joint_positions[2]  -Prius.Wheel_left_last_angle)   *Wheel_diameter;
				//center und räder update
				Prius.Center_now = angle_vector( Prius.Orientation, Prius.Center_past , way_travelled);
				Prius.Wheel_left =   angle_vector( Prius.Orientation, Prius.Wheel_left , way_travelled);
				Prius.Wheel_right =  angle_vector( Prius.Orientation, Prius.Wheel_left , way_travelled); // räder & orientation winkel sind ja unverändert

				std::cout <<" way_travelled is at" << way_travelled <<std::endl;
				std::cout <<" Center_now is at" << Prius.Center_now <<std::endl;
				Prius.velocity = distance_A_B(Prius.Center_now, Prius.Center_past);
				std::cout <<" velocity is at" << Prius.velocity <<std::endl;

				Prius.Center_past = Prius.Center_now;
			}



		}
		else{
			// ignore messages
			std::cout <<" Ignored seq " << Prius.msg_cnt <<std::endl;
		}

		std::cout << std::endl;

		//publish odom
		nav_msgs::Odometry pub_msg;
		pub_msg.header.frame_id = "id";
		// Position
		pub_msg.pose.pose.position.x = Prius.Center_now.x;
		pub_msg.pose.pose.position.y = Prius.Center_now.y;
		// Orientation (only z = Yaw)
		tf2::Quaternion quat_orientation;
		quat_orientation.setRPY(0, 0, Prius.Orientation);
		tf2::convert(quat_orientation, pub_msg.pose.pose.orientation);
		// velocity
		pub_msg.twist.twist.linear.x = Prius.velocity;
		odom_pub.publish(pub_msg);



		//ros::Duration(0.5).sleep(); // rausnehmen sobald der Algorithmus läuft!!!
		ros::spinOnce();
	}


	return 0;
}
