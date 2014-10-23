//
//  Player.cpp
//  GameSuite
//
//  Created by Robert Lis on 30/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Player.h"

Player::Player(int id, const char* name)
{
    this->id = id;
    this->name = new string(name);
}
