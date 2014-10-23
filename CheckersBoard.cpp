/*
    Author: Sean Smith
    Date:   20/04/2012
    Class:  CheckersBoard.cpp
    
    Purpose: Used to implement the methods
*/

#include "CheckersBoard.h"
#include "GameBoard.h"

void CheckersBoard::initForPlayer(Player *player, boardCondition condition)
{
    if(condition == Upper)                           //For a player on the upper part (Player 1)
    {
        for(int i = 7; i > 4; i--)              //Go from top down 3 rows
        {
            for(int j = 0; j < 8; j++)          //Traverse right
            {
                if((i % 2 != 0) && (j % 2 != 0))        //If we are at an odd row and colum
                {
                    CheckersDisk *disk = new CheckersDisk(j, i, player, goingDown);
                    placeItemAt(j, i, disk);
                }
                else if((i % 2 == 0) && (j % 2 == 0))   //If we are at an even row and even column
                {
                    CheckersDisk *disk = new CheckersDisk(j, i, player, goingDown);
                    placeItemAt(j, i, disk);
                }
            }
        }
    }
    else                                        //For a player on the lower part (Player 2)
    {
        for(int i = 0; i < 3; i++)              //Go from the bottom up 3 rows
        {
            for(int j = 0; j < 8; j++)          //Traverse right
            {
                if((i % 2 == 0) && (j % 2 == 0))        //If we are at an even row and column
                {
                    CheckersDisk *disk = new CheckersDisk(j, i, player, goingUp);
                    placeItemAt(j, i, disk);
                }
                else if((i % 2 != 0) && (j % 2 != 0))   //If we are at an odd row and odd column
                {
                    CheckersDisk *disk = new CheckersDisk(j, i, player, goingUp);
                    placeItemAt(j, i, disk);
                }
            }
        }
    }
}


void CheckersBoard::initBoard(Player *player1, Player *player2)
{
    initForPlayer(player1, Upper);
    initForPlayer(player2, Lower);
    
   for(int i = 0; i < 8; i++)
   {
        GameBoard<CheckersCell>::getCell(i, 0)->setSpecialCell(true);
        GameBoard<CheckersCell>::getCell(i, 0)->changeValueState(player2);
        GameBoard<CheckersCell>::getCell(i, 7)->setSpecialCell(true);
        GameBoard<CheckersCell>::getCell(i, 7)->changeValueState(player1);
   }
}

void CheckersBoard::displayBoard()                                 //Print row by row, from top to bottom
{
    for(int row = getHeight() - 1; row >= 0; row--)
    {
        cout << " " << row << " ";
        
        for (int column = 0; column < getWidth(); column++) 
        {
            if(isOccupiedAt(column, row))
            {
                Item *checker = getItemAt(column, row);
                
                if(checker->ownedBy() == 0)
                {
                    cout << " [R] ";
                }
                else if(checker->ownedBy() == 1)
                {
                    cout << " [W] ";
                }
            }
            else
            {
                cout << " [ ] ";
            }
        }
        
        cout << "" << endl;
    }
    
    cout << "   ";
    
    for(int i = 0; i < getWidth(); i++)
    {
        cout << "  " << i << "  ";
    }
    
    cout << "" << endl;
    cout << endl;
}
