#include "solver.h"


//------------------------------------------//
//---------- Mastermind Solver -------------//
//------------------------------------------//
// Aufbau:
//0. number to color
//1 tracking cube erstellen
//2. liste für was fragen wir ab
//3. genereieren einer fragen
//4. feeback hinzufügen zu der feedback liste
//5. ist eine frage so richtig?


//0. number to color


/* char MastermindSolver::numbers_to_color(int number)
{
	char color[] = "wgrboy"; //white green red blue orange yellow
	return color[number];	
}

int MastermindSolver::color_to_number(char color)
{
	switch (color)
	{
	case 'w':
		return 0;
		
	case 'g':
		return 1;
		
	case 'r':
		return 2;
		
	case 'b':
		return 3;
		
	case 'o':
		return 4;
		
	case 'y':
		return 5;
		
	default:
		////////cout<< "you took a wrong turn" <<endl;
		return -1;
	}
}        diese funktionen wurden in cube.h verschoben   */

//1 tracking cube erstellen
//Copy cube(-1) to tracking...


//2 liste der positionen
void MastermindSolver::generate_positions_to_ask()
{
	Cube Beagle(-1); //generates tracking cube
	//Edges //with push_fornt the last one should be first one inserted
	for(int i=0; i<6; i++){
		
		postions_to_ask.push_front(Beagle._cube[i][0][0]);
		postions_to_ask.push_front(Beagle._cube[i][2][0]);	
		postions_to_ask.push_front(Beagle._cube[i][0][2]);	
		postions_to_ask.push_front(Beagle._cube[i][2][2]);	
		}
	//Sides
	for(int i=0; i<6; i++){
		postions_to_ask.push_front(Beagle._cube[i][0][1]);
		postions_to_ask.push_front(Beagle._cube[i][1][0]);	
		postions_to_ask.push_front(Beagle._cube[i][2][1]);	
		postions_to_ask.push_front(Beagle._cube[i][1][2]);	
		}
	//Middles
	for(int i=0; i<6; i++){
		int j = 1;
		int k = 1;
		postions_to_ask.push_front(Beagle._cube[i][j][k]);				
		}
		
		/* 
		Beagle.printCube();
		std::////////cout<< "postions_to_ask contains:";
  for (std::list<int>::iterator it=postions_to_ask.begin(); it!=postions_to_ask.end(); ++it)
    std::////////cout<< ' ' << *it; 
 */
		
}

/*
void _print_question(string a)
{
	for( int i = 0; i< a.size();i++)
	{
		////cout<< a[i];
		if ( i+1%3)
			////cout<<endl;


	}


}
*/


//3 fragen erstellen
void MastermindSolver::generate_question()
{
	
	
	
	////////cout<< n << endl;
	string question;
	int n_counter = 0;
	// 1 get n possitions
	// 2 get random colors
	// 3 fill string with those
	// 4 posssible correct string if not differnece.
	
	//1 //
	// generate_positions_to_ask
	// get first number
	// if lower than 10 add 0 then the number
	// get current number
		for (std::list<int>::iterator it=postions_to_ask.begin(); n_counter < n;n_counter++, ++it)
		{
			
			// NUMMER FÜR FRAGE ANFAG
			
			//it* == number we need
			//////////cout<< *it<<endl;
			if( *it< 10)
			{
				question.append("0");
				question.append(to_string(*it));
			}
			else
			{
				question.append(to_string(*it));
			}
			
			// NUMMER FÜR FRAGE ENDE
			int get_color = rand() % 6;
			question.append(to_string(get_color));
			
			
			char color = numbers_to_color(get_color);
			
			while(correct_question(question)) //funktion gibt true wenn die frage nicht stimmt
			{
				//cout << "die Frage ist irgendwie falsch"  <<endl;
				get_color = rand() % 6;
				question.pop_back();
				question.append(to_string(get_color));      
			}
			
			//FARBE FÜR FRAGE ENDE

		
		}
		
		/*
		if (CHAOS_questions_asked.empty() == false)
		{
		string last_question = *CHAOS_questions_asked.begin();
		questions_same  = question.compare(last_question);
		}
		*/
  
		//////////cout<< question;
		// save question into unsorted question list.
		CHAOS_questions_asked.push_front(question);
		//////////cout<< *(CHAOS_questions_asked.begin());
		// save question into sorted question list. TO DO 
		ORDER_questions_asked.push_front(question);
		
	
	}
	
	
	// feedback hinzufügen
	void MastermindSolver::addFeedback (string valuable_feedback)
	{
		Feedback_chaos.push_front(valuable_feedback);
		//its chaos because its not tracked
	}
	
	
	//5 ist die frage richtig
	// tod - wenn kante dann selbe kante nincht selbe farbe
	// und wenn 2 kanten nicht zwi kanten dieselbe farben
	// selbe für seiten
	// und frage darf nicht den farbencounter überschreiten

