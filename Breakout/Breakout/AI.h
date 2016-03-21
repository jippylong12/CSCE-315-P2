#include "gamePiece.h"

class AI
{
public:
	
	// the evaluation fucntion is what the AI determines is the best move. It should run the function for every gamePiece and 
	// then pick the piece that returns the highest number. The inputs and the importance of each of the inputs are determined by us.
	// For now I have only three inputs: 
	//		1) Team
	//		2) Distance away from the other side of the board
	//		3) Can I take a piece? (0 if no, 1 if one or more piceces are able)
	//
	// This is a rought start and so it should change as we go along. 
	string difficulty;
	
	void setDifficulty(string);

	double evaluationFunction(gamePiece);
	
	/* RETURNS 1 DIVIDED BY HOW MANY SPACES THE GAME PIECE IS FROM WINNING*/
	double spacesFromWin(gamePiece);

	/*RETURNS 10 IF A PIECE CAN BE TAKEN AND 0 IF NONE CAN*/
	double takePiece(gamePiece);

	double canBeTaken(gamePiece);

};