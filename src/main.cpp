#include "cube.h"

int main (int argc, char* argv[]) {
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
