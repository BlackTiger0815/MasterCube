#include "solver.h"


//------------------------------------------//
//---------- Mastermind Solver -------------//
//------------------------------------------//
// Aufbau:
//1 tracking cube erstellen
//2. liste für was fragen wir ab
//3. genereieren einer fragen
//4. feeback hinzufügen zu der feedback liste
//5. ist eine frage so richtig?
//6. best_guess(single)
//7. update_list()


//2 liste der positionen
void MastermindSolver::generate_positions_to_ask()
{
	Cube Beagle(-1); //generates tracking cube
	init_Ecken();
	init_Kanten();
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
		
	
		
}

/*
void _print_question(string a)
{
	for( int i = 0; i< a.size();i++)
	{
		////////cout<< a[i];
		if ( i+1%3)
			////////cout<<endl;


	}


}
*/

//3 fragen erstellen  //copy 
void MastermindSolver::generate_question()
{

	/// PREPARATIONS
	int positions_array[n];
	string question;
	int n_counter = 0;
	n_counter = 0;
	int counter_of_loops = 0;


	for (std::list<int>::iterator it=postions_to_ask.begin(); n_counter < n;n_counter++,++it)
	{
		positions_array[n_counter] = *it;
			//////cout << *it;
			////cout << positions_array[n_counter];
		string pseudo_question ="";

		//Apending Position
		if( *it< 10)
			{
				pseudo_question.append("0");
				pseudo_question.append(to_string(*it));
			}
			else
			{
				pseudo_question.append(to_string(*it));
			}

		/*

		//Apending Color and trying them
		for(int i = 0; i < 6; i++)
		{
			pseudo_question.append(to_string(i));
			if(correct_question(question))
				//cout << "question: " << pseudo_question << "does not work" <<endl;
			else
			{
				//cout << "question: " << pseudo_question << "does work" <<endl;
			}
			pseudo_question.pop_back();

		}
		*/		
	}
	
	
	
	////////////cout<< n << endl;
	n_counter = 0;
	for (std::list<int>::iterator it=postions_to_ask.begin(); n_counter < n;n_counter++)
	{
			
		if(it==postions_to_ask.begin() && counter_of_loops>7)
			{
				//cout <<"Crahses at the top" <<endl;
				it=postions_to_ask.begin();
				counter_of_loops = 0;
				n_counter = 0;
			}


			int get_color = 7;
			
			

			// NUMMER FÜR FRAGE ANFAG
			//it* == number we need
			//////////////cout<< *it<<endl;
			if( *it< 10)
			{
				question.append("0");
				question.append(to_string(*it));
			}
			else
			{
				question.append(to_string(*it));
			}
			


			//// START FROM BEST GUESS ///
			get_color = 0; //"best guess"
			float best_wh = 0; // best wh
			if(!Feedback_chaos.empty()) // nur möglich wenn das feedback nicht leer ist
			{
				get_color = 0; //"best guess"
				
				////cout << "wir suchen die position " << positions_array[n_counter] << "in dem Feedback" <<endl;
				list<string>::iterator old_question =ORDER_questions_asked.begin();
				list<string>::iterator old_feedback = Feedback_chaos.begin();
				do{
					////cout << *old_question <<endl;
					////cout << *old_feedback <<endl; 
					////cout << "alte frage + feedback " <<endl;
					float easy_feedback = (float)vereinfachen_feedback(*old_feedback);

					//convert question
					int length = (*old_question).size();
					int size_of_question = length/3;
					int number[size_of_question];
					int guess_color[size_of_question];

					for(int i = 0; i < size_of_question; i++)
					{
							number[i] = 10 * (((*old_question)[i*3]-48));
							number[i] += 1 * (((*old_question)[i*3+1])-48) ;
							guess_color[i] = ((*old_question)[i*3+2])-48;

							if(number[i] == positions_array[n_counter])
							{
								////cout << "zu dieser Position wollen wir die Beste möglichkeit" <<endl;
								////cout << "im moment ist das feedback " << easy_feedback <<endl;
								////cout << positions_array[n_counter] << "kommt in der Frage " << *old_question << "vor" <<endl;


								// jetzt müssen wir auch schauen ob das der Beste guess ist
								if(best_wh <= easy_feedback/size_of_question )
								{
									//cout << best_wh << "best wh vs wh from antother queston" << easy_feedback/size_of_question <<endl;
									// wenn zwei wh gleich sind sind die Fragen trotzdem unterschiedlich
									if(best_wh==easy_feedback/size_of_question && rand()% 2)
									{
										get_color = guess_color[i];

									}
									else
									{
										get_color = guess_color[i];
									}


									//////cout << easy_feedback/size_of_question << "ist größer als " << best_wh <<endl;
									best_wh = easy_feedback/size_of_question;
									// und die "beste farbe" ist demnach
									//get_color = guess_color[i];
									// jetzt müssen wir nur noch entscheiden ob wir wirklich die farbe hernemen wollen
									//////cout << "die farbe war" << get_color <<endl;
								}
							}
							
					}


					//////cout << "die farbe ist geblieben" << get_color <<endl;
					old_question++;
					old_feedback++;
				}while(old_question!=ORDER_questions_asked.end());
			}

			if(best_wh >= (((rand() % 100) + 1) / 100.0)) // means if best_wh = 1 , we always choose it
			{
				//get color stays the same
				question.append(to_string(get_color)); // ich könnte das jetzt ändern und diese zeile nach dem if und else schreiben
				// aber so hat das if was zu tun.
				cout << "die beste Frage wurde gewählt" <<endl;
			}
			else
			{
				//cout << "die beste Frage wurde nicht gewählt" <<endl;
				//cout << "obwohl beste wh " << best_wh <<" ist" <<endl;
				int not_this_one = get_color;
				get_color = rand() % 6; // wir sollten eine zalh raten die anders ist als get color schon ist
				while(((get_color == not_this_one)))
				{
					get_color = rand() % 6;
				}
				question.append(to_string(get_color));

				// ONLY CHECK IF CORRECT IF WE ARE NOT USING THE PREDEFINED QUESTION
				while(correct_question(question)) //funktion gibt true wenn die frage nicht stimmt
				{
				//cout << "die Frage ist irgendwie falsch"  <<endl;
				cout << question << "und zwar an der " << n_counter << "-ten abfrage" <<endl;
				if(get_color ==5)
					get_color = 0;
				else
				{
					// so werden alle Farben durchprobiert und nicht pseudorandom
					get_color++;
				}
				question.pop_back();
				question.append(to_string(get_color));
				if((counter_of_loops++ %7) == 0)
				{
					// doing it once to clear this postion
					question.pop_back(); // should remove the last number
					question.pop_back();
					question.pop_back(); // and the color
					n_counter--;
					it--;

					// and as often as needed to go back to reedeem mistakes
					for(int i = 0;i < counter_of_loops/7; i++)
					{
						question.pop_back(); // should remove the last number
						question.pop_back();
						question.pop_back(); // and the color
						n_counter--;
						it--;
						if(question.empty())
							break; //BREAKING THE FOR LOOP

					}
					break; //BREAKING THE WHILE LOOP
				}
			}
			}
			////cout << "Wir haben uns für die Farbe " << get_color <<"entschieden" <<endl;

			// NUMMER FÜR FRAGE ENDE
			
			

			//char color = numbers_to_color(get_color); LATER
			
			++it;


			
			//FARBE FÜR FRAGE ENDE

		
		}
		////cout << "FRAGE GEFUNDEN" << question <<endl;
		
		/*
		if (CHAOS_questions_asked.empty() == false)
		{
		string last_question = *CHAOS_questions_asked.begin();
		questions_same  = question.compare(last_question);
		}
		*/
  
		//////////////cout<< question;
		// save question into unsorted question list.
		CHAOS_questions_asked.push_front(question);
		//////////////cout<< *(CHAOS_questions_asked.begin());
		// save question into sorted question list. TO DO 
		ORDER_questions_asked.push_front(question);
		
	
}


