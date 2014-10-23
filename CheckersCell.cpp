/*
    Author: Sean Smith
    Date:   20/04/2012
    Class:  CheckersCell.cpp

    Purpose: Used to implement the methods
*/

#include "CheckersCell.h"
#include "CheckersDisk.h"

bool CheckersCell::placeItem(Item *item)
{
    if(special == true && item != NULL && king != NULL && king->getId() != item->ownedBy())                  // if is a special cell
    {
        CheckersDisk *disk = (CheckersDisk *) item;     // disk for the board
        disk->setFree(true);                            // boolean value "free" = true
        return GameBoardCell::placeItem(disk);          // return "free" value on disk (stating that it is a special cell)
    }
    else
    {
        return GameBoardCell::placeItem(item);          // return a normal cell
    }
}
