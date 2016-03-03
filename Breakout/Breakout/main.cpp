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
    
    
    cout << "Enter the port number (e.g 8888): ";
    cin >> portNo;
    
    Server s(portNo);
    s.createSocket();
    //while(1)
	//{
    cout << "Marcus Is Awesome.  \n";
        
    
    
    //}
	
	
	

	

	//while(1)
	//{
		
	//}

	
	return 0;
}

