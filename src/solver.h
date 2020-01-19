#include <iostream>
#include <stdio.h>
#include <list>
#include "cube.h"
#include <string>
using namespace std;




class RubiksCubeSolver
{
private:
	int ManhattanDistance;
	
	
public:
	RubiksCubeSolver(){};
	~RubiksCubeSolver(){};
	
	void calculateManhattanDistance(int x)
	{
		cout << x << endl;
	}

	
};



class MastermindSolver
{
	private:
	// information to save
	int n;
	list <Cube> questions;
	
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

};