//
//  ConnectFourBoard.cpp
//  GameSuite
//
//  Created by Robert Lis on 30/03/2012.
//  Copyright (c) 2012 RedFoxDev. All rights reserved.
//

#include "ConnectFourBoard.h"
#include "GameBoard.h"
#include <iostream>

using namespace std;

bool ConnectFourBoard::dropAt(int column, Player *player)
{
    if(column >= 0 && column < getWidth() && occupied != occupiedLimit) //if column requested is not out of range and board is not full
    {
        for(int row = 0; row < getHeight(); row++)                      //traverse down the board, look for free spot, try to place a disc at that position, return sucess/faliure.
        {
            if(!GameBoard<GameBoardCell>::isOccupiedAt(column, row))   //if we are not at an occupied cell
            {
                Item *disk = new Item(column, row, false, player);
                placeItemAt(column, row, disk);                         //place item at col/row
                if(occupied == 0)
                {
                    state = fillableBoard;                              //change state of the board
                }

                occupied++;                                             //incrase amount of cells occupied

                if(occupied == occupiedLimit)                           //check if we have reached the limit of maximum cells allowd
                {
                    state = filledBoard;                                //if so change state of the board to filled
                }

                return true;                                            //return success at adding disk to the board
            }
        }
    }

    return false;                                                       //Only to keep the compiler happy with a return
}

void ConnectFourBoard::printInConsole()                                 //Print row by row, from top to bottom
{
    for(int i = 0; i < getWidth(); i++)
    {
        cout << "  " << i << "  ";
    }

    cout << endl;
    for(int row = getHeight() - 1; row >= 0; row--)
    {
        for (int column = 0; column < getWidth(); column++)
        {
            if(isOccupiedAt(column, row))
            {
                Item *disk = getItemAt(column, row);

                if(disk->ownedBy() == 0)
                {
                    cout << "[ R ]";    // Player 1
                }
                else if(disk->ownedBy() == 1)
                {
                    cout << "[ S ]";    // Player 2
                }
            }
            else
            {
                cout << "[   ]";
            }
        }

        cout << "" << endl;
    }
}

//Int X location, Y Location, Player ID for which to check connection, Direction which to follow, stepps left.
bool ConnectFourBoard::traverseInDirection(int x, int y, int forId, Direction1 dir, int steppesLeft)
{
    if(fitsOnBoard(x, y))
    {
        if(!isOccupiedAt(x, y)) return false;
        Item *disk = getItemAt(x, y);
        if(disk->ownedBy() != forId) return false;
        else if(steppesLeft == 0) return true;

        switch (dir)
        {
            case up:
                return traverseInDirection(x, ++y, forId, dir, --steppesLeft);
                break;

            case down:
                return traverseInDirection(x, --y, forId, dir, --steppesLeft);
                break;

            case left_:
                return traverseInDirection(--x, y, forId, dir, --steppesLeft);
                break;

            case right_:
                return traverseInDirection(++x, y, forId, dir, --steppesLeft);
                break;

            case upLeft:
                return traverseInDirection(--x, ++y, forId, dir, --steppesLeft);
                break;

            case upRight:
                return traverseInDirection(++x, ++y, forId, dir, --steppesLeft);
                break;

            case downLeft:
                return traverseInDirection(--x, --y, forId, dir, --steppesLeft);
                break;

            case downRight:
                return traverseInDirection(++x, --y, forId, dir, --steppesLeft);
                break;
        }
    }

    return false;
}


bool ConnectFourBoard::checkForConnectionAt(int x, int y, int playerID)
{
    for(int i = 0; i < 8; i++)
    {
        if(traverseInDirection(x, y, playerID, Direction1(i), 3)) return true;
    }

    return false;
}

int ConnectFourBoard::firstRowOccupiedAt(int column)
{
    for(int i = getHeight(); i >= 0; i--)
    {
        if(isOccupiedAt(column, i))
        {
            return i;
        }
    }

    return getHeight() - 1;
}












