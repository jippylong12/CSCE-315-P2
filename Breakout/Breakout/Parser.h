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

	/*CLASS FUNCTIONS*/
	bool parse();
	bool sendNewInput(string);
	string getInput() { return input; }

	/*CONTAINER FOR PARSER*/
	Container contain;

	/*PARSER FUNCTIONS*/
	bool isStatement();
	bool isPassword();
	bool isCommand();
	bool isMove();
	bool isComment();
	bool isDifficulty();
	bool isServer();
	bool isPort();
	bool isMyDifficulty();
	bool isOppenentDifficulty();
	bool isColumn();
	bool isRow();
	bool isMoveDirection();
};