bool MastermindSolver::correct_question(string a_question)
{

	// wenn sie gleich ist wie eine vorherige frage
	if((compare_questions(a_question)))
	{
		//cout<< "hier wird geschaut ob eine frage genug unterschied zu einer vorherigen frage hat";
		//cout<< " das ergebnis war " << to_string(compare_questions(a_question)) <<endl;
		return true;
	}
	
	int length = a_question.size();
	int size_of_question = length/3;
	int number[size_of_question];
	int guess_color[size_of_question];

	for(int i = 0; i < size_of_question; i++)
	{
			number[i] = 10 * ((a_question[i*3]-48));
			number[i] += 1 * ((a_question[i*3+1])-48) ;
			guess_color[i] = (a_question[i*3+2])-48;
			
	}

	// wenn zwei mitten die selbe farbe haben nein	
	if(isMitte(number[size_of_question-1]))
	{	
		//cout<< number[size_of_question-1] << "Ist eine Mitte" <<endl;
		for( int i = 0; i < size_of_question -1 ; i++)
		{
			//cout<< number[i] << "Ist eine Mitte" << isMitte(number[i])<<endl;

			if(isMitte(number[i]) && guess_color[i] == guess_color[size_of_question-1])
			{
				//cout<< number[i] << " und "<< number[size_of_question-1] << "sind mitten" <<endl;
				//cout<< "leider auch dieselbe farbe" << guess_color[i]  << guess_color[size_of_question-1] <<endl;
				return true;
			}
			}
	}	

	
	// wenn eine ecke die selben farben hat nein
	// und ecke darf auch nicht gleich sein wie eine andere ecke - simple knut

	/*
	if(isEcke(number[size_of_question-1]))
	{	

		int a,b,c = number[size_of_question-1];
		//cout<< c << "ist eine ecke" <<endl;
		vector<pair<int,int>> adjEcken;
		adjEcken=getAdjecentEcken(c);

		a=adjEcken[0].first;
		b=adjEcken[0].second;
		//cout<< "Speicherzugriffsefhler hier" <<endl;
		// dazugehörige ecke finden
		//cout<< "die Ecke" << c << "hat die dazugehörigen ecken" << a << "und" << b << "jetzt muss geschaut werden ob diese auch in der liste sind." << endl;
	}
	*/	


// wenn eine seiete dieselbe farbe hat nein

// wenn eine farbe schon zu oft vorkommt nein


	return false;
}


