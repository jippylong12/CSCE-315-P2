#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Container
{
public:
	
	bool DISPLAY = 0; //check after each tern to see if on or off. 
	bool EXIT = 0; //check after each user input to see if on or off and exit if 1
	bool UNDO = 0; //when this is called we undo 

	bool MOVE = 0; //know when to move
    
    bool WIN = 0; //Maybe we need this?
    
    //this will hold the last ten user commands (so the last 20 commands with user and AI)
	//Once it gets to 20 it will add the newest commands and pop the back two off. The back two because the human will not be able 
	//to call undo until it's their turn again so we have to think of the moves as pairs. 
	deque<string> lastTenCommands; 

	string gameMode = ""; //AI-AI HUMAN-AI
	string moveDirection = ""; //FWD RIGHT LEFT
	string password = ""; //find password
	string pieceRow = ""; //1,2,3, etc..
	string pieceColumn = ""; //A,B,C etc.
	string difficulty = ""; //EASY, MEDIUM, HARD
	string comment = ""; //following ;*
	string server = ""; //server IP addres
	string port = ""; //positive integer for port number
};