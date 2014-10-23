#ifndef GameSuite_SnakeLadderBoard_H
#define GameSuite_SnakeLadderBoard_H

#include "SnakeLadderCell.h"
#include "GameBoard.h"
#include "Player.h"

#define SNAKELADDER_DEF_WIDTH  10
#define SNAKELADDER_DEF_HEIGHT 10

class SnakeLadderBoard : public GameBoard<SnakeLadderCell>
{
private:
    bool canAccept(int x, int y);
public:
    SnakeLadderBoard(int height = SNAKELADDER_DEF_HEIGHT, int width = SNAKELADDER_DEF_WIDTH) : GameBoard<SnakeLadderCell>(height, width) {};
    void initBoard();           // calls "InitPlayer" and sets where the special cells are
    void printInConsole();                                              // print board layout with each player initalized at position
    bool placeItemAt(int x, int y, Item* item);
};

#endif
