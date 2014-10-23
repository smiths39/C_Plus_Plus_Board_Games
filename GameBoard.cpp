//
//  GameBoard.cpp
//  GameSuite
//
//  Created by Robert Lis on 29/03/2012.
//  Copyright (c) 2012 RedFoxDev. All rights reserved.
//
//
//
#import "GameBoard.h"
template <class T> 
GameBoard<T>::GameBoard(int height, int width)
{
    this->height = height;
    this->width = width;
    
    board = new T*[height];             
    
    for (int row = 0; row < height; row++)
    {
        board[row] = new T[width];
    }
}

template<class T>
GameBoard<T>::~GameBoard()
{
    for(int i = 0; i < height; i++)
    {
        delete[] board[i];
    }
    
    delete[] board;
}