
#include "SnakeLadderCell.h"

bool SnakeLadderCell::placeItem(Item *item)
{
    if(snake_ladder && destination != NULL)              // if SNAKE or LADDER on board is special
    {
        return destination->placeItem(item);            // return "free" value on disk (stating that it is a special cell)
    }
    else
    {
        if(showItem() == NULL)
        {
            return GameBoardCell::placeItem(item);
        }
        else if(secondItem == NULL)
        {
            secondItem = item;
        }
        
        return false;
    }
}

Item* SnakeLadderCell::getItemForPlayer(Player *player)
{
    if(isOccupied() && showItem()->ownedBy() == player->getId())
    {
        return showItem();
    }
    else if(secondItem != NULL && secondItem->ownedBy() == player->getId())
    {
        return secondItem;
    }
    else
    {
        return NULL;
    }
}

bool SnakeLadderCell::hasItemForPlayer(Player *player)
{
    if(isOccupied() && showItem()->ownedBy() == player->getId())
    {
        return true;
    }
    else if(secondItem != NULL && secondItem->ownedBy() == player->getId())
    {
        return true;
    }
    else
    {
        return false;
    }
        
}