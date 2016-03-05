#include <vector>
#include <string>
#include "gamePiece.h"


using namespace std;

class Board
{
	public:
	vector <vector <gamePiece> > Pieces;
	//AI goes here
	void moveBlack(coordinates orig, coordinates next);
	void moveWhite(coordinates orig, coordinates next);
	void removePiece(coordinates a);
	void saveState();
	void undoMove();
};