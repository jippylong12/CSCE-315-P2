#include <vector>
#include <string>
#include "gamePiece.h"


using namespace std;

class Board
{
	public:
	vector <vector <gamePiece> > Pieces;
	vector<gamePiece> blackPieces;
	vector<gamePiece> whitePieces;
	//AI goes here
	void moveBlack(coordinates a, gamePiece p);
	void moveWhite(coordinates a, gamePiece p);
	void removePiece(coordinates a, gamePiece p);
	void saveState();
	void undoMove();
};