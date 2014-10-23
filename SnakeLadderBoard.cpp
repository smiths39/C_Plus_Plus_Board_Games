#include "SnakeLadderBoard.h"

#define NUM_OF_LADDERS 10

bool SnakeLadderBoard::canAccept(int x, int y)
{
    if((x == 0 && y == 0) || (x == 0 && y == 99) || getCell(x, y)->isSpecial())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void SnakeLadderBoard::initBoard()
{
    srand((unsigned) time(0));
    
    for(int i = 0; i < 9; i++)
    {
        int xTo;
        int yTo;
        int xFrom;
        int yFrom;
        
        do
        {
            xTo = rand() % 9 + 1;
            yTo = rand() % 9 + 1;
            xFrom = rand() % 9 + 1;
            yFrom = rand() % 9 + 1;
        }
        while((xFrom == xTo && yFrom == yTo) || !canAccept(xTo, yTo) || !canAccept(xFrom, yFrom));
        getCell(xFrom, yFrom)->setDestination(getCell(xTo, yTo));
    }
}

bool SnakeLadderBoard::placeItemAt(int x, int y, Item* item)
{
    if(fitsOnBoard(x, y))
    {
        getCell(x, y)->placeItem(item);
        return true;
    }
    else
    {
        return false;
    }
}









