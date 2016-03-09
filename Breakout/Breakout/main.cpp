// Breakout.cpp : Defines the entry point for the console application.
//

#include <iostream>
//#include "Parser.h"
#include "Server.h"
#include <stdlib.h>
#include "Game.h"

#include <string.h>

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
	//userInputPassword = s.getMessage(); //Get the password from client
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

			//cout << "WELCOME\n";

			//s.sendMessage("WELCOME\n"); //server sends this to client
            //need game mode and difficulty
			getline(cin, userInput);
			//userInput = s.getMessage(); //gets userInput from the client
            
            if (userInput.size() > 1)
			{
				correctInput = mainGame.parse(userInput);
				//set those things
				mainGame.setDifficulty();
				if (mainGame.getDifficulty().size() < 1)
				{
					correctInput = 0;
				}
				mainGame.setGameMode();
				if (mainGame.getGameMode().size() < 1)
				{
					correctInput = 0;
				}
                userInput = "";
            }
			else
			{
				cout << "No input given\n";

               //s.sendMessage("No input given.\n");

               // s.sendMessage("No input given.\n");

			}
		}

		cout << "OK\n";
        //s.sendMessage("OK\n");  // server sends this to client
		//Start game
		mainGame.board.initGamePieces();
		mainGame.displayBoard();




		while (1)
		{

			correctInput = 0;
            bool turn = 0;
            cout << "Your turn\n";
            //s.sendMessage("Your turn\n");
			getline(cin, userInput);
			//userInput = s.getMessage();
            correctInput = mainGame.parse(userInput);
			if (correctInput)
			{
				cout << "OK\n";
				//s.sendMessage("OK\n");

            while(turn == 0 && !mainGame.board.checkIfWin()){
                
    

                if (mainGame.gameParser.contain.MOVE){  //Had this in the parser but I couldn't figure out how to update mainGame
                                                        //without putting it here
                    
                    bool turn = 0;
                    
                    

                    int row = stoi(mainGame.gameParser.contain.pieceRow); //convert row string to an int
                    string colString = mainGame.gameParser.contain.pieceColumn;
                    int col;                          //Will be the col number corresponding to A, B, C, etc
                    string moveDir = mainGame.gameParser.contain.moveDirection; //Grab move direction
                    
                    cout << "piece col " << mainGame.gameParser.contain.pieceColumn << endl;
                    if      (colString.compare("A") == 0) col = 0;
                    else if (colString.compare("B") == 0) col = 1;
                    else if (colString.compare("C") == 0) col = 2;
                    else if (colString.compare("D") == 0) col = 3;
                    else if (colString.compare("E") == 0) col = 4;
                    else if (colString.compare("F") == 0) col = 5;
                    else if (colString.compare("G") == 0) col = 6;
                    else if (colString.compare("H") == 0) col = 7;
                
                    cout << "row: " << row << " col: " << col << endl;
                    coordinates c(row,col); //piece at postion c to be moved

                    //cout << moveDir << endl;

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
                    //mainGame.board.printBoard();
                }

			
                turn = 1;
				if(mainGame.board.checkIfWin()) exit(2);
            
        
          

         }
          while(turn == 1 && !mainGame.board.checkIfWin()){
               //s.sendMessage("Ai's turn\n");
			   cout << "AI's turn" << endl;
               mainGame.board.randAI(); //run a random AI
               //s.sendMessage("AI's turn: done\n");
			   cout << "AI's turn: done" << endl;
               turn = 0;
           }
        }
        }
        }
    else
	{
		system("clear");
		cout << "Wrong Password. \n";
		main();
	}
        return 0;
    
    
    }
    

	





