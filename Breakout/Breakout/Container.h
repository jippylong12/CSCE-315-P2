#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Container
{
public:
	string humanAction = ""; //fwd right left
	string password = ""; //find password
	string pieceRow = ""; //1,2,3, etc..
	string pieceColumn = ""; //a,b,c etc.
	string command = ""; //DISPLAY , UNDO, UMAN-AI etc
	string difficulty = ""; //EASY, MEDIUM, HARD
	string comment = ""; //following ;*
	string server = ""; //server IP addres
	string port = ""; //positive integer for port number
};