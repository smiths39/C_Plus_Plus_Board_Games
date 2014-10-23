//
//  GameBoardCell.cpp
//  GameSuite
//
//  Created by Robert Lis on 29/03/2012.
//  Copyright (c) 2012 RedFoxDev. All rights reserved.
//

#include <iostream>
#include "GameBoardCell.h"

//create new cell, set state to empty, item to NULL
GameBoardCell::GameBoardCell()
{
    state = empty;
    item = NULL;
}

//will check the value stored in variable, and return cells state
bool GameBoardCell::isOccupied() const
{
    return state != empty;
}

//Change status from empty to occupied and vice versa
void GameBoardCell::changeState()
{
    if(state == empty)
    {
        state = occupied;
    }
    else
    {
        state = empty;
    }
}

bool GameBoardCell::placeItem(Item* item)
{
    if(item == NULL)
    {
        this->item = NULL;
        state = empty;
        return true;
    }
    else if(state != occupied)
    {
        this->item = item;
        state = occupied;
        return true;
    }
    else
    {
        return false;
    }
}

Item* GameBoardCell::showItem()
{
    return item;
}
