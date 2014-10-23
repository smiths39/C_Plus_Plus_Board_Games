/*
    Author: Sean Smith
    Date:   20/04/2012
    Class:  CheckersBoard.h
    
    Purpose: Used to create the game board for checkers
             Initializes rules invoked upon game
*/

#ifndef GameSuite_CheckersBoard_H
#define GameSuite_CheckersBoard_H

#include "CheckersCell.h"
#include "GameBoard.h"
#include "Player.h"
#include "CheckersDisk.h"

#define CHECKERS_DEF_WIDTH 8
#define CHECKERS_DEF_HEIGHT 8

enum boardCondition {Upper, Lower};

class CheckersBoard : public GameBoard<CheckersCell>            
{
private:
    //Given a player and a side of the board, init checkers.
    void initForPlayer(Player *player, boardCondition condition);
              
public:
    CheckersBoard(int height = CHECKERS_DEF_HEIGHT, int width = CHECKERS_DEF_WIDTH) : GameBoard<CheckersCell>(height, width) {};
    void initBoard(Player *player1, Player *player2);
    void displayBoard();
};

#endif
