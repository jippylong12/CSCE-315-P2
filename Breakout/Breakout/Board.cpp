#include <string>
#include "Board.h"
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void Board::initBoard()
{
	//fill the vectors with pieces
    for(int i = 0; i < 16; i++)
    {
        blackPieces.push_back(new gamePiece(true)); //create a blackPiece because BLACK IS 1
		blackPieces[i]->taken = 0; //set alive
        whitePieces.push_back(new gamePiece(false));// createa  whitePiece BECAUSE WHITE IS 0
		whitePieces[i]->taken = 0; //set alive
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
		whitePieces[i]->setPosition(7, i); //set position
		board[7][i] = whitePieces[i]; //push back into board
    }
	for (int i = 0; i < 8; i++)
	{
		blackPieces[i]->setPosition(0, i);
		board[0][i] = blackPieces[i];
	}
	//the second eight will be on the inner rows
	for (int i = 8; i < 16; i++)
	{
		whitePieces[i]->setPosition(6, i - 8);
		board[6][i-8] = whitePieces[i];
	}
	for (int i = 8; i < 16; i++)
	{
		blackPieces[i]->setPosition(1, i - 8);
		board[1][i - 8] = blackPieces[i];
	}
}

/*RUNS THE EVALUATION FUNCTION OVER EACH OF AI'S GAME PIECES*/
void Board::runAI()
{
	double max = -100000000;
	int indexToUse = 0;
	for (int i = 0; i < 16; i++)
	{
		//PLACES OUTPUT INTO THE AIVECTOR AFTER EACH ITERATION
		if (!blackPieces[i]->taken) //if alive run theAI
		{
			AIScorevector[i] = evaluationFunction(blackPieces[i]->row, blackPieces[i]->column, i); //grabs a weight for all of the pieces in their corresponding positions
		}
		else //the piece is dead so we should make sure never to use it
		{
			AIScorevector[i] = -1000000;
		}
		
		if (max < AIScorevector[i]) //finding max
		{
			max = AIScorevector[i];
			indexToUse = i;
		}
		if (max == AIScorevector[i]) //if we find an equal one we randomly pick one
		{
			int a = rand() % 2; //randomly pick 0 or 1
			if (a)
			{
				indexToUse = indexToUse;
			}
			else
			{
				indexToUse = i;
			}
		}
	}

	char directionToMove = AIMoveVector[indexToUse];

	coordinates selctedGamePieceCoordinates(blackPieces[indexToUse]->row, blackPieces[indexToUse]->column);

	switch (directionToMove)
	{
		case 'L':
			moveLEFT(selctedGamePieceCoordinates);
			break;
		case 'F':
			moveFWD(selctedGamePieceCoordinates);
			break;
		case 'R':
			moveRIGHT(selctedGamePieceCoordinates);
			break;
		default:
			cout << "Something went wrong when moving in the AI.\n";
	}
}



bool Board::canLEFT(int row, int col)
{
	if (col == 7) {
		cout << "Illegal move: moving black left outta bounds" << endl;
		isLegalMove = 0;
		return false;
	}
	if (board[row + 1][col + 1] != NULL && board[row + 1][col + 1]->team == 1) {
		cout << "Can't move: Teammate piece in the way. " << endl;
		isLegalMove = 0;
		return false;
	}
	else
	{
		return true;
	}
}

bool Board::canFWD(int row, int col)
{

	if (board[row + 1][col] != NULL && board[row + 1][col]->team == 1) {
		cout << "Can't move: Teammate piece in the way. " << endl;
		isLegalMove = 0;
		return false;
	}
	else if (board[row + 1][col] != NULL && board[row + 1][col]->team == 0) {
		cout << "Can't move FWD, enemy piece in the way. " << endl;
		isLegalMove = 0;
		return false;
	}
	else
	{
		return true;
	}
}

bool Board::canRIGHT(int row, int col)
{
	if (col == 0) {
		cout << "Illegal move: moving black right outta bounds" << endl;
		isLegalMove = 0;
		return false;
	}
	else if (board[row + 1][col - 1] != NULL && board[row + 1][col - 1]->team == 1) {
		cout << "Can't move: Teammate piece in the way. " << endl;
		isLegalMove = 0;
		return false;
	}
	else
	{
		return true;
	}
}

