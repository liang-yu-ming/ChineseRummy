#include "class.h"
#include <iomanip>
#include <iostream>
#include <time.h>
using namespace std;
vector<card> playercard(12), computercard(12), table, deck;
int playerscore = 0, computerscore = 0, cardcount = 28;
void SetColor(int color = 7)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
card::card()
{
    suit = face = 0;
}
void card::setsuit(int x)
{
    suit = x;
}
int card::getsuit()
{
    return suit;
}
void card::setface(int x)
{
    face = x;
}
int card::getface()
{
    return face;
}
void card::operator=(card &x)
{
    suit = x.suit;
    face = x.face;
}
int card::operator+(card &x)
{
    return this->face + x.face;
}
bool card::operator==(card &x)
{
    if (this->face == x.face)
        return 1;
    else
        return 0;
}
void game::shuffle()
{
    srand(time(NULL));
    card onecard;
    for (int i = 0; i < 52; i++)
    {
        onecard.setsuit(i / 13);
        onecard.setface(i % 13);
        deck.push_back(onecard);
    }
    for (int i = 0; i < 1000; i++)
    {
        int r1 = rand() % 52;
        int r2 = rand() % 52;
        card tempcard;
        tempcard = deck[r1];
        deck[r1] = deck[r2];
        deck[r2] = tempcard;
    }
}
void game::deal()
{
    for (int i = 0; i < 4; i++)
        table.push_back(deck[i]);
    for (int i = 0; i < 12; i++)
        playercard[i] = deck[i + 4];
    for (int i = 0; i < 12; i++)
        computercard[i] = deck[i + 16];
}
void game::showcard(int a, int b)
{
    if (b == 0)
    {
        if (a < 1)
            cout << "           ";
        else if (a == 1)
            cout << "A"
                 << "          ";
        else if (a == 11)
            cout << "J"
                 << "          ";
        else if (a == 12)
            cout << "Q"
                 << "          ";
        else if (a == 13)
            cout << "K"
                 << "          ";
        else
            cout << left << setw(2) << a << "         " << right;
    }
    else if (b == 1)
    {
        if (a == 0)
            cout << "     *     ";
        else if (a == 1)
            cout << " **     ** ";
        else if (a == 2)
            cout << "     *     ";
        else if (a == 3)
            cout << "     *     ";
    }
    else if (b == 2)
    {
        if (a == 0)
            cout << "   *****   ";
        else if (a == 1)
            cout << "****   ****";
        else if (a == 2)
            cout << "    ***    ";
        else if (a == 3)
            cout << "    ***    ";
    }
    else if (b == 3)
    {
        if (a == 0)
            cout << "  *******  ";
        else if (a == 1)
            cout << " ********* ";
        else if (a == 2)
            cout << "   *****   ";
        else if (a == 3)
            cout << " **  *  ** ";
    }
    else if (b == 4)
    {
        if (a == 0)
            cout << " ********* ";
        else if (a == 1)
            cout << "  *******  ";
        else if (a == 2)
            cout << "  *******  ";
        else if (a == 3)
            cout << "***********";
    }
    else if (b == 5)
    {
        if (a == 0)
            cout << "*   ***   *";
        else if (a == 1)
            cout << "   *****   ";
        else if (a == 2)
            cout << "   *****   ";
        else if (a == 3)
            cout << " **  *  ** ";
    }
    else if (b == 6)
    {
        if (a == 0)
            cout << "     *     ";
        else if (a == 1)
            cout << "    ***    ";
        else if (a == 2)
            cout << "    ***    ";
        else if (a == 3)
            cout << "    ***    ";
    }
    else if (b == 7)
    {
        if (a == 0)
            cout << "    ***    ";
        else if (a == 1)
            cout << "     *     ";
        else if (a == 2)
            cout << "     *     ";
        else if (a == 3)
            cout << "   *****   ";
    }
    else
    {
        if (a < 1)
            cout << "           ";
        else if (a == 1)
            cout << setw(11) << "A";
        else if (a == 11)
            cout << setw(11) << "J";
        else if (a == 12)
            cout << setw(11) << "Q";
        else if (a == 13)
            cout << setw(11) << "K";
        else
            cout << setw(11) << a;
    }
}
void game::showtable()
{
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < table.size(); i++)
        {
            if (table[i].getsuit() == 0 || table[i].getsuit() == 3)
            {
                SetColor(240);
                if (j == 0 || j == 8)
                    showcard(table[i].getface() + 1, j);
                else
                    showcard(table[i].getsuit(), j);
                SetColor(7);
                cout << "  ";
            }
            if (table[i].getsuit() == 1 || table[i].getsuit() == 2)
            {
                SetColor(252);
                if (j == 0 || j == 8)
                    showcard(table[i].getface() + 1, j);
                else
                    showcard(table[i].getsuit(), j);
                SetColor(7);
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
bool game::playornot(int x)
{
    for (int i = 0; i < 12; i++)
    {
        if (x == 0)
        {
            if (playercard[i].getface() != -10)
                for (int j = 0; j < table.size(); j++)
                {
                    if (playercard[i] + table[j] == 8)
                        return 1;
                    if (playercard[i].getface() >= 9)
                        if (playercard[i] == table[j])
                            return 1;
                }
        }
        else
        {
            if (computercard[i].getface() != -10)
                for (int j = 0; j < table.size(); j++)
                {
                    if (computercard[i] + table[j] == 8)
                        return 1;
                    if (computercard[i].getface() >= 9)
                        if (computercard[i] == table[j])
                            return 1;
                }
        }
    }
    return 0;
}
void game::countscore(int deter, card x, card y)
{
    int xpoint = 0, ypoint = 0, total;
    if (x.getsuit() == 1 || x.getsuit() == 2)
    {
        if (x.getface() == 0)
            xpoint += 20;
        else if (x.getface() == 8 || x.getface() == 9 || x.getface() == 10 || x.getface() == 11 || x.getface() == 12)
            xpoint += 10;
        else
            xpoint += x.getface() + 1;
    }
    if (y.getsuit() == 1 || y.getsuit() == 2)
    {
        if (y.getface() == 0)
            ypoint += 20;
        else if (y.getface() == 8 || y.getface() == 9 || y.getface() == 10 || y.getface() == 11 || y.getface() == 12)
            ypoint += 10;
        else
            ypoint += y.getface() + 1;
    }
    if (x.getsuit() == 0 && x.getface() == 0)
        xpoint += 10;
    if (y.getsuit() == 0 && y.getface() == 0)
        ypoint += 10;
    total = xpoint + ypoint;
    if (deter == 0)
        playerscore += total;
    else
        computerscore += total;
    cout << "獲得" << total << "分!!" << endl;
}
int game::findtable(card x)
{
    for (int i = 0; i < table.size(); i++)
        if (x.getface() == table[i].getface() && x.getsuit() == table[i].getsuit())
            return i;
    return 0;
}
void game::newtable(int x)
{
    game Game;
    table.push_back(deck[cardcount]);
    cardcount++;
    int i;
    for (i = 0; i < table.size() - 1; i++)
    {
        if (table[table.size() - 1].getface() >= 9 || table[i].getface() >= 9)
        {
            if (table[table.size() - 1] == table[i])
            {
                cout << "Comble!!" << endl;
                Game.showtable();
                Game.countscore(x, table[table.size() - 1], table[i]);
                table.pop_back();
                table.erase(table.begin() + i);
                Game.showtable();
                break;
            }
        }
        else if (table[table.size() - 1] + table[i] == 8)
        {
            cout << "Comble!!" << endl;
            Game.showtable();
            Game.countscore(x, table[table.size() - 1], table[i]);
            table.pop_back();
            table.erase(table.begin() + i);
            Game.showtable();
            break;
        }
    }
}
void game::whowin()
{
    cout << "遊戲結束!!" << endl;
    if (playerscore > computerscore)
        cout << "玩家獲勝~~~" << endl;
    else if (computerscore > playerscore)
        cout << "電腦獲勝>_<" << endl;
    else if (playerscore == computerscore)
        cout << "平手......" << endl;
}
void player::showhand()
{
    cout << "你的手牌 :" << endl;
    for (int i = 0; i < 12; i++)
    {
        if (playercard[i].getface() == -10)
            cout << setw(5) << "已出牌" << endl;
        else
        {
            if (playercard[i].getsuit() == 0)
            {
                cout << setw(2) << i + 1 << "."
                     << "黑桃" << setw(2) << playercard[i].getface() + 1 << "  ";
                cout << endl;
            }
            else if (playercard[i].getsuit() == 1)
            {
                cout << setw(2) << i + 1 << "."
                     << "愛心" << setw(2) << playercard[i].getface() + 1 << "  ";
                cout << endl;
            }
            else if (playercard[i].getsuit() == 2)
            {
                cout << setw(2) << i + 1 << "."
                     << "菱形" << setw(2) << playercard[i].getface() + 1 << "  ";
                cout << endl;
            }
            else
            {
                cout << setw(2) << i + 1 << "."
                     << "梅花" << setw(2) << playercard[i].getface() + 1 << "  ";
                cout << endl;
            }
        }
    }
    cout << endl;
    cout << "玩家得分:" << playerscore << endl;
}
void player::playerplay()
{
    int eatinput, input;
    card choose;
    game Game;
    if (Game.playornot(0))
    {
        bool check = true;
        while (check)
        {
            do
            {
                cout << "請輸入你要吃的牌的編號(由左至右1.2.3......)" << endl;
                cin >> eatinput;
            } while (eatinput > table.size());
            choose = table[eatinput - 1];
            do
            {
                cout << "請輸入你要打出的牌的編號" << endl;
                cin >> input;
            } while (playercard[input - 1].getface() == -10);
            if (playercard[input - 1].getface() >= 9 || choose.getface() >= 9)
                if (playercard[input - 1] == choose)
                    check = false;
            if (playercard[input - 1] + choose == 8)
                check = false;
            if (check)
                cout << "輸入錯誤!!" << endl;
        }
        Game.countscore(0, playercard[input - 1], choose);
        playercard[input - 1].setface(-10);
        table.erase(table.begin() + Game.findtable(choose));
    }
    else
    {
        do
        {
            cout << "無牌可出!!  輸入你要打到檯面上牌的編號" << endl;
            cin >> input;
        } while (playercard[input - 1].getface() == -10);
        table.push_back(playercard[input - 1]);
        playercard[input - 1].setface(-10);
    }
}
void player::computerplay()
{
    game Game;
    int r;
    bool check = false;
    cout << "電腦回合!!" << endl;
    cout << "電腦得分:" << computerscore << endl;
    if (Game.playornot(1))
    {
        for (int i = 0; i < 12; i++)
            if (computercard[i].getface() != -10)
            {
                for (int j = 0; j < table.size(); j++)
                {
                    if (computercard[i].getface() >= 9)
                    {
                        if (computercard[i] == table[j])
                        {
                            Game.countscore(1, computercard[i], table[j]);
                            computercard[i].setface(-10);
                            table.erase(table.begin() + j);
                            check = true;
                            if (check)
                                break;
                        }
                    }
                    else if (computercard[i] + table[j] == 8)
                    {
                        Game.countscore(1, computercard[i], table[j]);
                        computercard[i].setface(-10);
                        table.erase(table.begin() + j);
                        check = true;
                        if (check)
                            break;
                    }
                }
                if (check)
                    break;
            }
    }
    else
    {
        srand(time(NULL));
        do
        {
            r = rand() % 12;
        } while (computercard[r].getface() == -10);
        table.push_back(computercard[r]);
        computercard[r].setface(-10);
        cout << "電腦打了一張牌在檯面上!!" << endl;
    }
}
