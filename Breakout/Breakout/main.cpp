// Breakout.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Game.h"
#include "Server.h"

using namespace std;

int main()
{
	Game mainGame;
    int portNo;    
    
	/*CONNECTION FROM CLIENT TO SERVER*/

    //cout << "Enter the port number (e.g 8888): ";
    //cin >> portNo;
    
 //   Server s(portNo);
	////s.sendMessage("dsjf");
 //   s.createSocket();
	/* while(1){
		string sendToClient;
		cout << "Enter a message to send to the client: ";
		cin >> sendToClient;
		s.sendMessage(sendToClient);
		cout << endl;
		s.getMessage();	//recieve a message from the client..
	} */
	
	
	
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
		string userInput; //universal input 
		bool correctInput = 0;

		while (!correctInput)
		{
			system("clear");
			cout << "WELCOME\n";
			//need game mode and difficulty
			getline(cin, userInput);
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
			}
			else
			{
				cout << "No input given\n";
			}
		}

		cout << "OK\n";
		//Start game
		mainGame.board.initPieces
		while (1)
		{
			correctInput = 0;
			getline(cin, userInput);
			correctInput = mainGame.parse(userInput);
			if (correctInput)
			{
				cout << "OK\n";
				if (mainGame.gameParser.contain.UNDO)
				{
					cout << "Undoing... \n";
					mainGame.UNDO();
					mainGame.gameParser.contain.UNDO = 0; //so we don't keep going when it's not called
				}
				if (mainGame.gameParser.contain.DISPLAY)
				{
					mainGame.displayBoard();
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

