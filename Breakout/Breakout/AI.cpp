#include "AI.h"


void AI::setDifficulty(string diff)
{
	difficulty = diff;
}

double AI::evaluationFunction(gamePiece Piece)
{
	return spacesFromWin(Piece) + takePiece(Piece) + canBeTaken(Piece);
}

double AI::spacesFromWin(gamePiece)
{
	return 0; /*TEMP CHANGE WHEN YOU DO THE FUNCTION*/
}

double AI::takePiece(gamePiece)
{
	return 0;/*TEMP CHANGE WHEN YOU DO THE FUNCTION*/
}

double AI::canBeTaken(gamePiece)
{
	return 0;/*TEMP CHANGE WHEN YOU DO THE FUNCTION*/
}