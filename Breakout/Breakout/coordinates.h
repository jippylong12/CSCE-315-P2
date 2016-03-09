//coordinates.h
#include <vector>
#include <string>

using namespace std;

class coordinates
{
    int row;
    int col;
    
    public:
    
    coordinates(int r, int c) : row(r), col(c) {} //arg constructor
    
    int getRow()
    {
        return row;
    }
    int getCol()
    {
        return col;
    }
    void setPos(int r, int c){ row = r; col = c;}
};