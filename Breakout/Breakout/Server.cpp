#include "Server.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
/*
Server code should be fully functional: user can connect to the open port and play a random game. 
It should implement the full protocol (you may leave out actual AI-related function: 
game difficulty, ai-ai).
*/
//http://www.binarytides.com/server-client-example-c-sockets-linux/

Server::~Server(){
	close(clientSocket);	//Close the connections here
	close(socketfd);
}


void Server::createSocket(){
	
	char* buffer = (char*)malloc(sizeof(char)*SOCKET_BUF_SIZE);


    socketfd = socket(AF_INET, SOCK_STREAM, 0); //establish a socket in domain, configure communication for default
    
	cout << "Socket created..."  << socketfd << endl;
	cout << "Port No: " << port << endl;
    
	//Set server struct members
    server.sin_family = AF_INET;		//IPv4
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);      //Give it the port number
	cout << "address: " << INADDR_ANY << endl;
	
	if(::bind(socketfd, (struct sockaddr *)&server, sizeof(server)) < 0 ){ //socketfd - to be bound (client)
        cerr << "Bind Failed." << endl;
        exit(1);
    }
    cout << "Bind succesful... go to telnet and connect on port " << port << endl;
    c = sizeof(struct sockaddr_in);
    
	listen(socketfd, 1);    //allow 1 client on the port
    
	//Accept incoming client request to connect
    //telnet hostname 8888
	clientSocket = accept (socketfd, (struct sockaddr *)&client, (socklen_t*)&c);
    if(clientSocket < 0){
        cerr << "Accept Failed!" << endl;
        exit(1);
    }
	cout << "Connection accepted..." << endl;
    
    
	//Receive a message from client
   /*  while( (rd_size	= recv(clientSocket , clientMsg , 1000 , 0)) > 0 )
    {   //Sends message back to client
        write(clientSocket , "HI FROM THE CLIENT" , strlen(clientMsg));
    } */
	
	
	
	/*
		for ( ; ; ){
			int connectFd = accept(listenFd, (sockaddr *) NULL, NULL);
			shutdown(connectFd, 2);
			close(connectFd);
		}
	
	*/
	
	
	
	
	
}

string Server::getMessage(){
	//recv something
	//recv (int socketID, char* bufferPTR, int len, int flags)
	//socketfd shall be the clients sucket
	string message = "";
	recv(clientSocket, buffer, SOCKET_BUF_SIZE, 0);
	message = string(buffer);

    //char removeChars[] = {'\v', '\r', '\n', '\t'};
    char removeChars[] = "\v\r\n\t";

    for (int i = 0; i < 4; ++i) //Clean formatting of the input
        message.erase(std::remove(message.begin(), message.end(), removeChars[i]), message.end());



    
    memset(buffer, 0, SOCKET_BUF_SIZE);   //need this to clear the input buffer
	cout << "Client said: " << message << endl;
	return message;
    
}

void Server::sendMessage(string str){
	//send something
	send(clientSocket, str.c_str(), str.size(), 0);
	cout << str << endl;
	
}

