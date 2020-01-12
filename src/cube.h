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
public:
	int _old[6][3][3];
	int _cube[6][3][3]; //white side

	string moves = "";
	string question = "";
	string answer = "";

public:
	Cube(int n=1){
		if(n==0){
			for(int i=0;i<6;i++)
				for(int j=0;j<3;j++)
					for(int k=0;k<3;k++)
					{
						_cube[i][j][k]=-1;
						_old[i][j][k]=-1;  //Erzeugung eines Cubes mit zufälligen Farben (Zahlen)
					}
		}else{
			for(int i=0;i<6;i++)
				for(int j=0;j<3;j++)
					for(int k=0;k<3;k++)
					{
						_cube[i][j][k]=i+1;
						_old[i][j][k]=i+1;  //Erzeugung eines Cubes mit zufälligen Farben (Zahlen)
					}
		}
	}
	~Cube(){};

//--------------- copied from --------------//
//--https://github.com/ekuecks/rubiks-cube--//
//------------- and modificated ------------//

	virtual void printCube();
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

		int returnCubie(int a, int b, int c) {return this->_cube[a][b][c]; } //Gibt Cubie an der Stelle (Seite, Zeile, Spalte) zurück

	void splitQuestion(string s, int n); //Frage am Server spalten in Pos und Farbe
	void generateMastermindAnswer(int *questions, int *reference, int n);

};

// class TempCube : public Cube//soll verebt werden
// {
// private:
// 	int _tmp_old[6][3][3] = {
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } },
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, 
// 		-1, -1 } },
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } },
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } },
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } },
// 	};
// 	int _tmp_cube[6][3][3] = {
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } },
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } },
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } },
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } },
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } },
// 		{ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } } };

// 	string moves = "";
// 	string question = "";
// 	string answer = "";

// public:
// 	TempCube(){}
// 	~TempCube(){};

// 	//--------------------
// 	void printCube(); // erneute deklaration wegen virtual function in class Cube

// };
