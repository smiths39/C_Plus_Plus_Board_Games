/*
  NOTE: in "validMovement()" method, you should use a for loop (through ROWs)
                                           every 2nd row - make left direction acceptable (e.g. Row 1, 3, 5, 7, 9) 
                                           other rows - make right direction acceptable (e.g. Row 0, 2, 4, 6, 8) 
*/

#ifndef GameSuite_SnakeLadderSession_H 
#define GameSuite_SnakeLadder_H 

#import "SnakeLadderBoard.h"
#import "Player.h"

enum Turn {player1turn, player2turn};
enum DirectionOnBoard{Right, Left};

class SnakeLadderSession
{
private:
    SnakeLadderBoard board;          // Board for the game (reference!)
    Player *first;                   // Player 1             
    Player *second;                  // Player 2
    Turn turn;                       // using enumeration
    Item* tokenPlayer1;
    Item* tokenPlayer2;
    
    void moveByAmount(int num, int x, int y);     //
    void setProperXY(int x, int y);
    /* HELPERS */
    bool canContinue();           // if is possible to continue game
    Player* playerForTurn();      // Player who's turn it is
    void changeTurn();            // Change the player's turn in game
    int dice();  // generate a random number
    Item* tokenForPlayer(Player *player);
    void printInConsole();
    
public:
    // Constructor initializing each player on board, setting player 1 turn first, initializing the board with occupied cells
    SnakeLadderSession(Player *one, Player *two) : first(one), second(two), turn(player1turn) { board.initBoard(); tokenPlayer1 = new Item(0,0,true,first); tokenPlayer2 = new Item(0, 0, true, second);} 
    void gameLoop();            //Hand over the control to the game loop
};

#endif