//goes through the vector and finds the max and returns the index
int findMaxScoreIndex(vector<double> scoresVector)
{
	//max index is the number to return and currentMax what we will use to check for maximum
	int maxIndex = -1;
	double currentMax = -1;

	//for each index in the vector
	for (int i = 0; i < scoresVector.size(); ++i)
{
		if (currentMax < scoresVector[i]) //if there is a larger number
		{
			currentMax = scoresVector[i]; //set the new max
			maxIndex = i; //get the new location for the max number
		}
		if (currentMax == scoresVector[i]) //if we find an equal one we randomly pick one
		{
			int a = rand() % 2; //randomly pick 0 or 1
			if (a)
			{
				maxIndex = maxIndex;
			}
			else
			{
				maxIndex = i;
			}
		}
	}

	if (maxIndex == -1) //there are no possbile moves
	{
		cout << "No possible moves.!\n";
		return -1;
}
	return maxIndex;
}

double addScores(vector<double> scoresVector)
{
	double totalScore = 0;
	for (int i = 0; i < scoresVector.size(); ++i)
	{
		totalScore += scoresVector[i];
	}
	return totalScore;
}

double Board::evaluationFunction(int row, int column,int gamePieceIndex)
{
	//this vector will hold the scores which are intialized to a very low negative number so it will never get chosen
	// if that direction cannot be run
	vector<double> moveScores (6,-1000000.0); /*LEFT IS INDEX 0, MIDDLE IS INDEX 1, RIGHT IS INDEX 2*/
	


	if (canLEFT(row, column))
	{
		moveScores[0] = canBeTaken(row + 1, column + 1, 'L') + canTakePiece(row + 1, column + 1, 'L') + spacesFromWin(row + 1, column + 1);
		moveScores[3] = canTakePiece(row, column, 'L') + spacesFromWin(row, column);
	}
	if (canFWD(row, column))
	{
		moveScores[1] = canBeTaken(row + 1, column, 'M') + canTakePiece(row + 1, column, 'M') + spacesFromWin(row + 1, column);
		moveScores[4] = spacesFromWin(row, column);
	}
	if (canRIGHT(row, column))
	{

		moveScores[2] = canBeTaken(row + 1, column - 1, 'R') + canTakePiece(row + 1, column - 1, 'R') + spacesFromWin(row + 1, column - 1);
		moveScores[5] = canTakePiece(row, column, 'R') + spacesFromWin(row, column);
	}


	//find the max index
	int maxIndex = findMaxScoreIndex(moveScores);

	//depending on what our maxIndex is we will need to push_back the correct characterto indicate which direction is good to go
	switch (maxIndex) 
	{
		case 0: // the 0 index is the left direction
			AIMoveVector[gamePieceIndex] = 'L'; // so we tell the program to go left if it chooses this gamePiece
			break;
		case 1:// the 1 index is forward
			AIMoveVector[gamePieceIndex] = 'F';// so we tell the program to go forward if it chooses this gamePiece
			break;
		case 2:
			AIMoveVector[gamePieceIndex] = 'R';
			break;
		case 3: // the 0 index is the left direction
			AIMoveVector[gamePieceIndex] = 'L'; // so we tell the program to go left if it chooses this gamePiece
			break;
		case 4:// the 1 index is forward
			AIMoveVector[gamePieceIndex] = 'F';// so we tell the program to go forward if it chooses this gamePiece
			break;
		case 5:
			AIMoveVector[gamePieceIndex] = 'R';
			break;

		default:
			return -1000000.0;
	}


	return addScores(moveScores);



}

double Board::spacesFromWin(int row, int column)
{
    depth++;
    
    double left = 0, middle = 0, right = 0;
    
    if(depth < maxDepth)
    {
    	if (canLEFT(row, column))
    	{
			if (row == 7)
			{
				left = 20000;
			}
			else
			{
				left = depth*10.0;
			}
    	}
    	if (canFWD(row, column))
    	{
			if (row == 7)
			{
				middle = 20000;
			}
			else
			{
				middle = depth * 10.0;
			}
    	}
    	if (canRIGHT(row, column))
    	{
			if (row == 7)
			{
				right = 20000;
			}
			else
			{
				right = depth * 10.0;
			}
    	}
    }
	
	depth--;
	
	return left + middle + right;
}

double Board::canTakePiece(int row, int col, char direction)
{
    
     //going right in the POV of the AI gamepiece
    if (direction == 'R' && row + 1 <= 7 && col - 1 >= 0)
    {
        //Make sure there's no piece at the place.
        if (board[row + 1][col - 1] != NULL && board[row + 1][col - 1]->team == 0)
        {
            return 100000;
}
    }
    //going left in the POV of the AI gamepiece
    if (direction == 'L' && row + 1 >= 0 && col + 1 <= 7)
    {
        if (board[row + 1][col + 1] != NULL && board[row + 1][col + 1]->team == 0)
        {
            return 100000;
        }
    }

	return 0;
}

