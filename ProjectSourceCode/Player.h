#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player
{
private:
    string name_;
    int fullness_;

public:
    Player();
    Player(string name);

    string getName();
    int getFullness();

    void setName(string name);
    void setFullness(int fullness);
};

#endif
