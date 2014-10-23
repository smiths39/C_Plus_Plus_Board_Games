//
//  ConnectFourSession.cpp
//  GameSuite
//
//  Created by Robert Lis on 03/04/2012.
//  Copyright (c) 2012 RedFoxDev. All rights reserved.
//

#include <iostream>
#include "ConnectFourSession.h"
#include "ConnectFourBoard.h"
 
using namespace std;

bool ConnectFourSession::canContinue()
{
    return board.getState() != filledBoard;
}

void ConnectFourSession::changeTurns()
{
    if(turn == player_oneTurn)
    {
        turn = player_twoTurn;
    }
    else
    {
        turn = player_oneTurn;
    }
}

Player* ConnectFourSession::playerForTurn()
{
    if(turn == player_oneTurn)
    {
        return first;
    }
    else
    {
        return second;
    }
}

int ConnectFourSession::getColumn()
{
    int dropColumn;
    cout << playerForTurn()->getName() << ", please enter a column: ";
    cin >> dropColumn;
    
    while(board.isOccupiedAt(dropColumn, board.getHeight() - 1))
    {
        cout << " can't place disk there" << endl;
    }
    
    return dropColumn;
}

void ConnectFourSession::gameLoop()
{    
    while (canContinue())
    {
        board.printInConsole();
        int dropAt = getColumn();
        
        if(board.dropAt(dropAt, playerForTurn()))
        {
            if(board.checkForConnectionAt(dropAt, board.firstRowOccupiedAt(dropAt), playerForTurn()->getId()))
            {
                cout << playerForTurn()->getName()<< "is a winner" << endl;
                board.printInConsole();
                break;
            }
        }
        
        system("cls");
        changeTurns();
    }
}
