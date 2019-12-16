#include "cube.h"
#include <iostream>

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
	solved.splitQuestion(s, n);
	std::cout <<"test";

    return 0;
}
