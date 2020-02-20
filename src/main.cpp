#include "solver.h" //Solver for Mastermind and Rubiks Cube
//#include "cubie.h" // Stephanie
#include "mastermindcube.h" // Stephanie
#include <list>
//21.01.2020 for communication by Elisabeth
#include <iostream>		/* for std::cout */
#include <sys/socket.h> /* for socket(), bind(), connect(), send(), and recv() */
#include <stdlib.h>     /* for atoi()*/
#include <string.h>     /* for std::string */
#include <unistd.h>     /* for close() */

#define MAXPENDING 5    /* Maximum outstanding connection requests */
#define RCVBUFSIZE 10000   /* Size of receive buffer, that many characters can be send, determines how long the recieved message can be, 159 ist the max lenght of the MasterMind question*/

void DieWithError(char *errorMessage);  /* Error handling function, there are warnings because of this but we can ignore them */
int CreateServer(unsigned short serverPort); /* function for creating the server*/
int CreateClient(char *serverIP, unsigned short serverPort); /*function for creating the client */

int main (int argc, char* argv[]) {

	srand(time(0));


	int counter_questions = 0;
	// 15.12.2019 handling of calling parameters by Isabella
	// 21.01.2020 handling og calling parameters modified by Elisabeth
	// 21.01.2020 adding Server Client Communication (TCP) by Elisabeth
	//  Port and IP-adress needs to be calculated from String for using it in communication

	  int sock;                        /* Socket descriptor */
	  char *serverIP;					/* Server IP address (dotted quad) */
	  unsigned short serverPort;		/* Echo server port */
	  std::string modus;

	  if(argc == 1)
	  {
	  	std::cout << "Not enough parameters" << endl;
	  }else
	  {

	  	 for(int i=0; i<argc; i++){
	  	 	cout << i<< ":  " << argv[i] << endl;
	  	 }

	  	modus = argv[1];

	/* 	 Client--------------------------------------------------------------------------------------*/
	  	if(modus.compare ("client") == 0){
	  		serverIP = "127.0.0.1 4000";  		/* Second arg:  Server IP Address */
	  		serverPort = 4000;	/* Third arg:  Server port */

	  		sock = CreateClient(serverIP,serverPort); // create the client/the socket

	  	   	std::string clientMessage;          /* String to send to server */
	  		std::string serverMessage;			/* String that is recieved from the server */
      		char echoBuffer[RCVBUFSIZE];		/* Buffer for serverMessage */
      		unsigned int echoStringLen;      	/* Length of string*/
      		int bytesRcvd;   					/* Bytes read in single recv()*/
	  		bool solvingComplete;				/* determine if the cube is solved */

	  		 //This is my loop for the client, it includes ending the communication if the cube is solved
	  		 //there is a do-while so the client can send the ending communication message to the server before the communication is quit


	  		// here Client setup
	   		MastermindSolver clever;
	 

	  		Cube Katze;
	  		//Katze.scramble();
			Cube guesscube(0);
			string question = "";
			vector<int> vector_best_guess;
			int bayes_wurde_gefragt = 0;
			int n = 3; 		// Eingabe oder Zufällig später NNN
			Katze.alot_like_alotlot(n); // generiert Farben
			list <vector<int>> :: iterator katzenjagd = Katze.positionen.begin();
			int PosArray[n];
			MastermindSolver Dackel;
			Dackel.set_n(n);
			vector<int> actual_vector;

			Cube tracking_cube(-1);
			string trackstring; //

			int wird_gedreht = 0;


	  		do{
	  			/* Get solvedComplete message from terminal */
	  			//std::cout << "Please insert if solving is comleted (yes: 1; no: 0): ";
	  			//std::cin >> solvingComplete;
	  			solvingComplete = 0;
	  			// the following part can be used for both the Mastermind Questions to the server as well as the instructions for the server on how to scramble the cube, the "do" loop goes from start to finish of one entire communication circle so the section will be needed twice in the loop, once for Mastermind and once for cube solver
	  			if(solvingComplete == 0)
	  			{
	  				// Get the message that should be send to the server
	  				// std::cout << "Please insert client message: ";

	  				// HIER SERVER FRAGEN ERSTELLEN
	  				// Das sind Drehungen und Fragen.
	  				//clever.generate_question(); //COPY
	  				//clever.generate_question(); // ORIGINALS

	  				
	  				int i = 0;

	  				/*
	  				for (std::list<int>::iterator it=Dackel.postions_to_ask.begin(); it != Dackel.postions_to_ask.end();  ++it)
	  				{
	  					cout << " " << *it <<endl;

	  				}
	  				return 0;
	  				*/

					for (std::list<int>::iterator it=Dackel.postions_to_ask.begin(); i < n; ++i, ++it)
					{
						//cout << *it << endl;
						PosArray[i] = *it;
					}
					i = 0;

					//Katze.bayes_guesser(&PosArray[0],sizeof(PosArray)/sizeof(PosArray[0]));


					// katzenjagd muss jetzt mit positionen eine Partnerschaft eintragen
					
					string question = "";


					
					if(bayes_wurde_gefragt > 1)
					{
						// cout << vector_best_guess.at(0) <<endl;
						actual_vector.clear();
						actual_vector.swap( vector_best_guess );
						/*
						cout << "break " <<endl;
						for(int i = 0; i < actual_vector.size(); i++)
						{
							cout << actual_vector.at(i);
						}
						*/
						//cout << actual_vector.at(0);
						

					}
					else
					{
						vector_best_guess.clear();
						actual_vector = *katzenjagd;
						
					}
					question.clear();
					for(int i = 0; i< n; i++)
					{
						if(PosArray[i]<10)
							question.append(to_string(0));
						question.append(to_string(PosArray[i]));
						question.append(to_string(actual_vector.at(i)));

					}
						// cout<<"Question to check: "<<question<<endl;


					


					
						

					
						// frage tracken
					
					Cube nicht_gedreht(-1);

					// position in 

					if(!trackstring.empty() &&  wird_gedreht == 0)
					{

					
					for (int i = 0; i < (trackstring.length()); i+=3)
					{
						//string _oneMove;
						//_oneMove.clear();
						//cout << i <<endl;
						string _oneMove = trackstring.substr(i,3);
						//cout << _oneMove <<endl;

						if 		  (_oneMove == "gR_") { tracking_cube.globalRotationR(); }
						  else if (_oneMove == "gL_") { tracking_cube.globalRotationL(); }
						  else if (_oneMove == "gD_") { tracking_cube.globalRotationD(); }
						  else if (_oneMove == "gU_") { tracking_cube.globalRotationU(); }

						  // moves
						  else if (_oneMove == "r__") { tracking_cube.r(); }
						  else if (_oneMove == "ri_") { tracking_cube.ri(); }
						  else if (_oneMove == "r2_") { tracking_cube.r(); tracking_cube.r(); }

						  else if (_oneMove == "l__") { tracking_cube.l(); }
						  else if (_oneMove == "li_") { tracking_cube.li(); }
						  else if (_oneMove == "l2_") { tracking_cube.l(); tracking_cube.l(); }

						  else if (_oneMove == "u__") { tracking_cube.u(); }
						  else if (_oneMove == "ui_") { tracking_cube.ui(); }
						  else if (_oneMove == "u2_") { tracking_cube.u(); tracking_cube.u(); }

						  else if (_oneMove == "d__") { tracking_cube.d(); }
						  else if (_oneMove == "di_") { tracking_cube.di(); }
						  else if (_oneMove == "d2_") { tracking_cube.d(); tracking_cube.d(); }

						  else if (_oneMove == "f__") { tracking_cube.f(); }
						  else if (_oneMove == "fi_") { tracking_cube.fi(); }
						  else if (_oneMove == "f2_") { tracking_cube.f(); tracking_cube.f(); }

						  else if (_oneMove == "b__") { tracking_cube.b(); }
						  else if (_oneMove == "bi_") { tracking_cube.bi(); }
						  else if (_oneMove == "b2_") { tracking_cube.b(); tracking_cube.b(); }

				






					}
					
					question.clear();
					for(int i = 0; i< n; i++)
					{
						if(PosArray[i]<10)
							question.append(to_string(0));
						question.append(to_string(PosArray[i]));
						question.append(to_string(actual_vector.at(i)));

					}
					// cout<<"Question to check: "<<question<<endl;
					//return 0;
					//tracking_cube.printCube();
					//return 0;





					for(int i = 0; i< n; i++)
					{
					if( guesscube.getColor(PosArray[i])  == -1 )
					{
						cout <<PosArray[i] << "fehlt noch" <<endl;
						//cout << "current cube" << endl;
						//guesscube.printCube();

						//cout << "tracking Cube" <<endl;
						//tracking_cube.printCube();

						//cout << "nicht getrackt Cube" <<endl;
						//nicht_gedreht.printCube();
					}




					}

					// frage getrackt


					}



















					string ask_this_server;
					if(wird_gedreht == 1)
					{
						ask_this_server = trackstring;
						cout << ask_this_server <<endl;

					}
					else
					{
						ask_this_server = question;
						katzenjagd++;
					}


	  				// =  //das ist die Nachricht, die an Server geschickt wird //*clever.CHAOS_questions_asked.begin();
	  				

					


































	  				clientMessage = ask_this_server;
	  				//std::cin >> clientMessage;
	  				// std::cout << "Your message is: " << clientMessage << std::endl;
	  			}else
	  			{
	  				clientMessage = "fin";  //this message tells the server that the communicaton can be quit
	  			}

	  			//for debug (see if "fin" was chosen correctly)
	 			// std::cout << "The clientMessage is: " << clientMessage << std::endl;

	  			// Determine length of the message to be send
      			echoStringLen = strlen(clientMessage.c_str());
	  			// std::cout << "echoStringLen: " << echoStringLen << std::endl;

      			/* Send the string to the server */
      			if (send(sock, clientMessage.c_str(), echoStringLen, 0) != echoStringLen)
          			DieWithError("send() sent a different number of bytes than expected");

      			/* Receive string from the server */
	  			if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE, 0)) <= 0)
              		DieWithError("recv() failed or connection closed prematurely");

	  			serverMessage = echoBuffer; // write the string from the buffer in serverMessage
	  			serverMessage = serverMessage.substr(0,bytesRcvd); /* Cut so only the chars that were sent in this loop are in serverMessage*/

	  			// for debug
	  			// std::cout << "bytesRcvd: " << bytesRcvd << "." << std::endl;  Anzahl der Zeichen die empfangen wurden
      			// std::cout << "echoBuffer: " << echoBuffer << "." << std::endl;
	  			// do something with the message recieved from the server
	  			//std::cout << "serverMessage: " << serverMessage << "." << std::endl;




	  		clever.addFeedback(serverMessage);
	  		


	  			//serverMessage // muss an Bayes geschickt werden; if Feedback == n -> in Cube eintragen
	  			//serverMessage;

	  		if(serverMessage == "fin ")
	  		{
	  			// finito
	  		}
	  		else if(serverMessage ==  "_")
	  		{
	  			wird_gedreht = 0;

	  		}
	  		else
	  		{


	  		


	  			Katze.Mehrere_feedbacks.push_back(vereinfachen_feedback(serverMessage));

	  			if(vereinfachen_feedback(serverMessage) == n)
	  			{	
	  				cout << "CONGRATULATIONS" <<endl;
	  				Dackel.update_list();
	  				cout << "bayes wurde " << bayes_wurde_gefragt <<"aufgerufen" <<endl;
	  				cout << question <<endl;
					Katze.Mehrere_feedbacks.clear();
					// in cube eintragen



					if(bayes_wurde_gefragt > 0 )
					{

						for( int i=0; i<n; i++)
						{
					    	guesscube.writeCube(PosArray[i],(Katze.guess[i]-48));
						
						}
					}
					else
					{
						vector<int> vector_best_guess_2;
						katzenjagd--;
						vector_best_guess_2 = *katzenjagd;
						for( int i=0; i<n; i++)
						{

					    	guesscube.writeCube(PosArray[i],(vector_best_guess_2.at(i)));
						
						}
					}


					guesscube.printCube();
					// return 0;


					katzenjagd = Katze.positionen.begin();


					bayes_wurde_gefragt = 0;

					int check_for_one = 0;

					for(int i=0;i<6;i++)
						for(int j=0;j<3;j++)
							for(int k=0;k<3;k++)
					{
						if(	guesscube._cube[i][j][k]==-1 )
						{

							check_for_one++;
							// cout <<  check_for_one <<endl;
						}

					}


					
					//check_for_one = 100;

					// jetzt wird gedreht 
					if(54-check_for_one > 6+24)
					{
						wird_gedreht = 1;
						
					//in cube eintragen fertig
					// schauen ob was gelöst werden kann
					cout << endl << "Kantenfelder: " << endl;
					guesscube.printCube();
					guesscube.moveToTopCross();
					guesscube.switchEdgesTopCross();
					cout << endl << "Topcross:" << endl;
					guesscube.printCube();
					guesscube.solveSecondLayer();
					cout << endl << "Second Layer:" << endl;
					guesscube.printCube();
					guesscube.moveToBottomCross();
					guesscube.switchEdgesBottomCross();
					cout << endl << "Bottom Cross:" << endl;
					guesscube.printCube();
					

					if(54-check_for_one >= 6+24+24)
					{
						
					guesscube.moveToTopCorners();
					guesscube.printCube();
					guesscube.solvePositionCorners();
					guesscube.printCube();
					guesscube.solveOrientationCorners();
					guesscube.printCube();

					guesscube.printCube();
					// return 0;

					// alle farben sind bekannt
					// check for -1
					int check_for_one = 0;

					for(int i=0;i<6;i++)
						for(int j=0;j<3;j++)
							for(int k=0;k<3;k++)
					{
						if(	guesscube._cube[i][j][k]==-1 )
						{

							check_for_one++;
							cout <<  check_for_one <<endl;
						}

					}
					
					if(guesscube.isCubeSolved() && check_for_one == 0){

						cout << "cube wird versucht zu solven" <<endl;
						guesscube.solveCube();
						cout << "SOLVED CUBE (Algorithm): " << endl;
						guesscube.printCube();
						return 0;
					}

					cout << "SOLVED CUBE: " << endl;
					guesscube.printCube();
					

				}

					trackstring =  guesscube.moves;
					cout << trackstring <<endl;
					guesscube.moves.clear();

			}
	
	  		}

	  			

	  			if(katzenjagd == Katze.positionen.end() || bayes_wurde_gefragt != 0){

	  				katzenjagd = Katze.positionen.begin();


	  				//bayes
					// cout<<"+bayesguessser";
					string bestGuess =	Katze.bayes_guesser(n,bayes_wurde_gefragt);
					
					bayes_wurde_gefragt++;

					// cout << "bayes erfolgreich " <<endl;
					vector_best_guess.clear();

						for(int i=0;i<n;i++)
						{
							vector_best_guess.push_back( bestGuess.at(i) - 48 );
						}
						
	  			}

	  		}
	  			

	  					  			

	  			




	  		}while(solvingComplete == 0);  //while the cube is not solved

      		close(sock); // this closes the Socket and ends the communication, it needs to be performed by both client and server => fin message to server
	  	}
	  	// Server--------------------------------------------------------------------------------------
	  	else if(modus.compare ("server") == 0){
	  		serverPort = 4000;  /* Second arg:  Server port */

	 		sock = CreateServer(serverPort);  //create the server/the socket

	  		std::string serverMessage;			/* Message that is sent to the client */
	  		std::string clientMessage;			/* Message that is recieved from the client */
	  		char clientMessageBuffer[RCVBUFSIZE];        /* Buffer for message string from client*/
      		int recvMsgSize;                    /* Size of received message */
	  		unsigned int stringLen;      /* Length of string to echo */
	  		 int our_generated_n;



	  		 /// Here Server setup
	  		Cube scrambled(3);
	  		scrambled.scramble();
	  		int move_length = 0;
	  		scrambled.printCube();

			// checking split question before the start //
			//cout << "before Start" <<endl;
			//cout << scrambled.splitQuestion("490400",2);
			//cout << "before Start" <<endl;
			// wenn feedback 2 -> nicht richtig, genau was wir wollten
			// noch testen für kanten und ecken?



	  		/* This is my loop for the server, it includes ending the communication if the cube is solved */

	  		do{

      			/* Receive message from client */
      			if ((recvMsgSize = recv(sock, clientMessageBuffer, RCVBUFSIZE, 0)) < 0)
          			DieWithError("recv() failed");

	  			
	  			our_generated_n = recvMsgSize/3; // n aus der Anzahl der erhaltenen Characters berechnen

	  			clientMessage = clientMessageBuffer;
	  			clientMessage = clientMessage.substr(0,recvMsgSize); /* Cut so only the chars that were sent in this loop are in clientMessage*/

	  			
	  			if(clientMessage.compare("fin") != 0)
	  			{
	  				 

	  				if (isalpha((int)clientMessage[0])) // dann brauchen wir drehungen
	  					{
	  						
	  						string drehungen = clientMessage;
	  						// cout << drehungen <<endl;	  					
	  						string trackstring =  drehungen;


	  						for (int i = 0; i < (trackstring.length()); i+=3)
							{
							//cout <<"wird gedreht" <<endl;
									string _oneMove = trackstring.substr(i,3);
									//cout << _oneMove <<endl;
									

									if 		  (_oneMove == "gR_") { scrambled.globalRotationR(); }
									  else if (_oneMove == "gL_") { scrambled.globalRotationL(); }
									  else if (_oneMove == "gD_") { scrambled.globalRotationD(); }
									  else if (_oneMove == "gU_") { scrambled.globalRotationU(); }
									  else if (_oneMove == "r__") { scrambled.r(); }
									  else if (_oneMove == "ri_") { scrambled.ri(); }
									  else if (_oneMove == "r2_") { scrambled.r(); scrambled.r(); }
									  else if (_oneMove == "l__") { scrambled.l(); }
									  else if (_oneMove == "li_") { scrambled.li(); }
									  else if (_oneMove == "l2_") { scrambled.l(); scrambled.l(); }
									  else if (_oneMove == "u__") { scrambled.u(); }
									  else if (_oneMove == "ui_") { scrambled.ui(); }
									  else if (_oneMove == "u2_") { scrambled.u(); scrambled.u(); }
									  else if (_oneMove == "d__") { scrambled.d(); }
									  else if (_oneMove == "di_") { scrambled.di(); }
									  else if (_oneMove == "d2_") { scrambled.d(); scrambled.d(); }
									  else if (_oneMove == "f__") { scrambled.f(); }
									  else if (_oneMove == "fi_") { scrambled.fi(); }
									  else if (_oneMove == "f2_") { scrambled.f(); scrambled.f(); }
									  else if (_oneMove == "b__") { scrambled.b(); }
									  else if (_oneMove == "bi_") { scrambled.bi(); }
									  else if (_oneMove == "b2_") { scrambled.b(); scrambled.b(); }
									  else
									  {
									  	cout  << "ES FEHLT WAS" <<endl;
									  	cout << _oneMove <<endl;

									  }
								}
	  						// Cube drehen
	  					// cube gelöst?
					scrambled.printCube();


					serverMessage = "_";

					

	  					}
	  				else
	  				{
	  					serverMessage =  scrambled.splitQuestion(clientMessage, our_generated_n);	  					
	  				}








































	  			}else
	  			{
	  				serverMessage = "fin";
	  			}

	  			//debug
	  			//std::cout << "The serverMessage is: " << serverMessage << std::endl;
	  			stringLen = strlen(serverMessage.c_str()); /* get lenght of the message to be send */
	  			// std::cout << "stringLen: " << stringLen << std::endl;






	  			/* Send serverMessage to client */
	  			if (send(sock, serverMessage.c_str(), stringLen, 0) != stringLen)
	  				DieWithError("send() failed");


	 		if( stringLen == 0) // wenn wir keine Antwort bekommen
	 			return 0;
	  		}while(clientMessage.compare("fin") != 0);

      		close(sock); // this closes the Socket and ends the communication, it needs to be performed by both client and server => fin message to server

	  	}
	  	else{
	  		std::cout << "Wrong init-parameters";
	  	}
	  }




	return 0;
}
