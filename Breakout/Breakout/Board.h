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
	
	vector <vector<vector <gamePiece*> > > savedBoard;

    bool isLegalMove = 0;   //flag to test legal move
	bool moveDone = 0;      //another flag for the ai to test if the move executed


	

	
	void initGamePieces();
	void printBoard();
	//AI goes here
    int moveFWD(coordinates);
    int moveLEFT(coordinates);
    int moveRIGHT(coordinates);
	
    bool checkIfWin();
    
    void saveState();
    void undo();		
    
    
    
    vector <vector <gamePiece> > Pieces;
    void randAI();
	void undoMove();
};
