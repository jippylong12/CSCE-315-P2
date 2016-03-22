//This will hold the game class

#include <iostream>

#include "Parser.h"
#include "Board.h"

using namespace std;

class Game
{
	const string password = "a";
	string difficulty;
	string gameMode; //AI-AI HUMAN-Ai
public:
	Parser gameParser;
	Board board;
	bool DISPLAY; //determines if we should display the board after each term


	
	string getPassword() { return password; }
	string getDifficulty() { return difficulty; }
	string getGameMode() { return gameMode; }
	int convertCol(string);

	void setDifficulty();
	void setGameMode();
	bool parse(string);
	
	void displayBoard();

};

