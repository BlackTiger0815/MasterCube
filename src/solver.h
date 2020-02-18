#include <iostream>
#include <stdio.h>
#include <list>
#include "cube.h"
#include <string>
using namespace std;


//------------------------------------------//
//---------- Mastermind Solver -------------//
//------------------------------------------//

class MastermindSolver
{
	private:
	// information to save
	int n;
	
	public:
	// functions to us
	list <int> postions_to_ask;
	
	MastermindSolver(){
		cout << "solver is starting" <<endl;
		generate_positions_to_ask();
	};
	~MastermindSolver() {};


void generate_question1();
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

/*char numbers_to_color(int);
int color_to_number(char); look to the cube.h */

//tracking cube
void generate_tracking_cube();
// possition list;
void generate_positions_to_ask();


int* question_numbers;
int* question_colors;


// questions asked list
list <string> CHAOS_questions_asked; //unsortiert
list <string> ORDER_questions_asked; // sortiert

//feedback list
list <string> Feedback_chaos;
void addFeedback(string);
bool correct_question(string);
bool compare_questions(string);

void update_list();




};
int vereinfachen_feedback(string);




//--------------------------------------------//
//---------- Question Class -----------------//
//------------------------------------------//




class Question_container
{
	public:
		string contained_question;
		string current_feedback;
		int* colorfull_array;
		int* positional_array;
		float probability;


Question_container(string contained_question, string current_feedback){

	// from question get color and number
		int length = contained_question.size();
		int size_of_question = length/3;
		int positional_array[size_of_question];
		int colorfull_array[size_of_question];

		for(int i = 0; i < size_of_question; i++)
		{
				positional_array[i] = 10 * ((contained_question[i*3]-48));
				positional_array[i] += 1 * ((contained_question[i*3+1])-48) ;
				colorfull_array[i] = (contained_question[i*3+2])-48;
				
		}
		probability = double(vereinfachen_feedback(current_feedback))/size_of_question;
	};
	~Question_container() {};






};