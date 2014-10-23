

#ifndef GameSuite_SnakeLadderCell_H
#define GameSuite_SnakeLadderCell_H

#import "GameBoardCell.h"

class SnakeLadderCell : public GameBoardCell
{
private:
    SnakeLadderCell *destination;      //if it is special, sideOwner points to owner
    bool snake_ladder;
    Item *secondItem;
public:
    SnakeLadderCell() : GameBoardCell() { destination = NULL; snake_ladder = false; }        // *** NOTE: not sure of purpose
    bool placeItem( Item* );    
    void setDestination(SnakeLadderCell *cell) { destination = cell; snake_ladder = true;}
    inline bool isSpecial() { return snake_ladder ;}
    Item* getItemForPlayer(Player *player);
    bool hasItemForPlayer(Player *player);
    bool isEmpty() { return secondItem == NULL && isOccupied();}
};


#endif




