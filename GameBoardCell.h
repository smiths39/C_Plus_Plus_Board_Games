//
//  GameBoardCell.h
//  GameSuite
//
//  Created by Robert Lis on 29/03/2012.
//  Copyright (c) 2012 RedFoxDev. All rights reserved.
//
//  Base class for board cell for all board games in the game suide.
//  Sublass for more specific use. Use item variable to store any kind
//  of item on a cell. Use state to switch between empty/occupied. 
//  After constructor call, state == empty.

#ifndef GameSuite_GameBoardCell_H
#define GameSuite_GameBoardCell_H

#import "Item.h"

enum State {empty, occupied, fillable};               //enumeration representing two states of cell

class GameBoardCell
{
private:
    State state;                            //state of the cell
    Item* item;                             //object item, representing item on this cell
public:
    GameBoardCell();                       //constructor with defauts, used by array constructors
    bool isOccupied() const;               //check if cell is occupied
    void changeState();                    //switch state of the cell
    virtual bool placeItem(Item*);         //place new item on the cell. Object is COPIED. Pass NULL to remove item.
    Item* showItem();                      //return item placed on the cell. Generic cell, no way of telling what the item is gonna be.
};

#endif
