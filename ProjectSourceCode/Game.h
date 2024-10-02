#ifndef GAME_H
#define GAME_H

#include <cstring>
#include <iostream>
#include "Merchant.h"
#include "Player.h"
#include "Party.h"
#include "Map.h"
#include "Riddles.h"
#include "Monster.h"
#include <vector>

using namespace std;

class Game
{
private:
    // create all objects - party, riddles, monster, map
    Riddles riddles_;
    Map map_;
    Monster monster_;
    Party party_;
    Merchant merchant_;
    int anger_level_ = 0;
    int rooms_cleared_ = 0;
    int num_turns = 0;
    int spaces_explored = 0;
    int num_monsters_defeated = 0;
    int keys_ = 01;
    bool result;
    int counter = 0;
    char direction;   // direction to move (wasd)
    int row;          // map row
    int col;          // map col
    int choice = 0;   // outer menu choice
    int choice_2 = 0; // inner menu choice

public:
    Game(); // default constructor
    int getKeys();
    int getAngerLevel();
    void setAngerLevel();
    void openMerchantMenu(int room_number);
    void printMenu(Monster monstercontainer[6][4], Riddles riddles_array[20]);
    bool speakToNPC();
    void printStatusUpdate(); // prints various components of the party
    void randomizeMap();      // function to randomly add rooms and npc's to the map
    bool Battle(Monster monstercontainer[6][4], int room_number);
    void endGame();
    void gameLoop();
};

#endif
