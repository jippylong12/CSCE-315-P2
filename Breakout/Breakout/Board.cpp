#include <string>
#include "Board.h"
#include <iostream>

using namespace std;



void Board::initGamePieces()
{
    for(int i = 0; i < 16; i++)
    {
        blackPieces.push_back(new gamePiece(true));
        whitePieces.push_back(w);
    }
    
    for(int i = 0; i < 8; i++)
    {
        
        blackPieces[i]->setPosition(i,7);
        cout << blackPieces[i]->xPos << " " << blackPieces[i]->yPos << endl;
        
        board[7].push_back(blackPieces[i]);
        
        cout << "lol " << endl;
        
        /*blackPieces[i+8].setPosition(i,6);
        board[6].push_back(&blackPieces[i+8]);
        
        whitePieces[i].setPosition(i,0);
        board[0].push_back(&whitePieces[i]);
        
        whitePieces[i+8].setPosition(i,1);
        board[1].push_back(&whitePieces[i+8]);*/
        
        cout << i << endl;
    }
    
    
    
    
    
}

void Board::printBoard()
{
    
    for(int i = 0; i < board.size(); i++)
    {
        
        
        cout << "|";
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j]->team)
                cout << "X";
            else if(!board[i][j]->team)
                cout << "O";
            else
                cout << " ";
                
                
            cout << " " << i << " " << j ;
            cout << "|";
        }
        cout << endl;
    }
    
    /*for(int i = 0; i < board.size(); i++)
    {
        
        
        cout << "|";
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j].team)
                cout << "X";
            else if(!board[i][j].team)
                cout << "O";
            else
                cout << " ";
                
                
            cout << " " << i << " " << j ;
            cout << "|";
        }
        cout << endl;
    }
    
    cout << (bool)board[7][7].team << endl; */
    
    
    
}



