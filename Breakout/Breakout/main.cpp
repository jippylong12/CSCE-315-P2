// Breakout.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Game.h"
#include "Server.h"

using namespace std;

int main()
{
	int portNo;
    
    cout << "Enter the port number (e.g 8888): ";
    cin >> portNo;
    
    Server s(portNo);
    s.createSocket();
    //while(1)
	//{
    cout << "Marcus Is Awesome.  \n";
        
    
    
    //}
	
	
	
	
	return 0;
}