bool  MastermindSolver::compare_questions(string new_question)
{
	int simple_feedback = 0;
	int abc = 0;
	list<string>::iterator old_question =ORDER_questions_asked.begin();
	list<string>::iterator old_feedback = Feedback_chaos.begin();
	while(!(Feedback_chaos.empty()))
	{

		//cout << "Caugt in a loop and your to blame" <<endl;
		simple_feedback = vereinfachen_feedback((*old_feedback));

		// from question get color and number
		int length = new_question.size();
		int size_of_question = length/3;
		int number[size_of_question];
		int guess_color[size_of_question];

		for(int i = 0; i < size_of_question; i++)
		{
				number[i] = 10 * ((new_question[i*3]-48));
				number[i] += 1 * ((new_question[i*3+1])-48) ;
				guess_color[i] = (new_question[i*3+2])-48;
				
		}
		// same for old_question
		int length_old = (*old_question).size();
		int size_of_question_old = length_old/3;
		int number_old[size_of_question_old];
		int guess_color_old[size_of_question_old];

		for(int i = 0; i < size_of_question_old; i++)
		{
				number_old[i] = 10 * (((*old_question)[i*3]-48));
				number_old[i] += 1 * (((*old_question)[i*3+1])-48) ;
				guess_color_old[i] = ((*old_question)[i*3+2])-48;
				////cout<<guess_color_old[i] <<endl;
				////cout<< "unsere alten farben" <<endl;
				
		}

		int counter_of_same_nr_and_feedback = 0;
		for(int i = 0; i < size_of_question; i++)

		{
			for(int e = 0; e < size_of_question_old; e++)
			{
				
				// new_questions und old question nummern die gleich sind herraussuchen + deren farben
				if(number[i]==number_old[e] && guess_color[i] == guess_color_old[e])
				{
						//cout<< "angeblich gleiche stelle auch" << number[i] <<number_old[e] << "angeblich gleiche Farben " << guess_color[i] << guess_color_old[e] <<endl;
						counter_of_same_nr_and_feedback++; // für jede Zahl und Farbe die Gleich haben wird dieser Counter erhöht
				} 
			}
			if(counter_of_same_nr_and_feedback > simple_feedback)
			{
				//cout<< simple_feedback <<"simple feedback"<<endl;
				//cout<< counter_of_same_nr_and_feedback <<"counter_of_same_nr_and_feedback"<<endl;
				cout << new_question << "war zu gleich mit " << *old_question << "simple feedback:" << simple_feedback << "und " << counter_of_same_nr_and_feedback <<"größer ist" <<endl; 
				return true;
			}

		}


		if(counter_of_same_nr_and_feedback > simple_feedback)
		{
			//cout<< simple_feedback <<"simple feedback"<<endl;
			//cout<< counter_of_same_nr_and_feedback <<"counter_of_same_nr_and_feedback"<<endl;
			cout << new_question << "war zu gleich mit " << *old_question <<endl;
			return true;
		}

		//cout << "you give love a bad name" <<endl;

	old_question++;
	old_feedback++;

	if(old_feedback == Feedback_chaos.end())
		{
			//cout << "Escaping the clutches" <<endl;
			break;
		}

	}

	//cout<< "We return false meaining the question is sufficenitely different from last questions" <<endl;
	return false;
}

int MastermindSolver::vereinfachen_feedback(string one_feedback)
{
	int wie_gut = 0;
	//cout << "Feedback to be analyesd" << one_feedback <<endl;

	//cout<<"Feedback wird vereinfacht" <<endl;

			  for ( std::string::iterator it=one_feedback.begin(); it!=one_feedback.end(); ++it)
			  {
					int current_grading = int(*it)-48;
					////cout<< current_grading<<endl;
					if (current_grading!= 2)
						wie_gut++;
			  }
			  //cout << "we got " << wie_gut <<endl;
			  return wie_gut;
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
	////////cout<< n << endl;
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
			//////////cout<< " I want to save" << to_save << " in all_data" << e <<endl;
			all_data[i][e] = to_save;
			e++;
		}while( number/=6);
	}

	Cube a;
	a.generateMastermindAnswer(all_data[1],all_data[pos_guesses/2],n);
	////////cout<< a.feedback << endl;
	string answer  = a.feedback;
	
	int tracker = 0;
	for(int e = 0; e < pos_guesses; e++)
	{
		
		a.generateMastermindAnswer(all_data[1],all_data[e],n);
		string other_answer = a.feedback;
		//////////cout<<" " <<answer << other_answer <<endl;
		if ( other_answer == answer)
		{
			////////cout<< "this one cold work" <<endl;
			tracker++;
			
		}
	}
	////////cout<< "so many are left" << tracker <<endl;
		
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
			//n = 6;
 }






