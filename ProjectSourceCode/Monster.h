#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

using namespace std;

class Monster
{
private:
    string name_;
    int challenge_rating_;
    // int const static room_number = 6;
    // int const static num_monsters = 4;
    // string monsters[room_number][num_monsters];

public:
    Monster();                                  // default constructor
    Monster(string name, int challenge_rating); // parametrized constructor (takes in a string name and int challenge_rating)

    // getters/accessors
    string getMonsterName();
    int getChallengeRating();

    // setters/mutators
    void setMonster(string name);
    void setChallengeRating(int rating);
    void storeMonster(string file_name, Monster Monsters[][4]);
};

#endif