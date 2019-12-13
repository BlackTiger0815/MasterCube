#include "cube.h"
#include "debug.h"



int main (int argc, char* argv[]) {
	
	//new 13.12.2019 adding debug
	debug Debugger;
	Debugger.setdebug(0);
	Debugger.setdebug(1);
	Debugger.printf("MasterCube is starting");
	// Debug inilasition over
	
	
	
	
	
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
	scrambled.splitQuestion(s, n);

    return 0;
}
