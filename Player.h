//
//  Player.h
//  GameSuite
//
//  Created by Robert Lis on 29/03/2012.
//  Copyright (c) 2012 RedFoxDev. All rights reserved.
//
//  CLASS PLAYER
//  Use to identify players information.

#ifndef GameSuite_Player_H
#define GameSuite_Player_H

#import <string>
using namespace std;

class Player
{
private:
    string *name;                   //playes users name 
    int id;                         //players id number
public:
    Player(int id = -1, const char* = "NONAME" );   //constructor, pass id and C-style string
    int getId() {return id ;}                       //return players id number
    string getName() {return *name ;}
};

#endif
