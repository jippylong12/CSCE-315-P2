#include <string>
#include "Board.h"
#include <iostream>

using namespace std;



void Board::initGamePieces()
{
	//fill the vectors with pieces
    for(int i = 0; i < 16; i++)
    {
        blackPieces.push_back(new gamePiece(false));
        whitePieces.push_back(new gamePiece(true));
    }
    
	board.resize(8);

	for (int i = 0; i < 8; i++)
	{
		board[i].resize(8);
	}

	//change the position of the pieces
	//the first eight of each will be on the outer rows
	for(int i = 0; i < 8; i++)
    {
		blackPieces[i]->setPosition(7, i); //set position
		board[7][i] = blackPieces[i]; //push back into board
    }
	for (int i = 0; i < 8; i++)
	{
		whitePieces[i]->setPosition(0, i);
		board[0][i] = whitePieces[i];
	}
	//the second eight will be on the inner rows
	for (int i = 8; i < 16; i++)
	{
		blackPieces[i]->setPosition(6, i - 8);
		board[6][i-8] = blackPieces[i];
	}
	for (int i = 8; i < 16; i++)
	{
		whitePieces[i]->setPosition(1, i - 8);
		board[1][i - 8] = whitePieces[i];
	}
    
    
    
    
    
}

void Board::printBoard()
{
    
    for(int i = 0; i < board.size(); i++)
    {
        
        
        cout << "| ";
        for(int j = 0; j < board[i].size(); j++)
        {
			if(board[i][j] == NULL)
				cout << " " << " | ";
            else if(board[i][j]->team)
                cout << "X" << " | ";
			else if (!board[i][j]->team)
				cout << "O" << " | ";
			else
				cout << "error" << endl;
        }
        cout << endl;
    }      
}



