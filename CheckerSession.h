/*
    Author: Sean Smith
    Date:   20/04/2012
    Class:  CheckersSession.h

    Purpose: Used to create the final gameplay
*/

#ifndef GameSuite_CheckerSession_H
#define GameSuite_CheckerSession_H

#import "CheckersBoard.h"
#import "Player.h"

enum Direction { UpLeft, UpRight, DownLeft, DownRight };
enum Turn2 {player1_turn, player2_turn};

struct Point
{
    int x;
    int y;
    Point(int xco, int yco) : x(xco), y(yco) {};
};

class CheckerSession
{
private:
    CheckersBoard board;        //Board for the game
    Player *first;              //First player
    Player *second;             //Second Player
    int scoreFirst;             //First players score
    int scoreSecond;            //Second players score
    Turn2 turn;                  //Current turn


    /* MOVES */
    bool moveFrom(int xFrom, int yFrom, int xTo, int yTo, Player *owner);           //Move Checker FROM X/Y TO X/Y
    bool moveInDirection(Direction dir, int xFrom, int yFrom, Player *owner);       //Move checker into direction
    bool canMoveInDirection(Direction dir, int xFrom, int yFrom);                   //Can move checker into direction

    /* JUMPS */
    bool canJumpOver(int xFrom, int yFrom, Direction dir);                          //Can you jump over in certain direction over opponents checker
    bool jumpOver(int xFrom, int yFrom, Direction dir, Player *player);             //Jump over in certain direction over opponnets checker

    /* HELPERS */
    Point moveCoords(int x, int y, Direction dir);                                  //Get Co-Ordinates for new movement in new direction
    bool canContinue();                                                             //Can the game continue?
    void decOponentScore(Player *player);                                           //Decrement opponents scrore
    Player* playerForTurn();                                                        //Return player for current turn.
    void changeTurn();                                                              //Change current turn
    bool validMovement(Direction dir, CheckersDisk *disk);                           //Is the direction valid for this disk?

    /* USER INTEFACE */
    Point getPoint();                                                               //Get point supplied by user
    Direction whereToMove();                                                        //Return direction where to move


public:
    CheckerSession(Player *one, Player *two) : first(one), second(two), scoreFirst(12), scoreSecond(12), turn(player1_turn) { board.initBoard(one, two) ;}
    void gameSwitch();            //Hand over the control to the game loop
};

#endif
