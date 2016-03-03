//This will be the Server
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <stdio.h>


using namespace std;
class Server
{
	int port;	  //Port Number
	int socketfd; //Socket file descriptor
	int clientSocket;
	int c;        //Stores size of incoming socket
	int rd_size;  //read size for testing
	struct sockaddr_in server;	//Handling addresses
	struct sockaddr_in client;
	
	char clientMsg[1000]; //For testing
	char clientMessage[1000];
	
public:
	Server(){}
	Server(int p) : port(p) {}  //Constructor
	~Server() {}
	
    int getPort() { return port; }
	void setPort(int p) { port = p; }
	void createSocket();
	
};