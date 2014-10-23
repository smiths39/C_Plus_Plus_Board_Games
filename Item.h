//
//  Item.h
//  GameSuite
//
//  Created by Robert Lis on 29/03/2012.
//  Copyright (c) 2012 RedFoxDev. All rights reserved.
//
//  Base class representing any item on a board, in game suite.
//  Designed to work GameBoardCell. Location of item can be set,
//  item can also be set to non relocatable in a constructor.

#ifndef GameSuite_Item_H
#define GameSuite_Item_H

#include "Player.h"

class Item
{
private:
    int x;                  //location at board X
    int y;                  //location at board Y
    bool moveable;          //can change position?
    Player *owner;          //owner of the item
public:
    Item(int xpos = 0, int ypos = 0, bool canmove = true, Player *player = NULL) : x(xpos), y(ypos), moveable(canmove), owner(player){};
   
    //change X if canMove() == true
    virtual void setX(int x) { if(canMove()) this->x = x;} 
    
    //change Y if canMove() == true
    virtual void setY(int y) { if(canMove()) this->y = y;}  
    
    inline int getX() {return x ;}
    
    inline int getY() {return y ;}

    //true if item can change its location
    inline bool canMove()   { return moveable == true; }        
    
    //return id number of the owner if there is one, if non then -1 returned
    inline int ownedBy()    { if(owner != NULL) return owner->getId(); else return -1; }
};

#endif
