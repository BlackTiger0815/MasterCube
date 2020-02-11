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
	int _old[6][3][3];
	int _cube[6][3][3]; //white side

	/* int _old[6][3][3] = {
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
		{ { 5, 5, 5 }, { 5, 5, 5 }, { 5, 5, 5 } } }; //white side */

	string moves = "";


public:
	Cube(int n=1){
		if(n==0){
			for(int i=0;i<6;i++)
				for(int j=0;j<3;j++)
					for(int k=0;k<3;k++)
					{
						_cube[i][j][k]=-1;
						_old[i][j][k]=-1;  //Erzeugung eines Cubes mit leeren Farben (-1)
					}
		}
		else if(n==-1){
			int cnt = 0;
			for(int i=1;i<7;i++)
				for(int j=1;j<4;j++)
					for(int k=1;k<4;k++)
					{
						_cube[i-1][j-1][k-1]=cnt;
						_old[i-1][j-1][k-1]=cnt;  //Erzeugung eines Cubes mit indizes
						cnt++;
					}
		}
		else{
			for(int i=0;i<6;i++)
				for(int j=0;j<3;j++)
					for(int k=0;k<3;k++)
					{
						_cube[i][j][k]=i;
						_old[i][j][k]=i;  //Erzeugung eines Cubes mit zufälligen Farben (Zahlen)
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
	void solveTopCross();
	void findNextTopEdge(int & s, int & p);
	void moveTopEdges();
	void solveTopCorners();
	void findNextTopCorner(int & s, int & p);
	void moveTopCorners();
	void solveMiddleLayer();
	int findBottomMatch(int color);
	void placeMiddleEdge(int color, int edgeSide);
	void middleAlgorithm(int color, int direction);
	void solveBottomLayer();
	void positionBottomCorners();
	int numCorrectCorners();
	void getCorner(int num, int corners[]);
	void swapCorners(int face);
	void positionBottomEdges();
	int numEdgesInCorrectPos();
	void rotateEdges(int face, bool rotClockwise);
	void correctBottomCorners();
	int cornerOrientation();
	int findBestFace(int cornerNum = 5);
	void twoCornerRotate(int face, bool goForward);
	void correctBottomEdges();
	void twoEdgeRotate(int face, bool isNextTo);

//------------------------------------------//
	//Globale drehungen des Würfels im Raum
	void globalRotationR(); //global Right
	void globalRotationL(); //global Left
	void globalRotationD(); //global Down
	void globalRotationU(); //global Up

	void solveCube();

	void switchEdges(int top, bool direction);//destroys corners!!!!
	void moveToTopCross();
	int findTopEdgePos(int side, int pos);
	int findTopEdgeSide(int side, int pos);
	void switchEdgesTopCross();

	void findSwitchableEdges();
	bool isCorrectEdge(int i, int j, int k);;
//------------------------------------------//

// cube questions //
	int array_to_int(int, int, int);
	int int_to_array(int );

	int returnCubie(int a, int b, int c) {return this->_cube[a][b][c]; } //Gibt Cubie an der Stelle (Seite, Zeile, Spalte) zurück
	string feedback;
	string question = ""; // changed here to i can access it easily in questio_cube
	string answer = ""; // same as above
	string splitQuestion(string s, int n); //Frage am Server spalten in Pos und Farbe
	string generateMastermindAnswer(int *questions, int *reference, int n);

	void writeMoves(string newMove){ //Schreibt Moves
		moves = moves + newMove;
	}
	void writeCube(int position, int color);

	int middleIndexOf(int pos);
	int getAdjecentKante(int pos);
	void init_Kanten();
	int getColor(int pos);
	string getMoves(){
		return this->moves;
	};
};
