// Breakout.cpp : Defines the entry point for the console application.
//

#include <iostream>
//#include "Parser.h"
#include "Server.h"
#include <stdlib.h>
#include "Game.h"
using namespace std;


int main()
{
    Game mainGame;
    int portNo;    
    
	/*CONNECTION FROM CLIENT TO SERVER*/

    //cout << "Enter the port number (e.g 8888): ";
    //cin >> portNo;
    //Server s(portNo);
	//s.sendMessage("dsjf");
    //s.createSocket();
	
	
	/*INITIAL SET UP OF GAME*/
	//get access
	
	
	
	string userInputPassword;
	int accepted = 1; //0 is true anything else is false
		
	
    //s.sendMessage("PASSWORD\n");	//Server requests a password
	cout << "PASSWORD\n";
	getline(cin,userInputPassword);
	//userInputPassword = s.getMessage();//Get the password
	accepted = mainGame.parse(userInputPassword);



	if (accepted)
	{
		/*PLAY GAME USING SETTINGS*/
		//get difficulty
		string userInput = ""; //universal input
		bool correctInput = 0;

		while (!correctInput)
		{
			system("clear");
			cout << "WELCOME\n";
			//s.sendMessage("WELCOME\n"); //server sends this to client
            //need game mode and difficulty
			getline(cin, userInput);
			//userInput = s.getMessage(); //gets userInput from the client
            
            if (userInput.size() > 1)
			{
				correctInput = mainGame.parse(userInput);
				//set those things
				mainGame.setDifficulty();
				//if we don't have naything for the difficulty it's not correct input
				if (mainGame.getDifficulty().size() < 1)
				{
					correctInput = 0;
				}
				mainGame.setGameMode();
				//if we don't have naything for the gameMode it's not correct input
				if (mainGame.getGameMode().size() < 1)
				{
					correctInput = 0;
				}
                userInput = ""; //reset
            }
			else
			{
				cout << "No input given\n";
               // s.sendMessage("No input given.\n");
			}
		}

		cout << "OK\n";
        //s.sendMessage("OK\n");  // server sends this to client
		//Start game
		mainGame.board.initGamePieces();
		bool turn = 1; //white piece goes first

		while (1)
		{
			correctInput = 0;
			getline(cin, userInput);
			//userInput = s.getMessage();
            correctInput = mainGame.parse(userInput);
			if (correctInput)
			{
				cout << "OK\n";
				//s.sendMessage("OK\n");
                if (mainGame.gameParser.contain.MOVE){  //Had this in the parser but I couldn't figure out how to update mainGame
                                                        //without putting it here
                    
                    int row = stoi(mainGame.gameParser.contain.pieceRow); //convert row string to an int
                    string colString = mainGame.gameParser.contain.pieceColumn;
                    string moveDir = mainGame.gameParser.contain.moveDirection; //Grab move direction
                    
                    cout << "piece col " << mainGame.gameParser.contain.pieceColumn << endl;
					
					//convert the Column from a to a number in the vector
					int col;                          //Will be the col number corresponding to A, B, C, etc
					col = mainGame.convertCol(colString);

                
                    cout << "row: " << row << " col: " << col << endl;
                    coordinates c(row,col); //piece at postion c to be moved

                    if (moveDir.compare("FWD") == 0) mainGame.board.moveFWD(c);
                    else if (moveDir.compare("LEFT") == 0) mainGame.board.moveLEFT(c);
                    else mainGame.board.moveRIGHT(c);
                
                
                }
                if (mainGame.gameParser.contain.UNDO)
				{
					cout << "Undoing... \n";
					//s.sendMessage("Undoing...\n");  //server sends this to client
                    mainGame.UNDO();
					mainGame.gameParser.contain.UNDO = 0; //so we don't keep going when it's not called
				}
				if (mainGame.gameParser.contain.DISPLAY)
				{
					mainGame.displayBoard();
                }
				turn = !turn; //change turn
			}			
		}
	}

	//We enter the wrong password so go back to the main screen
	else
	{
		system("clear");
		cout << "Wrong Password. \n";
		main();
	}

	
	return 0;
}

