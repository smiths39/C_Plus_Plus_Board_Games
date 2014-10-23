//
//  ConnectFourBoard.h
//  GameSuite
//
//  Created by Robert Lis on 30/03/2012.
//  Copyright (c) 2012 RedFoxDev. All rights reserved.
//

#ifndef GameSuite_ConnectFourBoard_H
#define GameSuite_ConnectFourBoard_H

#include "GameBoard.h"
#include "Player.h"

#define CONN4_BOARD_DEF_HEIGHT 7
#define CONN4_BOARD_DEF_WIDTH 6

enum BoardState {emptyBoard, fillableBoard, filledBoard};
enum Direction1 {up, down, left_, right_, upLeft, upRight, downLeft, downRight};

class ConnectFourBoard : public GameBoard<GameBoardCell>
{
private:
    int occupied;                                           //number of occupied cells
    int occupiedLimit;                                      //maximum number of occupied cells
    BoardState state;
    bool traverseInDirection(int x, int y, int forId, Direction1 dir, int steppesLeft);

public:
    ConnectFourBoard(int height = CONN4_BOARD_DEF_HEIGHT, int width = CONN4_BOARD_DEF_WIDTH) : GameBoard<GameBoardCell>(height, width) , occupied(0) , occupiedLimit(height * width){};
    bool dropAt(int column, Player *owner);
    void printInConsole();
    bool checkForConnectionAt(int x, int y, int playerID);    //Check if there exists connection of four disks from X/Y for player with playerID.
    int firstRowOccupiedAt(int column);
    bool getState() { return state; }
};




#endif
