#include <iostream>	  /* for cin */
#include <sys/socket.h> /* for recv() and send() */
#include <unistd.h>     /* for close() */
#include <string.h>		/* for string */

#define RCVBUFSIZE 32   /* Size of receive buffer */

void DieWithError(char *errorMessage);  /* Error handling function */

void HandleTCPClient(int clntSocket)
{
    std::string serverMessage;			/* Message that is sent to the client */
	std::string clientMessage;			/* Message that is recieved from the client */
	char clientMessageBuffer[RCVBUFSIZE];        /* Buffer for message string from client*/
    int recvMsgSize;                    /* Size of received message */
	unsigned int stringLen;      /* Length of string to echo */
	int bytesRcvd, totalBytesRcvd;   /* Bytes read in single recv()
                                        and total bytes read */
	
	do
	{

    	/* Receive message from client */
    	if ((recvMsgSize = recv(clntSocket, clientMessageBuffer, RCVBUFSIZE, 0)) < 0)
        	DieWithError("recv() failed");
	
		std::cout << "recvMsgSize: " << recvMsgSize << "." << std::endl;
	
		/* Put processing of client message here */
		clientMessage = clientMessageBuffer;
		clientMessage = clientMessage.substr(0,recvMsgSize); /* Get only the chars that were sent in this loop */
		std::cout << "clientMessageBuffer: " << clientMessageBuffer << "." << std::endl;
		std::cout << "clientMessage: " << clientMessage << "." << std::endl;

		if(clientMessage.compare("fin") != 0)
		{
			/* Recieve serverMessage from terminal */
			std::cout << "Please insert server message: ";
			std::cin >> serverMessage;
		}else
		{
			serverMessage = "fin";
		}

		std::cout << "The serverMessage is: " << serverMessage << std::endl;
		
		stringLen = strlen(serverMessage.c_str());
		std::cout << "stringLen: " << stringLen << std::endl;
	
		/* Send serverMessage to client */
		if (send(clntSocket, serverMessage.c_str(), stringLen, 0) != stringLen)
			DieWithError("send() failed");

	}while(clientMessage.compare("fin") != 0);

    close(clntSocket);    /* Close client socket */
	std::cout << "Congratulations, the cube was successfully solved! :)" << std::endl;	
}
