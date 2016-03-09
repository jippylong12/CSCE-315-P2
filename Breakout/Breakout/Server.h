////This will be the Server
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <string>
//#include <stdio.h>
//using namespace std;
//
//class Server
//{
//	int port;	  //Port Number
//	int socketfd; //Socket file descriptor
//	int clientSocket;
//	int c, rd_size;        //Stores size of incoming socket
//						   //read size for testing
//	struct sockaddr_in server;	//Handling addresses
//	struct sockaddr_in client;
//	
//	char buffer[1024]; //For testing
//	char clientMessage[1000];
//	
//	const int SOCKET_BUF_SIZE = 1024;
//	
//public:
//	Server(){}
//	Server(int p) : port(p) {}  //Constructor
//	~Server();
//	
//    int getPort() { return port; }
//	void setPort(int p) { port = p; }
//	
//	void createSocket();
//	
//	//Communication between server and client
//	string getMessage();	//get a message from the client
//	void sendMessage(string s);	//send a message to the client
//	
//};