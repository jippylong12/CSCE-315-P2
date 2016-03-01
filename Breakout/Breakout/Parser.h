#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>
#include "Container.h"
using namespace std;

class Parser
{
	string input;
	queue<string> tokens;
	bool parsedCorrect = false;

public:
	Parser(string); //constructor
	Parser() { input = ""; } //default

							 //Parser functions
	void parse();
	void sendNewInput(string);
	string getInput() { return input; }

	Container contain;

};