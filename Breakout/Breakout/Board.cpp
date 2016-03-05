#include <string>
#include "Board.h"
using namespace std;

/*
    void moveBlack();
	void moveWhite();
	void removePiece();
	void saveState();
	void undoMove();
*/

void Board::moveBlack(coordinates orig, coordinates next)
{
    for (int i = 0; i < blackPieces.size(); ++i)
    {
        if (blackPieces)
        {
            blackPieces[i].currentPosition = a;
        }
    }
}

void Board::moveWhite(coordinates a, string s)
{
   
}

void Board::removeBlackPiece(coordinates a, string s)
{
    
}

void Board::removeWhitePiece(coordinates a, string s)
{
   
}

void Board::saveState()
{
   
}

void Board::undoMove()
{
    
}

