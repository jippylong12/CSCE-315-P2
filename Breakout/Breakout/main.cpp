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
	mainGame.parse(userInputPassword);
	accepted = (mainGame.getPassword() == mainGame.gameParser.contain.password);

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

               //s.sendMessage("No input given.\n");

               // s.sendMessage("No input given.\n");

			}
		}

		cout << "OK\n";
        //s.sendMessage("OK\n");  // server sends this to client
		//Start game
		mainGame.board.initBoard();


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

				if(turn == 0 && !mainGame.board.checkIfWin())
				{
                
    

					if (mainGame.gameParser.contain.MOVE){  //Had this in the parser but I couldn't figure out how to update mainGame
															//without putting it here
						bool goodMove = mainGame.gameMove(turn); 
						if (!goodMove) { continue; } //if not a good move keep going until we get one
						else turn = 1;  //else it is a good mvoe so let the AI have it's turn
					}
					
					if (mainGame.gameParser.contain.DISPLAY)
					{
						mainGame.displayBoard();
					}
			
					if (mainGame.gameParser.contain.UNDO)
					{
						cout << "Undoing... \n";
						//s.sendMessage("Undoing...\n");  //server sends this to client
						mainGame.board.undo();
						mainGame.board.undo();
						turn = 0;
						mainGame.gameParser.contain.UNDO = 0; //so we don't keep going when it's not called
					}
					
					if (mainGame.board.checkIfWin())
					{
						cout << "Play again? (Y/N)\n";
						getline(cin, userInput);
						if (userInput == "Y" || userInput == "y" ||
							userInput == "yes" || userInput == "Yes")
						{
							system("clear");
							main();
						}
						else
						{
							cout << "Thanks for playing!\n";
							exit(2);
						}
					}

					/*AI TURN*/
					if (turn == 1 && !mainGame.board.checkIfWin())
					{
						//s.sendMessage("Ai's turn\n");
						cout << "AI's turn" << endl;
						mainGame.board.runAI(); //RUN AI EVERY TURN
						//mainGame.board.randAI(); //run a random AI
												 //s.sendMessage("AI's turn: done\n");
						cout << "AI's turn: done" << endl;
						mainGame.displayBoard();
						turn = 0;

						if (mainGame.board.checkIfWin())
						{
							cout << "Play again? (Y/N)\n";
							getline(cin, userInput);
							if (userInput == "Y" || "y")
							{
								system("clear");
								main();
							}
							else
							{
								exit(2);
							}
						}
					}
					
				}
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


	





