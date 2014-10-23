/*
    Author: Sean Smith
    Date:   20/04/2012
    Class:  CheckerSession.cpp

    Purpose: Used to create the final gameplay
*/

#include <iostream>
#include <conio.h>
#include "CheckerSession.h"
#include "GameBoard.h"
#include "CheckersBoard.h"

using namespace std;

//Move checker owned by player, from X/Y to X/Y, provided its legal.
bool CheckerSession::moveFrom(int xFrom, int yFrom, int xTo, int yTo, Player *owner)
{
    //if board is occupied at FROM location, and the item belongs to the player, and TO location fits on board and its free.
    if(board.isOccupiedAt(xFrom, yFrom) && board.getItemAt(xFrom, yFrom)->ownedBy() == owner->getId() && board.fitsOnBoard(xTo, yTo) && !board.isOccupiedAt(xTo, yTo))
    {
        bool result = board.placeItemAt(xTo, yTo, board.getItemAt(xFrom, yFrom));
        if(result == true)
        {
            board.placeItemAt(xFrom, yFrom, NULL);
            board.getItemAt(xTo, yTo)->setX(xTo);
            board.getItemAt(xTo, yTo)->setY(yTo);
        }
        return result;
    }
    else
    {
        return false;
    }
}

//Move checker owned by player form X/Y into specified direction
bool CheckerSession::moveInDirection(Direction dir, int xFrom, int yFrom, Player *owner)
{
    Point p = moveCoords(xFrom, yFrom, dir);
    return moveFrom(xFrom, yFrom, p.x, p.y, owner);
}

