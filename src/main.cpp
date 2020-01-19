#include "debug.h"
#include "solver.h" //Solver for Mastermind and Rubiks Cube
#include <list>

int main (int argc, char* argv[]) {
	
	//new 13.12.2019 adding debug by Thomas
	debug Debugger;
	Debugger.setdebug(0);
	Debugger.setdebug(1);
	Debugger.printf("MasterCube is starting");
	// Debug inilasition over
	
	
	// here server
	// wait for answer
	// send answer
	
	
	
	
	//here client
	//get n
	// generate solver
	//Mastermind solver
	MastermindSolver clever;
	clever.set_n(3);
	clever.generate_question();

	// generate question
	// send question
	// calculate answer
	// answer to IDA*
	// rotate?
	
	//repeat
	
	

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
	solved.printCube();
	scrambled.scramble();
	scrambled.printCube();
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
	RubiksCubeSolver solver;
	//solver.calculateManhattanDistance(4);
	
	
    return 0;
}
