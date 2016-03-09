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
    cout << "    A B C D E F G H" << endl;
    
    for(int i = 0; i < board.size(); i++)
    {
        cout << i << "  |";
        for(int j = 0; j < board[i].size(); j++)
        {
			if(board[i][j] == NULL)
				cout << "_" << "|";
            else if(board[i][j]->team)
                cout << "X" << "|";
			else if (!board[i][j]->team)
				cout << "O" << "|";
			else
				cout << "error" << endl;
        }
        cout << endl;
    }      
}

//----------------------------Move Functions--------------------------//
//black = 1 (true) and white = 0 (false)

int Board::moveFWD(coordinates curPos) //ex:  E7 FWD
{
    int row = curPos.getRow();
    int col = curPos.getCol();
    if(board[row][col]==NULL){ cout << "ILLEGAL MOVE: no gamePiece there" << endl; }
    else
    {
        
        if (board[row][col]->team){ //black
            cout << "Moving piece at pos: " << row << ", " << col << ".  Moving black forward" << endl;
            if (board[row+1][col] != NULL && board[row+1][col]->team == 1) { cout << "Can't move: Teammate piece in the way. " << endl; }
            else if (board[row+1][col] != NULL && board[row+1][col]->team == 0) { cout << "Can't move FWD, enemy piece in the way. " << endl; }
            else{
                board[row+1][col] = board[row][col];    //set new pointer to old pointer
                board[row][col] = NULL;                     //set old pointer to null
                checkIfWin();
            }
        }
        else{                       //white
            cout << "Moving piece at pos: " << row << ", " << col << ".  Moving white forward" << endl;
            if (board[row-1][col] != NULL && board[row-1][col]->team == 0) { cout << "Can't move: Teammate piece in the way. " << endl; }
            else if (board[row-1][col] != NULL && board[row-1][col]->team == 1) { cout << "Can't move FWD, enemy piece in the way. " << endl; }
            else{
                board[row-1][col] = board[row][col];    //set new pointer to old pointer
                board[row][col] = NULL;                      //set old pointer to null
                checkIfWin();
            }
        }
    }

	return 0;
}

int Board::moveLEFT(coordinates curPos)
{
    int row = curPos.getRow();
    int col = curPos.getCol();
 
    
    if(board[row][col]==NULL){ cout << "ILLEGAL MOVE: no gamePiece there" << endl; }
    else{
        if (board[row][col]->team){ //black
            cout << "Moving piece at pos: " << row << ", " << col << ".  Moving black left" << endl;
            if (board[row+1][col+1] != NULL && board[row+1][col+1]->team == 1) { cout << "Can't move: Teammate piece in the way. " << endl; }
            else if (col == 7) { cout << "Illegal move: moving black left outta bounds" << endl; }
            else{
                board[row+1][col+1] = board[row][col];    //New piece relative left
                board[row][col] = NULL;                     //Previous position empty
                checkIfWin();
            }
        }
        else{                       //white
            //col = col + 1;
            cout << "Moving piece at pos: " << row << ", " << col << ".  Moving white left" << endl;
            if (board[row-1][col-1] != NULL && board[row-1][col-1]->team == 0) { cout << "Can't move: Teammate piece in the way. " << endl; }
            else if (col == 0) { cout << "Illegal move: moving white left outta bounds" << endl; }
            else{
                board[row-1][col-1] = board[row][col];    //New piece left
                board[row][col] = NULL;                      //Previous position empty
                checkIfWin();
            }
        }
    }
	return 0;
}

int Board::moveRIGHT(coordinates curPos)
{
    int row = curPos.getRow();
    int col = curPos.getCol();
    if(board[row][col] == NULL){ cout << "ILLEGAL MOVE: no gamePiece there" << endl; }
    else{
        if (board[row][col]->team){ //black
            cout << "Moving piece at pos: " << row << ", " << col << ".  Moving black right" << endl;
            if (board[row+1][col-1] != NULL && board[row+1][col-1]->team == 1) { cout << "Can't move: Teammate piece in the way. " << endl; }
            else if (col == 0) { cout << "Illegal move: moving black right outta bounds" << endl; }
            else{
                board[row+1][col-1] = board[row][col];    //New piece right
                board[row][col] = NULL;                     //Previous position empty
                checkIfWin();
            }
        }
        else{                       //white
            cout << "Moving piece at pos: " << row << ", " << col << ".  Moving white right" << endl;
            if (board[row-1][col+1] != NULL && board[row-1][col+1]->team == 0) { cout << "Can't move: Teammate piece in the way. " << endl; }
            else if (col == 7) { cout << "Illegal move: moving white right outta bounds" << endl; }
            else{
                board[row-1][col+1] = board[row][col];    //New piece right
                board[row][col] = NULL;                      //Previous position empty
                checkIfWin();
            }
        }
    }

	return 0;
}



bool Board::checkIfWin()
{
    for (int i = 0; i < 8; ++i)
    {
        if (board[0][i]->team == 0) { cout << "White wins!" << endl; return true;} //if white piece is on the black's home row (row 0)
        else if (board[7][i]->team == 1) { cout << "Black won" << endl; return true;} //if a black piece is in white home (row 7)
        else continue;
    }
	return false;
}















