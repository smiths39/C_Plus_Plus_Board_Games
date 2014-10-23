/*
    main.cpp
    Created by Feargal Karney
*/

#include "CheckerSession.h"
#include "ConnectFourSession.h"
#include "SnakeLadderSession.h"

#define WIDHT 10
#define HEIGHT 10

using namespace std;

void initCheckersGame()
{
    Player *chPlayer1 = new Player(0, "Robert");
    Player *chPlayer2 = new Player(1, "Sean");
    CheckerSession *session= new CheckerSession(chPlayer1, chPlayer2);
    system("cls");
    cout << "**-----------------Checkers Game-----------------**\n" << endl;
    session->gameSwitch();
}

void initConnectFourGame()
{
    Player *conPlayer1 = new Player(0, "Robert");
    Player *conPlayer2 = new Player(1, "Sean");
    ConnectFourSession *conSession = new ConnectFourSession(conPlayer1, conPlayer2);
    system("cls");
    cout << "**-----------------Connect Four Game--------------**\n" << endl;
    conSession->gameLoop();
}

void initSnakesAndLaddersGame()
{
    Player *snlPlayer1 = new Player(0, "Robert");
    Player *snlPlayer2 = new Player(1, "Sean");
    SnakeLadderSession *snlSession = new SnakeLadderSession(snlPlayer1, snlPlayer2);
    system("cls");
    cout << "**-----------------Snakes and Ladders Game--------------**\n" << endl;
    snlSession->gameLoop();
}

int main()
{
    while(true)
    {
        cout << "**-----------------Game Compendium---------------**\n" << endl;
        cout << "Press 1 for Checkers\n";
        cout << "Press 2 for Connect Four\n";
        cout << "Press 3 for Snakes and Ladders\n";
        cout << endl;
        char c;
        cin >> c;

        if(c == '1')
        {
            initCheckersGame();
        }
        else if(c == '2')
        {
            initConnectFourGame();
        }
        else if(c == '3')
        {
            initSnakesAndLaddersGame();
        }
        else
        {
            system("cls");
            cout << "Error: enter a valid number\n";
        }
    }
}

