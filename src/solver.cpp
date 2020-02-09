#include "solver.h" 


//------------------------------------------//
//---------- Mastermind Solver -------------//
//------------------------------------------//

void convert_to_base_6(int);
void MastermindSolver::generate_question()
{
	//	cout << n <<endl;
	
	string question;
	if(n < 7)
	{
		//cout << "n is" << n <<endl;
		int alpha = 0;
	
	// check list for what to ask; this list containts what we want to know. /possition wise
	
	// asume we want to ask middles ->  5+9*i
	for (int i = 0;i < n; i++)
	{
		alpha = 5+9*i; //alpha is the position we want to ask
	
		question.append(to_string(alpha/10));
		question.append(to_string(alpha%10));		
		question.append("r");
		//cout <<question<<endl;
	}
	// now we got possitions
	// next step which color
	int pos_guesses = how_much_can_i_ask();
	list <int*> start;
	
	
	for(int i = 0;i < pos_guesses ; i++)
	{
		int number = i;
		int e = 0;
		// converting
		int array_question[n];
		do{
			int to_save = number%6;
			//cout << " I want to save" << to_save << " in all_data" << e <<endl;
			array_question[e] = to_save;
			e++;
		}while( number/=6);
		start.push_back(array_question);
	}
	// start cointains all possible questions now //

  /* for (std::list<int*>::iterator it=start.begin(); it != start.end(); ++it)
  {
	  for( int i = 0; i < n; i++)
	  {
		cout << ' ' << (*it)[0];
	  }
  } */
 // simple question is 1 element.

//cout <<(*start.begin())[0];
//cout <<(*start.begin())[1];
//cout <<(*start.begin())[2];

for (int i = 0; i < n*3; i++)
{
//from number to color
char color ='g';

question[2+i*3] = color;
	}
	cout << question <<endl;
	}
}






void MastermindSolver::testing()
{
	
	int pos_guesses = how_much_can_i_ask();
	
	/*for(int i = 0; i < 53; i++)
	{
	pseudo_n = i;
	set_n(pseudo_n); 
	int pos_guesses = how_much_can_i_ask();
	list <short int> start (pos_guesses*n);
	cout << n << endl;
	}
	*/
	
	
	int all_data[pos_guesses][n] ={};
	// poss to base six - possibilites
	
	
	for(int i = 0;i < pos_guesses ; i++)
	{
		int number = i;
		int e = 0;
		// converting
			
		do{
			int to_save = number%6;
			//cout << " I want to save" << to_save << " in all_data" << e <<endl;
			all_data[i][e] = to_save;
			e++;
		}while( number/=6);
	}

	Cube a;
	a.generateMastermindAnswer(all_data[1],all_data[pos_guesses/2],n);
	cout << a.feedback << endl;
	string answer  = a.feedback;
	
	int tracker = 0;
	for(int e = 0; e < pos_guesses; e++)
	{
		
		a.generateMastermindAnswer(all_data[1],all_data[e],n);
		string other_answer = a.feedback;
		//cout <<" " <<answer << other_answer <<endl;
		if ( other_answer == answer)
		{
			cout << "this one cold work" <<endl;
			tracker++;
			
		}
	}
	cout << "so many are left" << tracker <<endl;
		
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

void MastermindSolver::set_n(int a)
        {
            n = a;
        }