//3 fragen erstellen

/*
void MastermindSolver::generate_question()
{
	
	
	
	////////////cout<< n << endl;
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

	//prints out the positions we want to get
	int positions_array[n];
	for (std::list<int>::iterator it=postions_to_ask.begin(); n_counter < n;n_counter++,++it)
	{
		positions_array[n_counter] = *it;
			//////cout << *it;
			////cout << positions_array[n_counter];
		string pseudo_question ="";

		//Apending Position
		if( *it< 10)
			{
				pseudo_question.append("0");
				pseudo_question.append(to_string(*it));
			}
			else
			{
				pseudo_question.append(to_string(*it));
			}

		/*

		//Apending Color and trying them
		for(int i = 0; i < 6; i++)
		{
			pseudo_question.append(to_string(i));
			if(correct_question(question))
				//cout << "question: " << pseudo_question << "does not work" <<endl;
			else
			{
				//cout << "question: " << pseudo_question << "does work" <<endl;
			}
			pseudo_question.pop_back();

		}


		
	}




	n_counter = 0;
	int counter_of_loops = 0;
	for (std::list<int>::iterator it=postions_to_ask.begin(); n_counter < n;n_counter++)
	{
			

			int get_color = 7;
			// nach reset
			if(counter_of_loops >= 6 )
			{
				it=postions_to_ask.begin();
				counter_of_loops = 0;
				n_counter = 0;
			}
			

			// NUMMER FÜR FRAGE ANFAG
			//it* == number we need
			//////////////cout<< *it<<endl;
			if( *it< 10)
			{
				question.append("0");
				question.append(to_string(*it));
			}
			else
			{
				question.append(to_string(*it));
			}
			


			//// START FROM BEST GUESS ///
			get_color = 0; //"best guess"
			float best_wh = 0; // best wh
			if(!Feedback_chaos.empty()) // nur möglich wenn das feedback nicht leer ist
			{
				get_color = 0; //"best guess"
				float best_wh = 0; // best wh
				////cout << "wir suchen die position " << positions_array[n_counter] << "in dem Feedback" <<endl;
				list<string>::iterator old_question =ORDER_questions_asked.begin();
				list<string>::iterator old_feedback = Feedback_chaos.begin();
				do{
					////cout << *old_question <<endl;
					////cout << *old_feedback <<endl; 
					////cout << "alte frage + feedback " <<endl;
					float easy_feedback = (float)vereinfachen_feedback(*old_feedback);

					//convert question
					int length = (*old_question).size();
					int size_of_question = length/3;
					int number[size_of_question];
					int guess_color[size_of_question];

					for(int i = 0; i < size_of_question; i++)
					{
							number[i] = 10 * (((*old_question)[i*3]-48));
							number[i] += 1 * (((*old_question)[i*3+1])-48) ;
							guess_color[i] = ((*old_question)[i*3+2])-48;

							if(number[i] == positions_array[n_counter])
							{
								////cout << "zu dieser Position wollen wir die Beste möglichkeit" <<endl;
								////cout << "im moment ist das feedback " << easy_feedback <<endl;
								////cout << positions_array[n_counter] << "kommt in der Frage " << *old_question << "vor" <<endl;


								// jetzt müssen wir auch schauen ob das der Beste guess ist
								if(best_wh < easy_feedback/size_of_question)
								{
									//////cout << easy_feedback/size_of_question << "ist größer als " << best_wh <<endl;
									best_wh = easy_feedback/size_of_question;
									// und die "beste farbe" ist demnach
									get_color = guess_color[i];
									// jetzt müssen wir nur noch entscheiden ob wir wirklich die farbe hernemen wollen
									//////cout << "die farbe war" << get_color <<endl;
								}
							}
							
					}


					//////cout << "die farbe ist geblieben" << get_color <<endl;
					old_question++;
					old_feedback++;
				}while(old_question!=ORDER_questions_asked.end());
			}

			if(best_wh >= (rand() % 101 / 100.0)) // means if best_wh = 1 , we always choose it
			{
				//get color stays the same
				question.append(to_string(get_color)); // ich könnte das jetzt ändern und diese zeile nach dem if und else schreiben
				// aber so hat das if was zu tun.
				////cout << "die beste Frage wurde gewählt" <<endl;
			}
			else
			{
				int not_this_one = get_color;
				get_color = rand() % 6; // wir sollten eine zalh raten die anders ist als get color schon ist
				while(((get_color == not_this_one)))
				{
					get_color = rand() % 6;
				}
				question.append(to_string(get_color));
			}
			////cout << "Wir haben uns für die Farbe " << get_color <<"entschieden" <<endl;

			// NUMMER FÜR FRAGE ENDE
			
			

			char color = numbers_to_color(get_color);

			counter_of_loops = 0;
			while(correct_question(question)) //funktion gibt true wenn die frage nicht stimmt
			{
				////cout << "die Frage ist irgendwie falsch"  <<endl;
				////cout << question << "und zwar an der " << n_counter << "-ten abfrage" <<endl;
				if(get_color ==5)
					get_color = 0;
				else
				{
					// so werden alle Farben durchprobiert und nicht pseudorandom
					get_color++;
				}
				question.pop_back();
				question.append(to_string(get_color));
				if(counter_of_loops++ > 7)
				{
					//im moment einfach von vorne anfangen
					 //problem wir gehen ein weiter durch den for loop
					question.clear();
					////cout << question << "question was cleard?" <<endl;
					n_counter = 0;
					// not the right way to do it

					break;
				}

				   
			}
			++it;


			
			//FARBE FÜR FRAGE ENDE

		
		}
		////cout << "FRAGE GEFUNDEN" << question <<endl;
		
		/*
		if (CHAOS_questions_asked.empty() == false)
		{
		string last_question = *CHAOS_questions_asked.begin();
		questions_same  = question.compare(last_question);
		}
		
  
		//////////////cout<< question;
		// save question into unsorted question list.
		CHAOS_questions_asked.push_front(question);
		//////////////cout<< *(CHAOS_questions_asked.begin());
		// save question into sorted question list. TO DO 
		ORDER_questions_asked.push_front(question);
		
	
}


*/

