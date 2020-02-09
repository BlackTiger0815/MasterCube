#include <iostream>
#include <stdio.h>
#include <list>
#include "cube.h"
#include <string>
using namespace std;

// general Solver Functions //
char numbers_to_color(int);


//------------------------------------------//
//------------- Cube Solver ----------------//
//------------------------------------------//

class RubiksCubeSolver
{
private:
	float _ManhattanDistance;
	int _unsolvedCubiesI;
	float _unsolvedCubiesF;
	Cube a;


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

//------------------------------------------//
//---------- Mastermind Solver -------------//
//------------------------------------------//

class MastermindSolver
{
	private:
	// information to save
	int n;
	//list questions;
	Cube tracking_cube;
	public:
	// functions to use
	MastermindSolver(){
		cout << "solver is starting" << endl;
	};
	~MastermindSolver() {};

void generate_question();
void set_n(int);
void testing();
void what_to_ask(); // base on n switches solver approach
int how_much_can_i_ask(); //for low n generates possible questions / answers
string all_possible(int guesses);
void convert_to_base_6(int i);
string which_question_to_choose();  // 2 asking itself with generateMastermindAnswer
string what_does_the_answer_mean(); //possible_corret -  answer //eliminate possibilities
string generic_evolution_solver();
string all_possible();


// tracking - cube
void generate_tracking();


};
