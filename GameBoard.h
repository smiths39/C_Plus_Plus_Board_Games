//
//  Header.h
//  GameSuite
//
//  Created by Robert Lis on 29/03/2012.
//  Copyright (c) 2012 RedFoxDev. All rights reserved.
//
//  Generic base class template representing board. Designed to be extended in subclasses.
//  T is should be subclass of GameBoardCell. 
//  BOARD INDEXING : USE 2D Cartesian-Coordinate System (X, Y) where (0,0) is at the DOWN LEFT.
//  Underlying array indexing is abstracted away. X grows to the right, Y grows up.

#ifndef GameSuite_Header_H
#define GameSuite_Header_H

#define BOARD_DEF_WIDTH 2           //Default height of board, in no value suppied for constuctor
#define BOARD_DEF_HEIGHT 2          //Default width of board, if no value supplied to a constuctor

#import "GameBoardCell.h"
#import <iostream>

template<class T = GameBoardCell> 
class GameBoard       
{
private:
    int width;          //Board width
    int height;         //Boards height
    T **board;          //2D array of type T
public:
    GameBoard(int height = BOARD_DEF_HEIGHT, int width = BOARD_DEF_WIDTH);       //Constructor, creates 2D grid for games. 
    ~GameBoard(); //Deallocates grid, but not items on the board.
    inline int getWidth() {return width;}
    inline int getHeight() {return height;}
    bool isOccupiedAt(int x, int y);                                             //Check if board at (X,Y) is occupied.
    bool placeItemAt(int x, int y, Item* item);                                  //Place item at X/Y, pass NULL to clean.
    Item* getItemAt(int x, int y);                                               //Return item from (X,Y), NULL returned if field is empty.
    inline bool fitsOnBoard(int x, int y) { return x >= 0 && x < getWidth() && (height - y - 1) >= 0 && height - y - 1 < getHeight(); }
    T* getCell(int x, int y);  //Be CAREFUL, returns object representing cell which is part of an array, use only if its a must. Returns NULL if fitsOnBoard(x, y) == false;


};

template<class T> GameBoard<T>::GameBoard(int height, int width)
{
    this->height = height;
    this->width = width;
    
    board = new T*[height];             
    
    for (int row = 0; row < height; row++)
    {
        board[row] = new T[width];
    }
}

template<class T> GameBoard<T>::~GameBoard()
{
    for(int i = 0; i < height; i++)
    {
        delete[] board[i];
    }
    
    delete [] board;
}

template<class T> bool GameBoard<T>::isOccupiedAt(int x, int y)
{
    if(fitsOnBoard(x, y))
    {        
        return board[height - y - 1][x].isOccupied();
    }
    else
    {
        return false;
    }
}

template<class T> bool GameBoard<T>::placeItemAt(int x, int y, Item *item)
{
    if(fitsOnBoard(x, y) && !isOccupiedAt(x, y))
    {
        return board[height - y - 1][x].placeItem(item);
    }
    else if(fitsOnBoard(x, y) && item == NULL)
    {
        board[height - y - 1][x].placeItem(NULL);
        return true;
    }
    else
    {
        return false;
    }
}

template<class T> Item* GameBoard<T>::getItemAt(int x, int y)
{
    if(isOccupiedAt(x, y))
    {
        return board[height - y - 1][x].showItem();
    }
    else
    {
        return NULL;
    }
}

template<class T> T* GameBoard<T>::getCell(int x, int y)
{
    if(fitsOnBoard(x, y))
    {
        return &(board[height - y - 1][x]);
    }
    else
    {
        return NULL;
    }
}

#endif
