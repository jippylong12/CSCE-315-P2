#include "Parser.h"
#include <string>

using namespace std;


Parser::Parser(string in)
{
	input = in;
	parse();
}

void Parser::sendNewInput(string in)
{
	input = in; //give it input
	parse(); //then tell it to do something
}

void Parser::parse()
{
	int stringCount = 0;
	int splitStart = 0;
	int splitEnd = 0;
	string subString;

	char * cstring = new char[input.length() + 1];
	strcpy(cstring, input.c_str());

	//	was needed because show wasn't popping off tokens. 	
	while (tokens.size() > 0)
	{
		tokens.pop();
	}


	istringstream iss(cstring);
	while (iss.get() != -1)
	{
		if (input[stringCount] == ' ' || input[stringCount] == '('
			|| input[stringCount] == ')' || input[stringCount] == ',' || input[stringCount] == ';')
		{
			if (input[stringCount] != ' ')
			{
				if (subString != "")
				{
					tokens.push(subString);
				}
				subString = input[stringCount];
				tokens.push(subString);
				subString = "";
			}
			else
			{
				tokens.push(subString);
				subString = "";
			}

		}
		else
		{
			subString.push_back(input[stringCount]);
		}
		++stringCount;
	}

	queue<string> temp;
	int tokenSize = tokens.size();
	for (int i = 0; i<tokenSize; ++i)
	{

		while (tokens.front()[0] == '"' && tokens.front()[tokens.front().size() - 1] != '"') //remove quotations
		{

			string literal = tokens.front();
			tokens.pop();
			tokens.front() = literal + " " + tokens.front();
			tokenSize--;

		}
		if (tokens.front()[0] == '"' && tokens.front()[tokens.front().size() - 1] == '"')
		{

			tokens.front().erase(tokens.front().begin()); //remove first quotation
			tokens.front().pop_back(); //gets rid of last quotation
		}
		if (tokens.front().compare(", ") == 0)
		{
			temp.push(",");
			tokens.pop();

		}
		else if (tokens.front() != "")
		{
			temp.push(tokens.front());
			cout << tokens.front() << endl;
			tokens.pop();
		}
		else
		{

			tokens.pop();
		}
	}

	tokens = temp;

	if (isStatement()) {}
	else
	{
		cout << "Error: Command or Query not found!" << endl;
	}
}


bool Parser::isStatement()
{
	if (isPassword()) return true;
	else if (isCommand()) return true;
	else if (isMove()) return true;
	else if (isComment()) return true;
	else return false;
}

bool Parser::isPassword()
{
	//here we get the password
	contain.password = tokens.front();
	//then remove it from the queue
	tokens.pop();
	//then we return true and go back up the tree
	return true;
}
bool Parser::isCommand()
{

}

bool Parser::isMove()
{

}

bool Parser::isComment()
{

}

bool Parser::isDifficulty()
{

}

bool Parser::isServer()
{

}

bool Parser::isPort()
{

}

bool Parser::isMyDifficulty()
{

}

bool Parser::isOppenentDifficulty()
{

}

bool Parser::isColumn()
{

}

bool Parser::isRow()
{

}

bool Parser::isMoveDirection()
{

}