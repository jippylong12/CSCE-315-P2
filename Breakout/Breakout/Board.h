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

    bool isEnemy(coordinates);
	

	
	void initGamePieces();
	void printBoard();
	//AI goes here
	// the evaluation fucntion is what the AI determines is the best move. It should run the function for every gamePiece and 
	// then pick the piece that returns the highest number. The inputs and the importance of each of the inputs are determined by us.
	// For now I have only three inputs: 
	//		1) Team
	//		2) Distance away from the other side of the board
	//		3) Can I take a piece? (0 if no, 1 if one or more piceces are able)
	//
	// This is a rought start and so it should change as we go along. 
	double evaluationFunction(bool, int, int); 


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