//3 fragen erstellen OVER
	
	
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
		//////cout<< number[size_of_question-1] << "Ist eine Mitte" <<endl;
		for( int i = 0; i < size_of_question -1 ; i++)
		{
			//////cout<< number[i] << "Ist eine Mitte" << isMitte(number[i])<<endl;

			if(isMitte(number[i]) && guess_color[i] == guess_color[size_of_question-1])
			{
				////cout<< number[i] << " und "<< number[size_of_question-1] << "sind mitten" <<endl;
				////cout<< "leider auch dieselbe farbe" << guess_color[i]  << guess_color[size_of_question-1] <<endl;
				//cout << "mitten sind falsch" <<endl;
				return true;
			}
			}
	}	

	
	// wenn eine ecke die selben farben hat nein
	// und ecke darf auch nicht gleich sein wie eine andere ecke - simple knut

	
	if(isEcke(number[size_of_question-1]))
	{	
		////cout << number[size_of_question-1] << "ist eine Ecke" <<endl;
		// mit dieser Ecke suchen wir nun die benachbarten ecken

		int a,b,c = number[size_of_question-1];
		//////cout<< c << "ist eine ecke" <<endl;
		vector<pair<int,int>> adjEcken;
		//adjEcken=getAdjecentEcken(c);

		//a=adjEcken[0].first;
		//b=adjEcken[0].second;
		//////cout<< "Speicherzugriffsefhler hier" <<endl;
		// dazugehörige ecke finden
		//////cout<< "die Ecke" << c << "hat die dazugehörigen ecken" << a << "und" << b << "jetzt muss geschaut werden ob diese auch in der liste sind." << endl;
	}
		


