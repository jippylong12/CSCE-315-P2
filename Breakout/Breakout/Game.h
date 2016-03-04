//This will hold the game class


#include "Parser.h"
#include "Board.h"
using namespace std;

class Game
{
	string password = "a";
	string difficulty;
public:
	Parser gameParser;
	Board board;
	bool DISPLAY; //determines if we should display the board after each term


	
	string getPassword() { return password; }
	string setDifficulty(string);

};

