#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "SnakeLadderSession.h"
#include "GameBoard.h"
#include "SnakeLadderBoard.h"

using namespace std;

bool SnakeLadderSession::canContinue()
{
    if(tokenPlayer1->getX() == 0 && tokenPlayer1->getY() == 99)
    {
        return false;
    }
    else if(tokenPlayer2->getX() == 0 && tokenPlayer2->getY() == 99)
    {
        return false;
    }
    {
        return true;
    }
}

Player* SnakeLadderSession::playerForTurn()
{
     if(turn == player1turn)
     {
             return first;  // first player
     }
     else
     {
             return second; // second player
     }
}

Item* SnakeLadderSession::tokenForPlayer(Player *player)
{
    if(player->getId() == tokenPlayer1->ownedBy())
    {
        return tokenPlayer1;
    }
    else
    {
        return tokenPlayer2;
    }
}

void SnakeLadderSession::changeTurn()
{
     if(turn == player1turn)
     {
             turn = player2turn;     // swap game control
     }
     else
     {
             turn = player1turn;
     }
}

int SnakeLadderSession::dice()
{
    srand((unsigned) time(0));
    return rand() % 6 + 1;
}

void SnakeLadderSession::setProperXY(int x, int y)
{
    if(board.isOccupiedAt(x, y))
    {
        board.getCell(x, y)->getItemForPlayer(playerForTurn())->setY(y);
        board.getCell(x, y)->getItemForPlayer(playerForTurn())->setX(x);
    }
}

void SnakeLadderSession::printInConsole()                                 //Print row by row, from top to bottom
{
    for(int row = board.getHeight()-1; row >= 0; row--)                  // top row to bottom
    {
        cout << " " << row << " ";                                      // print row numbers   
        
        for (int column = 0; column < board.getWidth(); column++)       // left column to right
        {
            Item *item1 = board.getCell(column, row)->getItemForPlayer(first);
            Item *item2 = board.getCell(column, row)->getItemForPlayer(second);
            
            if(board.getCell(column, row)->isEmpty())                               // if a cell is occupied by an item
            {
                if(item1 != NULL && item2 != NULL)
                {
                    cout << "[ X ]";
                }
                if(item1 != NULL)          // Player 1
                {
                    cout << " [ "<< first->getName().at(0) << " ] ";
                }
                else if(item2 != NULL)     // Player 2
                {
                    cout << " [ "<< second->getName().at(0) << " ] ";
                }
            }
            else if(board.getCell(column, row)->isSpecial() == true)  // if special cell on board is a SNAKE
            {
                cout << " [ s ] ";                                        
            }
            else if(board.getCell(column, row)->isSpecial() == true) // if special cell on board is a LADDER
            {
                cout << " [ l ] ";
            }
            else
            {
                cout << " [   ] ";        // empty cell                      
            }
        }
        
        cout << "" << endl;
    }
    
    cout << "     "; 
    
    for(int col = 0; col < board.getWidth(); col++)
    { 
        cout << "   " << col << "   ";         // print column numbers on sides of the board
    }
    
    cout << "" << endl;
}



//Ugly but necessary :(
void SnakeLadderSession::moveByAmount(int num, int x, int y)
{
    if(board.isOccupiedAt(x, y))
    {
        if(y == 99 && x - num < 0)  //Cant move off the board
        {
            return;
        }
        else if(y % 2 == 0)         //Right
        {
            if(x + num > 9)         //If we will move off the edge
            {
                int movCurr = 9 - x; 
                int movNext = num - movCurr;
                board.getCell(9 - movNext, ++y)->placeItem(board.getCell(x, y)->getItemForPlayer(playerForTurn()));
                board.getCell(x, y)->placeItem(NULL);
                setProperXY(9 - movNext, y);
            }
            else
            {
                board.getCell(x + num, y)->placeItem(board.getCell(x, y)->getItemForPlayer(playerForTurn()));
                setProperXY(x + num, y);
                board.getCell(x, y)->placeItem(NULL);
            }
        }
        else                         //Left
        {
            if(x - num < 0)          //If we will move off the edge
            {
                int movCurrent = 9 - x;
                int movNext = num - movCurrent;
                board.getCell(movNext, ++y)->placeItem(board.getCell(x, y)->getItemForPlayer(playerForTurn()));
                setProperXY(movNext, y);
                board.getCell(x, y)->placeItem(NULL);
            }
            else 
            {
                board.getCell(x - num, y)->placeItem(board.getCell(x, y)->getItemForPlayer(playerForTurn()));
                setProperXY(x - num, y);
                board.getCell(x, y)->placeItem(NULL);
            }
        }
    }
}

void SnakeLadderSession::gameLoop()
{    

    board.placeItemAt(0, 0, tokenPlayer1);
    board.placeItemAt(0, 0, tokenPlayer2);
    
    do 
    {  
        printInConsole();
        cout << playerForTurn()->getName() << " press to roll the dice" << endl;
        int mov = dice();
        cout << playerForTurn()->getName() << " goes by " << mov << endl;
        moveByAmount(mov, tokenForPlayer(playerForTurn())->getX(), tokenForPlayer(playerForTurn())->getY());
        getchar();
        changeTurn();
        printInConsole();
        
    } while (canContinue());
    
}