#include <vector>
#include <string>
#include "gamePiece.h"
//#include "coordinates.h"

using namespace std;



class Board
{
	public:
	vector <vector <gamePiece*> > board;
		
	
	vector<gamePiece*> blackPieces;
	vector<gamePiece*> whitePieces;
    
    bool isLegalMove;
	
	
	void initGamePieces();
	void printBoard();
	//AI goes here
	//void moveBlack(coordinates a, gamePiece p);
	//void moveWhite(coordinates a, gamePiece p);
	//void removePiece(coordinates a, gamePiece p);
    coordinates moveFWD(coordinates);
    coordinates moveLEFT(coordinates);
    coordinates moveRIGHT(coordinates);
	
    bool checkIfWin();
    
    
    
    
    
    vector <vector <gamePiece> > Pieces;
	//AI goes here
	//void moveBlack(coordinates orig, coordinates next);
	//void moveWhite(coordinates orig, coordinates next);
	//void removePiece(coordinates a); //just need to set taken to 0 and its position to NULL or -1
	void saveState();
	void undoMove();
};
