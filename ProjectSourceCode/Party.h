#ifndef PARTY_H
#define PARTY_H

#include <vector>
#include <iostream>
#include "Inventory.h"
#include "Player.h"
#include "Monster.h"
#include "Merchant.h"

using namespace std;

class Party
{
private:
    Inventory inventory_;
    string username_;
    string print_name;
    int print_fullness;
    Merchant price;
    int item_price;
    int updated_gold;
    int current_gold;
    int amount = -1;
    char result;
    int ingreds = 0;
    int choice = 0;
    int attack = 0;
    int battle_result = 0;
    double chance = 0;
    // Party count = 5;
    vector<Player> party;

public:
    // constructor will ask for player names
    Party();
    void printName(int player_index);
    void printFullness(int player_index);
    // attempt to buy and sell items, or print error message if unsuccessful
    void buyItem(string item_name, int room_number);
    void sellTreasure(string item_name);
    bool fightMonster(int monster_rating, string monster_name); // gets info from inventory
    void findTreasure(int num_rooms_cleared);
    void handleMisfortune();
    void printPartyInfo();
    bool checkPartyStats();
    void checkFullness();
    void losePlayer();
    // decrease every players fullness by 1 with probability chance
    void decreaseFullness(/*double chance*/); // overload decreases fullness for individual player
    void cookAndEat();                        // menu to attempt to cook ingredients and eat a meal
};

#endif