// wenn eine seiete dieselbe farbe hat nein


	if(isKante(number[size_of_question-1]))
	{
		////cout << number[size_of_question-1] << "ist eine Kante" <<endl;
		// mit dieser Kante suchen wir nun die benachbarten Kante
		int kante_1 = number[size_of_question-1];
		int kante_2 = getAdjecentKante(kante_1);
		////cout << kante_2 << "gehört zu "<< kante_1 <<endl;

		// jetzt schauen ob kante_2 überhaubt in der Frage ist


		multimap <int,int> andere_kanten; 		
		for(int i = 0; i< size_of_question -1 ; i++)
		{


			if(number[i] == kante_2)
			{
				////cout << "sowohl " << kante_1 << "&" << kante_2 << "sind in der Frage" << a_question <<endl;
				if(guess_color[i] == guess_color[size_of_question-1])
				{
					////cout << "sowohl " << kante_1 << "&" << kante_2 << "leider auch die gleiche Farbe" << guess_color[i]  <<"& " << guess_color[size_of_question-1] <<endl;
					//cout << "kanten sind falsch" <<endl;
					return true;
				}
			}
			else
			{
				////cout << "looking" <<endl;
				//if(isKante(number[i]))
					
			}
			}
		}

	// wenn eine farbe schon zu oft vorkommt nein
	for(int current_color = 0; current_color < 6; current_color++)
	{
		int color_counter = 0;
		for(int i = 0;i < size_of_question;i++)
			{
				if(guess_color[i]== current_color)
				{
					color_counter++;
					if(color_counter>9)
					{
						////cout << "zu viele gleiche farben in " << a_question <<"und zwar" << color_counter << "von " << current_color <<endl;
						//cout << "zu viele Farben ist falsch" <<endl;
						return true;
					}
				}

			}

	}
			




