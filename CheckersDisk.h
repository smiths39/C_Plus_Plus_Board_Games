/*
    Author: Sean Smith
    Date:   20/04/2012
    Class:  CheckersDisk.h
    
    Purpose: Used to specify which Player owns the Disk on the board
*/

#ifndef GameSuite_CheckersDisk_H
#define GameSuite_CheckersDisk_H

#import "Player.h"
#import "Item.h"

enum MovementDir {goingUp, goingDown};    // marks direction the piece should go

class CheckersDisk : public Item
{
private:
    bool free;
    MovementDir direction;
public:
    CheckersDisk(int x, int y, Player *master, MovementDir dir) : Item(x, y, true, master), free(false), direction(dir){};
    inline void setFree(bool val) { free = val; };
    inline bool isFree(){ return free; };
    inline MovementDir getDirection() { return direction; }
};

#endif
