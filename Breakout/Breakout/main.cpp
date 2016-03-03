// Breakout.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Game.h"


using namespace std;

int main()
{
	Game mainGame;

	while(1)
	{
		mainGame.gameParser.sendNewInput("Hello, World!;");
		cout << "Marcus Is Awesome.  \n";
	}
	
	return 0;
}

