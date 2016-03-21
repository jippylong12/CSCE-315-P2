#include <vector>
#include <string>
#include "AI.h"
//#include "coordinates.h"

using namespace std;



class Board
{
	
	public:
	vector <vector <gamePiece*> > board;
	
	//AI goes here
	AI gameAI;
	
	vector<double> AIvector;
	Board() : AIvector(16, 0.0) {} //initalize vector to size of 16 all with 0's;

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
