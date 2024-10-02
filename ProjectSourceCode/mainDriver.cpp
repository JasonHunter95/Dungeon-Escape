#include "Monster.h"
#include "Player.h"
#include "Party.h"
#include "Riddles.h"
#include "Map.h"
#include "Inventory.h"
#include "Merchant.h"
#include "Game.h"
#include "Riddles.h"
#include "BoulderParchmentShears.cpp"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    // game loop runs the game
    Game game;
    game.gameLoop();
    return 0;
}