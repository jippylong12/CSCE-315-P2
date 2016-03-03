#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Container
{
	string humanAction; //fwd right left
	string pieceRow; //1,2,3, etc..
	string pieceColumn; //a,b,c etc.
	string password; //to get into server
	string command; //DISPLAY , UNDO, UMAN-AI etc
	string difficulty; //EASY, MEDIUM, HARD
	string comment; //following ;*
	string server; //server IP addres
	string port; //positive integer for port number
};