double Board::canBeTaken(int row, int col, char direction)
{
    
    //going right in the POV of the AI gamepiece
    if (direction == 'R' && row + 1 <= 7 && col - 1 >= 0)
    {
        //Make sure there's no piece at the place.
        if (board[row + 1][col - 1] != NULL && board[row + 1][col - 1]->team == 0)
        {
            return -696969;
        }
    }
    //going left in the POV of the AI gamepiece
    if (direction ==  'L' && row + 1 >= 0 && col + 1 <= 7)
    {
        if (board[row + 1][col + 1] != NULL && board[row + 1][col + 1]->team == 0)
{
            return -696969;
        }
    }
    
    //Can't be taken
    return 1000;
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
    
    if(board[row][col]==NULL){
        cout << "ILLEGAL MOVE: no gamePiece there" << endl;
        isLegalMove = 0;
        return 0;
    }
    else
    {
        
        if (board[row][col]->team){ //black
            //cout << "Moving piece at pos: " << row << ", " << col << ".  Moving black forward" << endl;
            if (board[row+1][col] != NULL && board[row+1][col]->team == 1) {
                cout << "Can't move: Teammate piece in the way. " << endl;
                isLegalMove = 0;
                return 0;
            }
            else if (board[row+1][col] != NULL && board[row+1][col]->team == 0) {
                cout << "Can't move FWD, enemy piece in the way. " << endl;
                isLegalMove = 0;
                return 0;
            }
            else{
            	saveState();
				board[row][col]->row += 1;
                board[row+1][col] = board[row][col];    //New piece foward
                board[row][col] = NULL;                     //Previous position empty
                isLegalMove = 1;  //means the move can happen
                moveDone = 1;     //movement done
                checkIfWin();
                return 1;
            }
        }
        else{                       //white
            cout << "Moving piece at pos: " << row << ", " << col << ".  Moving white forward" << endl;
            if (board[row-1][col] != NULL && board[row-1][col]->team == 0) {
                cout << "Can't move: Teammate piece in the way. " << endl;
                isLegalMove = 0;
                return 0;
            }
            else if (board[row-1][col] != NULL && board[row-1][col]->team == 1) {
                cout << "Can't move FWD, enemy piece in the way. " << endl;
                isLegalMove = 0;
                return 0;
            }
            else{
            	saveState();
				board[row][col]->row -= 1;
                board[row-1][col] = board[row][col];    //New piece foward
                board[row][col] = NULL;                      //Previous position empty
                isLegalMove = 1;  //means the move can happen
                moveDone = 1;     //set movement done
                checkIfWin();
                return 1;
            }
        }
    }
	//printBoard();
	return 0;

}

int Board::moveLEFT(coordinates curPos)
{
    int row = curPos.getRow();
    int col = curPos.getCol();
 
    
    if(board[row][col]==NULL){
        cout << "ILLEGAL MOVE: no gamePiece there" << endl;
        isLegalMove = 0;
        return 0;
    }
    else{
        if (board[row][col]->team){ //black
            //cout << "Moving piece at pos: " << row << ", " << col << ".  Moving black left" << endl;
            if (board[row+1][col+1] != NULL && board[row+1][col+1]->team == 1) {
                cout << "Can't move: Teammate piece in the way. " << endl;
                isLegalMove = 0;
                return 0;
            }
            else if (col == 7) {
                cout << "Illegal move: moving black left outta bounds" << endl;
                isLegalMove = 0;
                return 0;
            }
            else{
            	saveState();
				board[row][col]->row += 1;
				board[row][col]->column += 1;
                board[row+1][col+1] = board[row][col];    //New piece relative left
                board[row][col] = NULL;                     //Previous position empty
                isLegalMove = 1;  //means the move can happen
                moveDone = 1;     //set movement done
                checkIfWin();
                return 1;
            }
        }
        else{                       //white
             if (col == 0) {    //moving a piece out of bounds
                cout << "Illegal move: moving white left outta bounds" << endl;
                isLegalMove = 0;
                return 0;
                
            }
        
        
            //cout << "Moving piece at pos: " << row << ", " << col << ".  Moving white left" << endl;
            else if (board[row-1][col-1] != NULL && board[row-1][col-1]->team == 0) {
                cout << "Can't move: Teammate piece in the way. " << endl;
                isLegalMove = 0;
                return 0;
            }
                
            else{
            	saveState();
				board[row][col]->row -= 1;
				board[row][col]->column -= 1;
                board[row-1][col-1] = board[row][col];    //New piece left
                board[row][col] = NULL;                      //Previous position empty
                isLegalMove = 1;  //means the move can happen
                moveDone = 1;     //set movement done
                checkIfWin();
                return 1;
            }
        }
    }
	//printBoard();
	return 0;
}