// wenn sie gleich ist wie eine vorherige frage
// schauen ob es ohne das besser geht

	
	if((compare_questions(a_question)))
	{
		//////cout<< "hier wird geschaut ob eine frage genug unterschied zu einer vorherigen frage hat";
		//////cout<< " das ergebnis war " << to_string(compare_questions(a_question)) <<endl;
		//cout << "die Frage war zu gleich mit einer vorherigen" <<endl;
		return true;
	}
	


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

		//////cout << "Caugt in a loop and your to blame" <<endl;
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
				////////cout<<guess_color_old[i] <<endl;
				////////cout<< "unsere alten farben" <<endl;
				
		}

		int counter_of_same_nr_and_feedback = 0;
		for(int i = 0; i < size_of_question; i++)

		{
			for(int e = 0; e < size_of_question_old; e++)
			{
				
				// new_questions und old question nummern die gleich sind herraussuchen + deren farben
				if(number[i]==number_old[e] && guess_color[i] == guess_color_old[e])
				{
						//////cout<< "angeblich gleiche stelle auch" << number[i] <<number_old[e] << "angeblich gleiche Farben " << guess_color[i] << guess_color_old[e] <<endl;
						counter_of_same_nr_and_feedback++; // für jede Zahl und Farbe die Gleich haben wird dieser Counter erhöht
				} 
			}
			if(counter_of_same_nr_and_feedback > simple_feedback) /// simple_feedback/2 entfernen wenn es besser geht
			{
				//////cout<< simple_feedback <<"simple feedback"<<endl;
				//////cout<< counter_of_same_nr_and_feedback <<"counter_of_same_nr_and_feedback"<<endl;
				

				///
				//INTERESSANT
								////cout << new_question << "war zu gleich mit " << *old_question << "simple feedback:" << simple_feedback << "und " << counter_of_same_nr_and_feedback <<"größer ist" <<endl; 
								
				////

				return true;
			}

		}


		if(counter_of_same_nr_and_feedback > simple_feedback)
		{
			//////cout<< simple_feedback <<"simple feedback"<<endl;
			//////cout<< counter_of_same_nr_and_feedback <<"counter_of_same_nr_and_feedback"<<endl;
			////cout << new_question << "war zu gleich mit " << *old_question <<endl;
			return true;
		}

		//////cout << "you give love a bad name" <<endl;

	old_question++;
	old_feedback++;

	if(old_feedback == Feedback_chaos.end())
		{
			//////cout << "Escaping the clutches" <<endl;
			break;
		}

	}

	//////cout<< "We return false meaining the question is sufficenitely different from last questions" <<endl;
	return false;
}

int vereinfachen_feedback(string one_feedback)
{
	int wie_gut = 0;
	//////cout << "Feedback to be analyesd" << one_feedback <<endl;

	//////cout<<"Feedback wird vereinfacht" <<endl;

			  for ( std::string::iterator it=one_feedback.begin(); it!=one_feedback.end(); ++it)
			  {
					int current_grading = int(*it)-48;
					////////cout<< current_grading<<endl;
					if (current_grading!= 2)
						wie_gut++;
			  }
			  //////cout << "we got " << wie_gut <<endl;
			  return wie_gut;
}



// sollte die liste um  verschieben
void MastermindSolver::update_list()
{
	int updater = 0;
	for (std::list<int>::iterator it=postions_to_ask.begin(); updater < n; updater++)
    {
    	//cout << "position" << *it << "verursacht probleme?" <<endl;

    	postions_to_ask.push_back(*it);
    	postions_to_ask.pop_front();

    	//cout << "position" << *it << "kann nicht " <<endl;

    	it=postions_to_ask.begin();
    }
    for (std::list<int>::iterator it=postions_to_ask.begin(); updater < n; ++it, updater++)
    {
    	//cout << " " << *it;
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
	////////////cout<< n << endl;
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
			//////////////cout<< " I want to save" << to_save << " in all_data" << e <<endl;
			all_data[i][e] = to_save;
			e++;
		}while( number/=6);
	}

	Cube a;
	a.generateMastermindAnswer(all_data[1],all_data[pos_guesses/2],n);
	////////////cout<< a.feedback << endl;
	string answer  = a.feedback;
	
	int tracker = 0;
	for(int e = 0; e < pos_guesses; e++)
	{
		
		a.generateMastermindAnswer(all_data[1],all_data[e],n);
		string other_answer = a.feedback;
		//////////////cout<<" " <<answer << other_answer <<endl;
		if ( other_answer == answer)
		{
			////////////cout<< "this one cold work" <<endl;
			tracker++;
			
		}
	}
	////////////cout<< "so many are left" << tracker <<endl;
		
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






