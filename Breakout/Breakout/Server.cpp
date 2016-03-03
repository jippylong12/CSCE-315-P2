#include "Server.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <cstdlib>

//http://www.binarytides.com/server-client-example-c-sockets-linux/

void Server::createSocket(){
	
    
    socketfd = socket(AF_INET, SOCK_STREAM, 0); //establish a socket in domain, configure communication for default
    cout << "Socket created..."  << socketfd << endl;
	cout << "Port No: " << port << endl;
    //Set server struct members
    server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);      //Give it the port number
	
	if( bind(socketfd, (struct sockaddr *)&server, sizeof(server)) < 0 ){
        cerr << "Bind Failed." << endl;
        exit(1);
    }
    cout << "Bind done..." << endl;
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
    while( (rd_size	= recv(clientSocket , clientMsg , 1000 , 0)) > 0 )
    {   //Sends message back to client
        write(clientSocket , "HI FROM THE CLIENT" , strlen(clientMsg));
    }
}