int Board::moveRIGHT(coordinates curPos)
{
    int row = curPos.getRow();
    int col = curPos.getCol();
    if(board[row][col] == NULL){
        cout << "ILLEGAL MOVE: no gamePiece there" << endl;
        isLegalMove = 0;
        return 0;
    }
    else{
        if (board[row][col]->team){ //black
            //cout << "Moving piece at pos: " << row << ", " << col << ".  Moving black right" << endl;
             if (col == 0) {
                cout << "Illegal move: moving black right outta bounds" << endl;
                isLegalMove = 0;
                return 0;
            }
			else if (board[row+1][col-1] != NULL && board[row+1][col-1]->team == 1) {
                cout << "Can't move: Teammate piece in the way. " << endl;
                isLegalMove = 0;
                return 0;
            }
            
            else{
            	saveState();
				board[row][col]->row += 1;
				board[row][col]->column -= 1;
                board[row+1][col-1] = board[row][col];    //New piece right
                board[row][col] = NULL;                     //Previous position empty
                isLegalMove = 1;  //means the move can happen
                moveDone = 1;     //set movement done
                checkIfWin();
                return 1;
            }
        }
        else{                       //white
            //cout << "Moving piece at pos: " << row << ", " << col << ".  Moving white right" << endl;
            if (board[row-1][col+1] != NULL && board[row-1][col+1]->team == 0) {
                cout << "Can't move: Teammate piece in the way. " << endl;
                isLegalMove = 0;
                return 0;
            }
            else if (col == 7) {
                cout << "Illegal move: moving white right outta bounds" << endl;
                isLegalMove = 0;
                return 0;
            }
            else{
            	saveState();
				board[row][col]->row -= 1;
				board[row][col]->column += 1;
                board[row-1][col+1] = board[row][col];    //New piece right
                board[row][col] = NULL;                      //Previous position empty
                isLegalMove = 1;  //means the move can happen
                moveDone = 1;     //set movement done
                checkIfWin();
                return 1;
            }
        }
    }
	
	return 0;
}



bool Board::checkIfWin()
{
    for (int i = 0; i < 8; ++i){
        if (board[0][i] != NULL && board[0][i]->team == 0) {       //if white piece is on the black's home row (row 0)
            cout << "White wins!" << endl;
            return true;
        }
        else if (board[7][i] != NULL && board[7][i]->team == 1) {  //if a black piece is in white home (row 7)
            cout << "Black won" << endl;
            return true;
         }
        else continue;
    }
	return false;

}

void Board::randAI(){
      moveDone = 0;
      isLegalMove = 0;
      int randRow;
      int randCol;
      srand(time(0));
       while(!moveDone && !isLegalMove){    //until the AI finds a successful move
        randRow = rand() % 8; //0..7
        randCol = rand() % 8; //0..7
        coordinates randCoord(randRow, randCol);
        //cout << "AI move pos: " <<  randRow << ", "  << randCol << endl;
            if(board[randRow][randCol] != NULL && board[randRow][randCol]->team){    //move if the piece is black
                int randomMove = rand() % 3;    //take a random move
                    if (randomMove==0){
                        moveFWD(randCoord);
                    }else if (randomMove==1){
                        moveLEFT(randCoord);
                    }else{
                        moveRIGHT(randCoord);
                    }
                //cout << "moveDone: " << moveDone << " isLegalMove: " << isLegalMove << endl;
            }else if (board[randRow][randCol] == NULL){
					moveDone = 0; 
					isLegalMove = 0; 
					continue;        //move wasn't done successfully, try again
			}
			else { /*cerr << "fuck" << endl;*/}
       }


}

bool Board::isEnemy(coordinates curPos){
    
    int row = curPos.getRow();
    int col = curPos.getCol();
    if(board[row][col] != NULL && board[row][col]->team){
       return true;
    }
    else return false;
}
void Board::saveState()
{
	if (savedBoard.size() < 21)
	{
		cout<<"pushed back the current states"<<endl<<endl;
		savedBoard.push_back(board);
	}
	else
	{
		savedBoard.erase(savedBoard.begin());
		savedBoard.erase(savedBoard.begin());
		savedBoard.push_back(board);
	}
	
}

void Board::undo()
{
	if (savedBoard.size() == 0)
	{
	    cout <<endl<< "Can't undo anymore."<<endl;
	}
	else
	{
	board = savedBoard[savedBoard.size()-1];
	savedBoard.pop_back();
	//saveState();
	cout<<endl<<endl<<endl<<"UNDO BOARD: "<<endl<<endl;
	printBoard();
}

}












