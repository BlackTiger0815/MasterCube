#include "cube.h"
#include "debug.h"
#include "solver.h" //Solver for Mastermind and Rubiks Cube

int main (int argc, char* argv[]) {

	//new 13.12.2019 adding debug by Thomas
	debug Debugger;
	Debugger.setdebug(0);
	Debugger.setdebug(1);
	Debugger.printf("MasterCube is starting");
	// Debug inilasition over


	//15.12.2019 handling of calling parameters by Isabella
	// Port and IP-adress needs to be calculated from String for using it in communication
	// @Elisabeth -> bei mir melden wie dus brauchst ;)
	/*string ServerIPAdress = "", ServerPort = "";
	string modus = "";

	if(argc == 1)
		Debugger.printf("Not enough parameters");
	else{

		//for(int i=0; i<argc; i++){
		//	cout << i<< ":  " << argv[i] << endl;
		//}

		if(string(argv[1]) == "client"){
			modus = "client";
			ServerIPAdress = argv[2];
			ServerPort = argv[3];
		}
		else if(string(argv[1]) == "server"){
			modus = "server";
			ServerPort = argv[2];
		}
		else{
			Debugger.printf("Wrong init-parameters");
		}

	}
	// parameter handling over
	*/

	Cube solved;
	Cube scrambled;
	Cube tmp(0);

	solved.printCube();
	scrambled.scramble();
	scrambled.printCube();
	tmp.printCube();

/*	solved.printCube();
	cout << "------------------" << endl<<endl;
	scrambled.printCube();

	string s;
	int n = 0;
	cin >> n >> s;
	scrambled.splitQuestion(s, n);
*/
	//Debugger.printf( scrambled.array_to_int(5,2,2) ); //this gets you 54
	//Debugger.printf( scrambled.int_to_array(2) );  // if theres an int smaller than 100, then there are leading zeros to consider

	//Rubiks Cube Solver
	// RubiksCubeSolver RubiksSolver;
	// int a,b,c;
	// //cin >> a >> b >> c;
	// //RubiksSolver.calculateManhattanDistance(scrambled, a, b, c);
	// float h1 = RubiksSolver.max_CornerEdge_sum(scrambled);
	// RubiksSolver.writeManhattenDistance(h1);
	// cout << "Manhatten Distanz = " << h1 << endl;

	// bool admissible = true;
	// cin >> admissible;
	// if(admissible == true){
	// 	float h2 = RubiksSolver.calculateNumUnsolvedCubies(scrambled, admissible);
	// 	//RubiksSolver.writeUnsolvedCubies(h2);
	// 	cout << "Num unsolved Cubies = " << h2 << endl;
	// }
	// else{
	// 	float h2 = RubiksSolver.calculateNumUnsolvedCubies(scrambled, admissible);
	// 	//RubiksSolver.writeUnsolvedCubies(h2);
	// 	cout << "Num unsolved Cubies = " << h2 << endl;
	// }



	// //Mastermind solver
	// MastermindSolver clever;
	// //clever.testing();  //ENDLOSSCHLEIFE


	return 0;
}
