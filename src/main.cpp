#include "cube.h"
#include <iostream>

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
	string ServerIPAdress = "", ServerPort = "";
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
	
	
	Cube solved;
	Cube scrambled;

/*	scrambled.scramble();
	solved.printCube();
	cout << "------------------" << endl<<endl;
	scrambled.printCube();
*/
	string s;
	int n = 0;

	cin >> n >> s;
	solved.splitQuestion(s, n);
	std::cout <<"test";

    return 0;
}
