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
	board.difficulty = difficulty;
	if (difficulty == "EASY")
	{
		board.maxDepth = 2;
	}
	else if (difficulty == "MEDIUM")
	{
		board.maxDepth = 4;
	}
	else if (difficulty == "HARD")
	{
		board.maxDepth = 6;
	}
	else
	{
		cout << "Not valid difficulty.\n";
	}
}

void Game::setGameMode()
{
	gameMode = gameParser.contain.gameMode;

}

bool Game::parse(string s)
{
	return gameParser.sendNewInput(s);
}

void Game::displayBoard()
{

    board.printBoard();

}

bool Game::gameMove(bool turn)
{

	int row = stoi(gameParser.contain.pieceRow); //convert row string to an int
	string colString = gameParser.contain.pieceColumn;
	string moveDir = gameParser.contain.moveDirection; //Grab move direction

																//cout << "piece col " << mainGame.gameParser.contain.pieceColumn << endl;

																//convert the Column from a to a number in the vector
	int col;                          //Will be the col number corresponding to A, B, C, etc
	col = convertCol(colString);


	cout << "row: " << row << " col: " << col << endl;
	coordinates c(row, col); //piece at postion c to be moved
	if (board.isEnemy(c)) { cout << "Cannot move enemy piece\n" << endl; return 0; }

	bool goodMove = 0;

	if (moveDir.compare("FWD") == 0)
	{
		goodMove = board.moveFWD(c);
		if (goodMove) return true;
		else return false;
	}
	else if (moveDir.compare("LEFT") == 0)
	{
		goodMove = board.moveLEFT(c);
		if (goodMove) return true;
		else return false;
	}
	else
	{
		goodMove = board.moveRIGHT(c);
		if (goodMove) return true;
		else return false;
	}
}

bool Game::playAgain()
{
	string userInput;
	cout << "Play again? (Y/N)\n";
	getline(cin, userInput);
	if (userInput == "Y" || userInput == "y" ||
		userInput == "yes" || userInput == "Yes")
	{
		system("clear");
		return true;
	}
	else
	{
		cout << "Thanks for playing!\n";
		exit(2);
	}
}