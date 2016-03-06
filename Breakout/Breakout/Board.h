#include <vector>
#include <string>
#include "gamePiece.h"


using namespace std;



class Board
{
	public:

	gamePiece* b = new gamePiece(true); // black piece
	gamePiece* w = new gamePiece(false); // white piece
	vector <vector <gamePiece*> > board;
		
	
	vector<gamePiece*> blackPieces;
	vector<gamePiece*> whitePieces;
	
	
	void initGamePieces();
	void printBoard();
	//AI goes here
	/*void moveBlack(coordinates a, gamePiece p);
	void moveWhite(coordinates a, gamePiece p);
	void removePiece(coordinates a, gamePiece p);

	vector <vector <gamePiece> > Pieces;
	//AI goes here
	void moveBlack(coordinates orig, coordinates next);
	void moveWhite(coordinates orig, coordinates next);
	void removePiece(coordinates a);
	void saveState();
	void undoMove();*/
};
