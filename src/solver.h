#include <iostream>
#include <stdio.h>
//#include "cube.h"
using namespace std;

//------------------------------------------//
//---------- Mastermind Solver -------------//
//------------------------------------------//

class MastermindSolver
{
	private:
	// information to save
	int n;
	string* questions;
	string* answers;
	string* possible_corret;



	public:
	// functions to use
	MastermindSolver(){
		cout << "solver is starting" << endl;
	};
	~MastermindSolver() {};

	void set_n(int a)
        {
            n = a;
        }

	//testing
	// all funcions are testet here (pls)
	void testing();

	// 1 //

	void what_to_ask(); //switch n

	// 2 //

	int how_much_can_i_ask();



	// 3 //

	string which_question_to_choose();  // 2 asking itself with generateMastermindAnswer

	// 4 //

	string what_does_the_answer_mean(); //possible_corret -  answer //eliminate possibilities

	// 5 // start at 1

	// 6 //

	string generic_evolution_solver();

	// 7 //
	// knut mastermind for low name
	string all_possible();
	// 2 to 4

	// 8 //

	// tabu search

	// from colors generate puzzle 24 parts

};


//------------------------------------------//
//------------- Cube Solver ----------------//
//------------------------------------------//

class RubiksCubeSolver
{
private:
	float _ManhattanDistance;
	int _unsolvedCubiesI;
	float _unsolvedCubiesF;


public:
	RubiksCubeSolver(){};
	~RubiksCubeSolver(){};

	//Heuristiken
	int calculateManhattanDistance(Cube c, int x, int y, int z); //Berechnen der Manhatten Distanz eines Cubies by Isabella
	float max_CornerEdge_sum(Cube c); //Berechnen der Manhatten Distanz des Cubes by Isabella
	void writeManhattenDistance(float dist) {_ManhattanDistance = dist; };

	float calculateNumUnsolvedCubies(Cube c, bool admissible); //Berechnen der Anzahl an -cubies am falschen Platz by Isabella
	void writeUnsolvedCubies(int num) {_unsolvedCubiesI = num; };
	void writeUnsolvedCubies(float num) {_unsolvedCubiesF = num; };

	//Metoden des IDA*
	double IDAstarAlgorithm(Cube scrambledCube, int cost, int lastMove); //by Isabella
	Cube performMove(Cube c, int i); //Cube drehen
};
