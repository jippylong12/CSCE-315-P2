#include "Parser.h"
#include <locale>
#include <string>

using namespace std;


Parser::Parser(string in)
{
	input = in;
	parse();
}

bool Parser::sendNewInput(string in)
{
	input = in; //give it input
	return parse(); //then tell it to do something
}

bool Parser::parse()
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
	//needed to get the last part of the input
	tokens.push(subString);

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
			tokens.pop();
		}
		else
		{

			tokens.pop();
		}
	}

	tokens = temp;

	if (isStatement()) { return true; }
	else
	{
		cout << "ILLEGAL\n";
        input = "";
		return false;
	}
}

/*We need this because the inputs are supposed to be case insensitive. It's arbitrary that I choose upper case over lower case. */
string UPPERCASE_STRING(string str)
{
	locale loc;
	string returnString;
	for (string::size_type i = 0; i<str.length(); ++i)
		returnString.push_back(std::toupper(str[i], loc));

	return returnString;
}

bool Parser::isStatement()
{
	if (isCommand()) return true;
	else if (tokens.size() < 1) return false;
	else if (isMove()) return true;
	else if (tokens.size() < 1) return false;
	else if (isComment()) return true;
	else if (tokens.size() < 1) return false;
	else if (isPassword()) return true;
	else return false;
}

bool Parser::isPassword()
{
	//if we already have a password we don't need another one
	if (contain.password.size() > 0) return false;
	//here we get the password
	contain.password = tokens.front();
	//then remove it from the queue
	tokens.pop();
	//then we return true and go back up the tree
	return true;
}
bool Parser::isCommand()
{
	if (UPPERCASE_STRING(tokens.front()).compare("DISPLAY") == 0)
	{
		contain.DISPLAY = !contain.DISPLAY; //flip the dispaly signal
		cout << "Display set to: " << contain.DISPLAY << endl;
		tokens.pop();
		return true;
	}
	else if (UPPERCASE_STRING(tokens.front()).compare("EXIT") == 0)
	{
		contain.EXIT = 1; //send signal to exit
		cout << "Exiting... \n";
		tokens.pop();
        exit(1);
		return true;
	}
	else if (UPPERCASE_STRING(tokens.front()).compare("UNDO") == 0)
	{
		contain.UNDO = 1; //send signal to undo
		tokens.pop();
		return true;
	}
	else if (UPPERCASE_STRING(tokens.front()).compare("HUMAN-AI") == 0)
	{
		contain.gameMode = UPPERCASE_STRING(tokens.front());
		tokens.pop();
		if (isDifficulty()) return true;
		else return false;
	}
	else if (UPPERCASE_STRING(tokens.front()).compare("AI-AI") == 0)
	{
		contain.gameMode = UPPERCASE_STRING(tokens.front());
		tokens.pop();
		if (!isServer()) return false;
		else if (tokens.size() < 1) return false;
		else if (!isPort()) return false;
		else if (tokens.size() < 1) return false;
		else if (!isPassword()) return false;
		else if (tokens.size() < 1) return false;
		else if (!isMyDifficulty()) return false;
		else if (tokens.size() < 1) return false;
		else if (!isOppenentDifficulty()) return false;
		else  return true;
	}
	else return false;
}

bool Parser::isMove()
{
	if (!isColumn()) return false;
	else if (!isRow()) return false;
	else if (tokens.size() < 1) return false;
	else if (!isMoveDirection()) return false;
	else    //we have a movement
    {
        contain.MOVE = 1;   //set container for move to true
        return true;
    }
}

bool Parser::isComment()
{
	//if we there is a ; then that signifies that we have a comment
	//I am not sure if there is always a space after the ; so I just check the
	//first index
	if (tokens.front()[0] == ';')
	{
		//print out the comment
		return true;
	}
	else return false;
}

bool Parser::isDifficulty()
{
	if (UPPERCASE_STRING(tokens.front()) == "EASY")
	{
		contain.difficulty = "EASY";
		tokens.pop();
		return true;
	}
	else if (UPPERCASE_STRING(tokens.front()) == "MEDIUM")
	{
		contain.difficulty = "MEDIUM";
		tokens.pop();
		return true;
	}
	else if (UPPERCASE_STRING(tokens.front()) == "HARD")
	{
		contain.difficulty = "HARD";
		tokens.pop();
		return true;
	}
	else return false;
}

bool Parser::isServer()
{
	contain.server = tokens.front(); //grab server
	tokens.pop(); //remove from queue
	return true;
}

bool Parser::isPort()
{
	contain.port = tokens.front();
	tokens.pop(); //remove from queue
	return true;
}

bool Parser::isMyDifficulty()
{
	if (isDifficulty()) return true;
	else return false;
}

bool Parser::isOppenentDifficulty()
{
	if (isDifficulty()) return true;
	else return false;
}

bool Parser::isColumn()
{
	//The input should look something like A7 FWD
	//So the temp will be A7
	//and the first index is the column
	string temp = UPPERCASE_STRING(tokens.front());
	if ((temp[0] == 'A') || (temp[0] == 'B') ||
		(temp[0] == 'C') || (temp[0] == 'D') ||
		(temp[0] == 'E') || (temp[0] == 'F') ||
		(temp[0] == 'G') || (temp[0] == 'H'))
	{
		//if we are then we have a valid column
		contain.pieceColumn = temp[0]; //so we add it
		//we will pop in isRow()
		return true;
	}
	else
	{
		return false;
	}
		
}

bool Parser::isRow()
{
	//The input should look something like A7 FWD
	//So the temp will be A7
	//and the second index is the row
	string temp = UPPERCASE_STRING(tokens.front());
	if(temp[1] == '1' || temp[1] == '2' ||
		temp[1] == '3' || temp[1] == '4' || 
		temp[1] == '5' || temp[1] == '6' || 
		temp[1] == '7' || temp[1] == '8' )
	{
		contain.pieceRow = temp[1]; //get the row
		tokens.pop(); //get rid of the A7 or whatever it is
		return true;

	}
	else
	{
		return false;
	}
}

bool Parser::isMoveDirection()
{
	if (UPPERCASE_STRING(tokens.front()) == "FWD")
	{
		contain.moveDirection = UPPERCASE_STRING(tokens.front());
		tokens.pop();
		return true;
	}
	else if (UPPERCASE_STRING(tokens.front()) == "RIGHT")
	{
		contain.moveDirection = UPPERCASE_STRING(tokens.front());
		tokens.pop();
		return true;
	}
	else if (UPPERCASE_STRING(tokens.front()) == "LEFT")
	{
		contain.moveDirection = UPPERCASE_STRING(tokens.front());
		tokens.pop();
		return true;
	}
	else
	{
		return false;
	}
}