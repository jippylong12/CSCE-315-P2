#include <vector>
#include <string>
#include "gamePiece.h"
//#include "coordinates.h"

using namespace std;



class Board
{
	
	public:
	vector <vector <gamePiece*> > board;
	string difficulty;

	/*AI STARTS*/
	// the evaluation fucntion is what the AI determines is the best move. It should run the function for every gamePiece and 
	// then pick the piece that returns the highest number. The inputs and the importance of each of the inputs are determined by us.
	// For now I have only three inputs: 
	//		1) Team
	//		2) Distance away from the other side of the board
	//		3) Can I take a piece? (0 if no, 1 if one or more piceces are able)
	//
	// This is a rought start and so it should change as we go along. 
	double evaluationFunction(gamePiece);

	/* RETURNS 1 DIVIDED BY HOW MANY SPACES THE GAME PIECE IS FROM WINNING*/
	double spacesFromWin(gamePiece);

	/*RETURNS 10 IF A PIECE CAN BE TAKEN AND 0 IF NONE CAN*/
	double takePiece(gamePiece);

	double canBeTaken(gamePiece);
	
	vector<double> AIvector;
	Board() : AIvector(16, 0.0) {} //initalize vector to size of 16 all with 0's;


	/*ACTUAL BOARD*/
	vector<gamePiece*> blackPieces;
	vector<gamePiece*> whitePieces;
	void runAI(); //updates the AIvector
	
	vector <vector<vector <gamePiece*> > > savedBoard;

    bool isLegalMove = 0;   //flag to test legal move
	bool moveDone = 0;      //another flag for the ai to test if the move executed

    bool isEnemy(coordinates);
	
	void initBoard();
	void printBoard();

    int moveFWD(coordinates);
    int moveLEFT(coordinates);
    int moveRIGHT(coordinates);
	
    bool checkIfWin();
    
    void saveState();
    void undo();		

    vector <vector <gamePiece> > Pieces;
    void randAI();
};
