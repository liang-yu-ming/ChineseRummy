#include "class.h"
#include <iostream>
using namespace std;

int main()
{
    COORD Vector;
    Vector.X = 3000;
    Vector.Y = 1000;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), Vector);
    game Game;
    player User;
    player computer;
    Game.shuffle();
    Game.deal();
    int round=0;
    while (round<12)
    {
        cout << "NEW ROUND~~" << endl;
        Game.showtable();
        User.showhand();
        User.playerplay();
        Game.newtable(0);
        Game.showtable();
        computer.computerplay();
        Game.newtable(1);
        round++;
    }
    Game.whowin();
    return 0;
}
