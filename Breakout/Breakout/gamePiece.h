#include <string>

using namespace std;

class gamePiece
{
public:
	bool team; //black 0 white 1
	bool taken;// 0 is alive, 1 is dead

	int xPos, yPos;
	//vector < coordinates > possibleMovements;	//has a vector of s.  Each  consists of a row and col.
	//coordinates currentPossition;
	
	gamePiece(bool t){team = t;}
	void setPosition(int x, int y){xPos = x; yPos = y;}
};