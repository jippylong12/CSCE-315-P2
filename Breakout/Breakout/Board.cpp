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
    if (Pieces[next.getRow()][next.getCol()] != NULL || Pieces[next.getRow()][next.getCol()].team != 0)
    {
        removeWhitePiece(next)
        Pieces[orig.getRow()][orig.getCol()].currentPosition = next;
    }
    else
    {
        cout<<"Error in moving black piece"<<endl;
    }
}

void Board::moveWhite(coordinates orig, coordinates next)
{
   if (Pieces[next.getRow()][next.getCol()] != NULL || Pieces[next.getRow()][next.getCol()].team != 1)
    {
        removeBlackPiece(next);
        Pieces[orig.getRow()][orig.getCol()].currentPosition = next;
    }
    else
    {
        cout<<"Error in moving white piece"<<endl;
    }
}

void Board::removePiece(coordinates a)
{
    Pieces[a.getRow()][a.getCol()].taken = 1;
}

void Board::saveState()
{
   
}

void Board::undoMove()
{
    
}

