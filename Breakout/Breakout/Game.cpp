//define functions of the game class that we need. 
#include <string>
#include "Game.h"
using namespace std;

int Game::convertCol(string colString)
{
	int col = 0;
	if (colString.compare("A") == 0) col = 0;
	else if (colString.compare("B") == 0) col = 1;
	else if (colString.compare("C") == 0) col = 2;
	else if (colString.compare("D") == 0) col = 3;
	else if (colString.compare("E") == 0) col = 4;
	else if (colString.compare("F") == 0) col = 5;
	else if (colString.compare("G") == 0) col = 6;
	else if (colString.compare("H") == 0) col = 7;

	return col;
}

void Game::setDifficulty()
{
	difficulty = gameParser.contain.difficulty;
}

void Game::setGameMode()
{
	gameMode = gameParser.contain.gameMode;
}

bool Game::parse(string s)
{
	return gameParser.sendNewInput(s);
}

void Game::UNDO()
{

}

void Game::displayBoard()
{

    board.printBoard();

}