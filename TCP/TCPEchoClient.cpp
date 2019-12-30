#include <iostream>   /* for std::cerr and std::cout */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <iostream>	  /* for cout */

#define RCVBUFSIZE 32   /* Size of receive buffer */

void DieWithError(char *errorMessage);  /* Error handling function */

int main(int argc, char *argv[])
{
    int sock;                        /* Socket descriptor */
    struct sockaddr_in echoServAddr; /* Echo server address */
    unsigned short echoServPort;     /* Echo server port */
    char *servIP;                    /* Server IP address (dotted quad) */
   	std::string clientMessage;          /* String to send to server */
	std::string serverMessage;			/* String that is recieved from the server */
    char echoBuffer[RCVBUFSIZE];				/* Buffer for serverMessage */
    unsigned int echoStringLen;      /* Length of string to echo */
    int bytesRcvd, totalBytesRcvd;   /* Bytes read in single recv()
                                        and total bytes read */
	bool solvingComplete;

    if ((argc < 2) || (argc > 3))    /* Test for correct number of arguments */
    {
       std::cerr << "Usage:" << argv[0] << "<Server IP> [<Echo Port>]" << std::endl;
       exit(1);
    }

    servIP = argv[1];             /* First arg: server IP address (dotted quad) */

    if (argc == 3)
        echoServPort = atoi(argv[2]); /* Use given port, if any */
    else
        echoServPort = 7;  /* 7 is the well-known port for the echo service */

    /* Create a reliable, stream socket using TCP */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    /* Construct the server address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));     /* Zero out structure */
    echoServAddr.sin_family      = AF_INET;             /* Internet address family */
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);   /* Server IP address */
    echoServAddr.sin_port        = htons(echoServPort); /* Server port */

    /* Establish the connection to the echo server */
    if (connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("connect() failed");

	do
	{
		/* Get solvedComplete message from terminal */
		std::cout << "Please insert if solving is comleted (yes: 1; no: 0): ";
		std::cin >> solvingComplete;

		if(solvingComplete == 0)
		{
			/* Get clientMessage from terminal */
			std::cout << "Please insert client message: ";
			std::cin >> clientMessage;
			std::cout << "Your message is: " << clientMessage << std::endl;
		}else
		{
			clientMessage = "fin";
		}
		
		std::cout << "The clientMessage is: " << clientMessage << std::endl;

    	echoStringLen = strlen(clientMessage.c_str());          /* Determine input length */
		std::cout << "echoStringLen: " << echoStringLen << std::endl;

    	/* Send the string to the server */
    	if (send(sock, clientMessage.c_str(), echoStringLen, 0) != echoStringLen)
        	DieWithError("send() sent a different number of bytes than expected");

    	/* Receive string from the server */
		if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE, 0)) <= 0)
            DieWithError("recv() failed or connection closed prematurely");

		serverMessage = echoBuffer;
		serverMessage = serverMessage.substr(0,bytesRcvd); /* Get only the chars that were sent in this loop */

		std::cout << "bytesRcvd: " << bytesRcvd << "." << std::endl;
    	std::cout << "echoBuffer: " << echoBuffer << "." << std::endl;
		std::cout << "serverMessage: " << serverMessage << "." << std::endl;    /* Print the serverMessage */

	}while(solvingComplete == 0);
	
    close(sock);
    exit(0);
}
