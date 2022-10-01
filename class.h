#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
void SetColor(int);
class card
{
private:
    int suit;
    int face;

public:
    card();
    void setsuit(int);
    int getsuit();
    void setface(int);
    int getface();
    void operator=(card &);
    int operator+(card &);
    bool operator==(card &);
};
class game
{
public:
    void shuffle();
    void deal();
    void showcard(int, int);
    void showtable();
    bool playornot(int);
    void countscore(int, card, card);
    int findtable(card);
    void newtable(int);
    void whowin();
};
class player
{
public:
    void showhand();
    void playerplay();
    void computerplay();
};
extern vector<card> playercard, computercard, table, deck;
extern int playerscore, computerscore, cardcount;
#endif
