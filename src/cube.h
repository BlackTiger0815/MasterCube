//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <time.h>
#include <stdio.h>
using namespace std;

class Cube
{
private:
	int _old[6][3][3] = {
		{ { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } }, //yellow side
		{ { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } }, //orange side
		{ { 2, 2, 2 }, { 2, 2, 2 }, { 2, 2, 2 } }, //blue side
		{ { 3, 3, 3 }, { 3, 3, 3 }, { 3, 3, 3 } }, //red side
		{ { 4, 4, 4 }, { 4, 4, 4 }, { 4, 4, 4 } }, //green side
	};
	int _cube[6][3][3] = {
		{ { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } }, //yellow side
		{ { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } }, //orange side
		{ { 2, 2, 2 }, { 2, 2, 2 }, { 2, 2, 2 } }, //blue side
		{ { 3, 3, 3 }, { 3, 3, 3 }, { 3, 3, 3 } }, //red side
		{ { 4, 4, 4 }, { 4, 4, 4 }, { 4, 4, 4 } }, //green side
		{ { 5, 5, 5 }, { 5, 5, 5 }, { 5, 5, 5 } } }; //white side

	string moves = "";
	
	
public: 
	Cube(){};
	~Cube(){};
	
//--------------- copied from --------------//
//--https://github.com/ekuecks/rubiks-cube--//
//------------- and modificated ------------//
	void printCube(); 
	void printMoves(); //print moves made previosly
	void copyCube();
	void removeLast(); //removes the last move performed
	void clearMoves(); //clears all moves
	string last();
	void scramble();
	
// moves - see https://ruwix.com/the-rubiks-cube/notation/
	void r();
	void ri();
	void l();
	void li();
	void u();
	void ui();
	void d();
	void di();
	void f();
	void fi();
	void b();
	void bi();
//------------------------------------------//

// cube questions //
	int array_to_int(int, int, int);
	int int_to_array(int );

	string feedback;
	string question = ""; // changed here to i can access it easily in questio_cube
	string answer = ""; // same as above
	void splitQuestion(string s, int n); //Frage am Server spalten in Pos und Farbe
	void generateMastermindAnswer(int *questions, int *reference, int n);
	
};
