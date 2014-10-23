/*
    Author: Sean Smith
    Date:   20/04/2012
    Class:  CheckersCell.h

*/


#ifndef GameSuite_CheckersCell_H
#define GameSuite_CheckersCell_H

#import "GameBoardCell.h"

class CheckersCell : public GameBoardCell
{
private:
    bool special;           //is it one of the special sides
    Player *king;      //if it is special, sideOwner points to owner
public:
    CheckersCell(Player *owner = NULL, bool isSpecial = false) : king(owner), special(isSpecial){};
    bool placeItem(Item*);
    inline void setSpecialCell(bool val) { special = val; }
    inline void changeValueState(Player *owner) { king = owner; }
};


#endif
