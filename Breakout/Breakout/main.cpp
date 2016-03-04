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
    mainGame.gameParser.sendNewInput("Hello, World!;");
    cout << "Marcus Is Awesome.  \n";
    
    
	/*CONNECTION FROM CLIENT TO SERVER*/

    //cout << "Enter the port number (e.g 8888): ";
    //cin >> portNo;
    
    //Server s(portNo);
    //s.createSocket();

	/*INITIAL SET UP OF GAME*/
	//get access
	string userInputPassword;
	int accepted = 1; //0 is true anything else is false
	cout << "PASSWORD\n";
	cin >> userInputPassword;
	accepted = userInputPassword.compare(mainGame.getPassword());

	if (!accepted)
	{
		/*PLAY GAME USING SETTINGS*/
		//get difficulty
		string userInput; //universal input 
		cout << "WELCOME\n";
		
		while (1)
		{
			cin >> userInput;
			mainGame.gameParser.sendNewInput(userInput);
			
		}
	}
	else
	{
		cout << "Wrong Password. \n";
	}

	
	return 0;
}

