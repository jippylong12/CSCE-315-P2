//define functions of the game class that we need. 
#include <string>
#include "Game.h"
using namespace std;

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