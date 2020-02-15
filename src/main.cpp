#include "debug.h"
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
#define RCVBUFSIZE 159   /* Size of receive buffer, that many characters can be send, determines how long the recieved message can be, 159 ist the max lenght of the MasterMind question*/

void DieWithError(char *errorMessage);  /* Error handling function, there are warnings because of this but we can ignore them */
int CreateServer(unsigned short serverPort); /* function for creating the server*/
int CreateClient(char *serverIP, unsigned short serverPort); /*function for creating the client */

int main (int argc, char* argv[]) {

	//new 13.12.2019 adding debug by Thomas
	debug Debugger;
	Debugger.setdebug(0);
	Debugger.setdebug(1);
	Debugger.printf("MasterCube is starting");
	// Debug inilasition over


	// here server
	// wait for answer
	// send answer




	//here client
	//get n
	// generate solver
	//Mastermind solver
	//MastermindSolver clever;
	//clever.set_n(3);
	//clever.generate_question();

	// generate question
	// send question
	// calculate answer
	// answer to IDA*
	// rotate?

	//repeat



	//15.12.2019 handling of calling parameters by Isabella
	//21.01.2020 handling og calling parameters modified by Elisabeth
	//21.01.2020 adding Server Client Communication (TCP) by Elisabeth
	// Port and IP-adress needs to be calculated from String for using it in communication

	// int sock;                        /* Socket descriptor */
	// char *serverIP;					/* Server IP address (dotted quad) */
	// unsigned short serverPort;		/* Echo server port */
	// std::string modus;
	//
	// if(argc == 1)
	// {
	// 	std::cout << "Not enough parameters" << endl;
	// }else
	// {
	//
	// 	//for(int i=0; i<argc; i++){
	// 	//	cout << i<< ":  " << argv[i] << endl;
	// 	//}
	//
	// 	modus = argv[1];
	//
	// 	//Client--------------------------------------------------------------------------------------
	// 	if(modus.compare ("client") == 0){
	// 		serverIP = argv[2];  		/* Second arg:  Server IP Address */
	// 		serverPort = atoi(argv[3]);	/* Third arg:  Server port */
	//
	// 		sock = CreateClient(serverIP,serverPort); //create the client/the socket
	//
	// 	   	std::string clientMessage;          /* String to send to server */
	// 		std::string serverMessage;			/* String that is recieved from the server */
    // 		char echoBuffer[RCVBUFSIZE];		/* Buffer for serverMessage */
    // 		unsigned int echoStringLen;      	/* Length of string*/
    // 		int bytesRcvd;   					/* Bytes read in single recv()*/
	// 		bool solvingComplete;				//determine if the cube is solved
	//
	// 		//This is my loop for the client, it includes ending the communication if the cube is solved
	// 		do //there is a do-while so the client can send the ending communication message to the server before the communication is quit
	// 		{
	// 			/* Get solvedComplete message from terminal */
	// 			std::cout << "Please insert if solving is comleted (yes: 1; no: 0): ";
	// 			std::cin >> solvingComplete;
	//
	// 			//the following part can be used for both the Mastermind Questions to the server as well as the instructions for the server on how to scramble the cube, the "do" loop goes from start to finish of one entire communication circle so the section will be needed twice in the loop, once for Mastermind and once for cube solver
	// 			if(solvingComplete == 0)
	// 			{
	// 				//Get the message that should be send to the server
	// 				std::cout << "Please insert client message: ";
	// 				std::cin >> clientMessage;
	// 				//std::cout << "Your message is: " << clientMessage << std::endl;
	// 			}else
	// 			{
	// 				clientMessage = "fin"; //this message tells the server that the communicaton can be quit
	// 			}
	//
	// 			//for debug (see if "fin" was chosen correctly)
	// 			//std::cout << "The clientMessage is: " << clientMessage << std::endl;
	//
	// 			//Determine length of the message to be send
    // 			echoStringLen = strlen(clientMessage.c_str());
	// 			//std::cout << "echoStringLen: " << echoStringLen << std::endl;
	//
    // 			/* Send the string to the server */
    // 			if (send(sock, clientMessage.c_str(), echoStringLen, 0) != echoStringLen)
    //     			DieWithError("send() sent a different number of bytes than expected");
	//
    // 			/* Receive string from the server */
	// 			if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE, 0)) <= 0)
    //         		DieWithError("recv() failed or connection closed prematurely");
	//
	// 			serverMessage = echoBuffer; //write the string from the buffer in serverMessage
	// 			serverMessage = serverMessage.substr(0,bytesRcvd); /* Cut so only the chars that were sent in this loop are in serverMessage*/
	//
	// 			//for debug
	// 			//std::cout << "bytesRcvd: " << bytesRcvd << "." << std::endl; //Anzahl der Zeichen die empfangen wurden
    // 			//std::cout << "echoBuffer: " << echoBuffer << "." << std::endl;
	//
	// 			//do something with the message recieved from the server
	// 			std::cout << "serverMessage: " << serverMessage << "." << std::endl;
	//
	// 		}while(solvingComplete == 0); //while the cube is not solved
	//
    // 		close(sock); //this closes the Socket and ends the communication, it needs to be performed by both client and server => fin message to server
	// 	}
	// 	//Server--------------------------------------------------------------------------------------
	// 	else if(modus.compare ("server") == 0){
	// 		serverPort = atoi(argv[2]);  /* Second arg:  Server port */
	//
	// 		sock = CreateServer(serverPort); //create the server/the socket
	//
	// 		std::string serverMessage;			/* Message that is sent to the client */
	// 		std::string clientMessage;			/* Message that is recieved from the client */
	// 		char clientMessageBuffer[RCVBUFSIZE];        /* Buffer for message string from client*/
    // 		int recvMsgSize;                    /* Size of received message */
	// 		unsigned int stringLen;      /* Length of string to echo */
	// 		//int n;
	//
	// 		//This is my loop for the server, it includes ending the communication if the cube is solved
	// 		do
	// 		{
	//
    // 			/* Receive message from client */
    // 			if ((recvMsgSize = recv(sock, clientMessageBuffer, RCVBUFSIZE, 0)) < 0)
    //     			DieWithError("recv() failed");
	//
	// 			//debug
	// 			//std::cout << "recvMsgSize: " << recvMsgSize << "." << std::endl;
	// 			//n = recvMsgSize/3; //n aus der Anzahl der erhaltenen Characters berechnen
	//
	// 			clientMessage = clientMessageBuffer;
	// 			clientMessage = clientMessage.substr(0,recvMsgSize); /* Cut so only the chars that were sent in this loop are in clientMessage*/
	//
	// 			//debug
	// 			//std::cout << "clientMessageBuffer: " << clientMessageBuffer << "." << std::endl;
	//
	// 			//do something with the message recieved from the client
	// 			std::cout << "clientMessage: " << clientMessage << "." << std::endl;
	//
	// 			//see if the client has sent the message to end the communication
	// 			if(clientMessage.compare("fin") != 0)
	// 			{
	// 				//Get the message that should be send to the client
	// 				std::cout << "Please insert server message: ";
	// 				std::cin >> serverMessage;
	// 			}else
	// 			{
	// 				serverMessage = "fin";
	// 			}
	//
	// 			//debug
	// 			//std::cout << "The serverMessage is: " << serverMessage << std::endl;
	//
	// 			stringLen = strlen(serverMessage.c_str()); /* get lenght of the message to be send */
	// 			//std::cout << "stringLen: " << stringLen << std::endl;
	//
	// 			/* Send serverMessage to client */
	// 			if (send(sock, serverMessage.c_str(), stringLen, 0) != stringLen)
	// 				DieWithError("send() failed");
	//
	// 		}while(clientMessage.compare("fin") != 0);
	//
    // 		close(sock); //this closes the Socket and ends the communication, it needs to be performed by both client and server => fin message to server
	//
	// 	}
	// 	else{
	// 		std::cout << "Wrong init-parameters";
	// 	}
	// }





	Cube solved;
	Cube scrambled;
	//scrambled.scramble();
	scrambled.r();
	scrambled.l();
	scrambled.f();
	scrambled.di();
	scrambled.r();
	scrambled.b();
	scrambled.r();
	scrambled.fi();
	cout << "scrambled:" << endl;
	scrambled.printCube();
	scrambled.clearMoves();
	Cube tmp(0); //Cube mit -1 gefüllt
	Cube tmp2(-1); //Cube mit indizes

	 // int cnt = 0; //alles außer 0 wird zu -1 -> test der moveToTopCross()
	 // for(int i=0; i<6; i++){
	 // 	for(int j=0; j<3; j++){
	 // 		for(int k=0; k<3; k++){
	 // 			if(scrambled.getColor(cnt) != 0){
	 // 				scrambled.writeCube(cnt,-1);
	 // 			}
	 // 			cnt++;
	 // 		}
	 // 	}
	 // }

	//scrambled.writeCube(12,-1);
	//scrambled.writeCube(19,-1);
	//scrambled.printCube();
	scrambled.moveToTopCross(); //alle weißen (0) zum Kreuz der Obersten ebene
	//cout << "TOP CROSS:" << endl;
	//scrambled.printCube();
	scrambled.switchEdgesTopCross();
	//scrambled.printCube();
	scrambled.clearMoves();
	//scrambled.printMoves();
	//scrambled.findSwitchableEdges();
	scrambled.solveSecondLayer();
	scrambled.printCube();
	scrambled.printMoves();
	//bool x = scrambled.get_bedingung();
	//cout << x << endl;


	//scrambled.scramble();
	//scrambled.splitQuestion("011033044136095112", 6);
	return 0;
}
