#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() // default constructor
{
    name_ = "";
    fullness_ = 50;
}

Player::Player(string name) // parametrized constructor
{
    name_ = name;
    fullness_ = 50;
}

// getters/accessors
string Player::getName()
{
    return name_;
}

int Player::getFullness()
{
    return fullness_;
}

// setters/mutators
void Player::setName(string name)
{
    name_ = name;
}

void Player::setFullness(int fullness)
{
    if (fullness > 0) // if fullness is greater than 0
    {
        if (fullness_ == 50)
        {
            cout << "Can't add more Health" << endl; // won't add anymore health to player if they have 50
        }
        else if ((fullness_ + fullness) >= 50)
        {
            fullness_ = 50; // if amount of fullness being added goes over 50 it sets fulnnes to 50
        }
        else
        {
            fullness_ = fullness_ + fullness; // it will just to the orignal fullnes
        }
    }
    else // this is to subtract the fullness
    {
        fullness_ = fullness_ + fullness;
    }
}