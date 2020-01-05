#include "solver.h"

int convert_to_base_6(int);

void MastermindSolver::testing()
{
	int pseudo_n = 6;
	set_n(4);
	
	cout << how_much_can_i_ask() << endl;
	
	what_to_ask();
	
	all_possible();
	
	
	
}

void MastermindSolver::what_to_ask()
{
	if (n > 10)
	{
	//generic_evolution_solver();
	}
	else
	{
		how_much_can_i_ask();
		//which_question_to_choose();
		//what_does_the_answer_mean();
	}
	
}



int MastermindSolver::how_much_can_i_ask()
{
	// a: alot
	int alot = 1;
	for( int i = 0; i < n; i++)
	{
		alot *= 6;
	}
	return alot;
}

string MastermindSolver::all_possible()
{
	int alot = how_much_can_i_ask() ;
	string quite_alot[alot];
	int actually = 0;
	
	for(int i = 0; i <  100; i++) //base 6 converter
	{
	actually = convert_to_base_6(i);	
	}
	
	return 0;
	
	
}

int convert_to_base_6(int i)
{
	int converted = i;
	int last_place = i%6;
	for (int e = 0;e<i; e*=6)
	{
		
		converted = i/6;
		cout << converted << last_place <<endl;
		
	}
	return converted;
	
	
}