//Can you move checker from X/Y into a specified direction
bool CheckerSession::canMoveInDirection(Direction dir, int xFrom, int yFrom)
{
    Point oneStep = moveCoords(xFrom, yFrom, dir);

    //if board is occupied at X/Y and destination location is not occupied
    if(board.isOccupiedAt(xFrom, yFrom) && !board.isOccupiedAt(oneStep.x, oneStep.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Is there checker placed in our way, and theres free space at its back, where we can jump to.
bool CheckerSession::canJumpOver(int xFrom, int yFrom, Direction dir)
{
    //Get points for movement into direction, two steps.
    Point oneStep = moveCoords(xFrom, yFrom, dir);
    Point twoStep = moveCoords(oneStep.x, oneStep.y, dir);

    //If both steppes of the jump fit on board, at first step there must be a checker and at second there must be nothing
    if(board.fitsOnBoard(oneStep.x, oneStep.y) && board.fitsOnBoard(twoStep.x, twoStep.y) && board.isOccupiedAt(xFrom, yFrom) && board.isOccupiedAt(oneStep.x, oneStep.y) && !board.isOccupiedAt(twoStep.x, twoStep.y))
    {
        return board.getItemAt(xFrom, yFrom)->ownedBy() != board.getItemAt(oneStep.x, oneStep.y)->ownedBy();
    }
    else
    {
        return false;
    }
}

//Jump over into direction
bool CheckerSession::jumpOver(int xFrom, int yFrom, Direction dir, Player *player)
{
    if(canJumpOver(xFrom, yFrom, dir))
    {
        Point oneStep = moveCoords(xFrom, yFrom, dir);
        Point twoStep = moveCoords(oneStep.x, oneStep.y, dir);
        moveFrom(xFrom, yFrom, twoStep.x, twoStep.y, player);
        board.placeItemAt(oneStep.x, oneStep.y, NULL);
        decOponentScore(player);
        return true;
    }
    else
    {
        return false;
    }
}

/* HELPERS */

//Create point stuct with points moved into a new location
Point CheckerSession::moveCoords(int x, int y, Direction dir)
{
    switch (dir)
    {
        case UpLeft:
            return Point(--x, ++y);
            break;

        case UpRight:
            return Point(++x, ++y);
            break;

        case DownRight:
            return Point(++x, --y);
            break;

        case DownLeft:
            return Point(--x, --y);
            break;
    }

    return Point(0, 0);
}

//Can the game continue
bool CheckerSession::canContinue()
{
    return scoreFirst != 0 && scoreSecond != 0;
}

//Decrement score of the OPPOSITE player
void CheckerSession::decOponentScore(Player *player)
{
    if(player->getId() == 0)
    {
        scoreSecond--;
    }
    else
    {
        scoreFirst--;
    }
}


//Is the direction valid for this disk?
bool CheckerSession::validMovement(Direction dir, CheckersDisk *disk)
{
    if(!disk->isFree())
    {
        Point oneStep = moveCoords(disk->getX(), disk->getY(), dir);

        if((disk->getDirection() == goingUp && oneStep.y <= disk->getY()) || (disk->getDirection() == goingDown && oneStep.y >= disk->getY()))
        {
            return false;
        }
        else
        {
            return true;
        }

    }
    else
    {
        return true;
    }
}

/* USER INTEFACE */
Point CheckerSession::getPoint()
{
    //Keep asking for a point as long as the one supplied is off the board, X/Y is empty, or checker at X/T does not belong to player
    int x;
    int y;

    do
    {
        cout << playerForTurn()->getName()  << ", please enter (X, Y) coordinates of the checker: ";
        cin >> x;
        cin >> y;
    }
    while(!board.fitsOnBoard(x, y) || !board.isOccupiedAt(x, y) || board.getItemAt(x, y)->ownedBy() != playerForTurn()->getId());

    return Point(x, y);
}

Direction CheckerSession::whereToMove()
{
    int answer;

    while(answer < 1 || answer > 4 )
    {
        cout << "Enter (arrow keys) : UP and LEFT : UP and RIGHT : DOWN and LEFT : DOWN and RIGHT " << endl;

        char ch1, ch2, ch3, ch4;

        ch1 = getch();
        ch2 = getch();
        ch3 = getch();
        ch4 = getch();

        if((int(ch1) == -32 && int(ch2) == 72) && (int(ch3) == -32 && int(ch4) == 75)) // up and left
        {
              answer = 1;
        }
        else if((int(ch1) == -32 && int(ch2) == 72) && (int(ch3) == -32 && int(ch4) == 77)) // up and right
        {
              answer = 2;
        }
        else if((int(ch1) == -32 && int(ch2) == 80) && (int(ch3) == -32 && int(ch4) == 75))// down and left
        {
              answer = 3;
        }
        else if((int(ch1) == -32 && int(ch2) == 80) && (int(ch3) == -32 && int(ch4) == 77)) // down and right
        {
             answer = 4;
        }
    }

    return Direction(--answer);
}

Player* CheckerSession::playerForTurn()
{
    if(turn == player1_turn)
    {
        return first;
    }
    else
    {
        return second;
    }
}

void CheckerSession::changeTurn()
{
    if(turn == player1_turn)
    {
        turn = player2_turn;
    }
    else
    {
        turn = player1_turn;
    }
}

void CheckerSession::gameSwitch()
{
    while(canContinue())
    {
        board.displayBoard();
        Player *current = playerForTurn();
        Point at = getPoint();
        cout << "";
        Direction dir = whereToMove();

        while(!validMovement(dir, (CheckersDisk *) board.getItemAt(at.x, at.y)))
        {
            cout << "Cant move in that direction, try again" << endl;
            dir = whereToMove();
        }

        cout << "";

        if(canJumpOver(at.x, at.y, dir))
        {
            //if successfully jumped then change turn
            if(jumpOver(at.x, at.y, dir, current))
            {
                changeTurn();
            }
        }
        else if(canMoveInDirection(dir, at.x, at.y))
        {
            //if successfully moved then change turn
            if(moveInDirection(dir, at.x, at.y, current))
            {
                changeTurn();
            }
        }
        system("cls");
    }
}
































