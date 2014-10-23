//
//  ConnectFourSession.h
//  GameSuite
//
//  Created by Robert Lis on 03/04/2012.
//  Copyright (c) 2012 RedFoxDev All rights reserved.
//

#ifndef GameSuite_ConnectFourSession_H 
#define GameSuite_ConnectFourSession_H 

#include "ConnectFourBoard.h"
#include "Player.h"

enum Turn {player_oneTurn, player_twoTurn};

class ConnectFourSession
{
private:
    ConnectFourBoard board;
    Player *first;
    Player *second;
    Turn turn;
    
public:
    ConnectFourSession(Player *one, Player *two) : first(one), second(two), turn(player_oneTurn) {};
    void gameLoop();            //Hand over the control to the game loop
    bool canContinue();         //Is the board filled already?
    void changeTurns();         //Change turn
    Player* playerForTurn();    //Get player for current turn
    int getColumn();
    
};

#endif
