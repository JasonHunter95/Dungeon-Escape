Date: Dec 1, 2022
------------------------------------------------

HOW TO COMPILE AND RUN
------------------------

Compile: g++ -std=c++17 Monster.cpp Player.cpp Party.cpp Map.cpp Inventory.cpp Merchant.cpp Game.cpp Riddles.cpp mainDriver.cpp
------------------------
Run: ./a.out
------------------------

DEPENDENCIES
------------------------

Game.h Monster.h Map.h Player.h Riddles.h Merchant.h Party.h Inventory.h
files in order to compile
------------------------

ABOUT THIS PROJECT
------------------------

This project entails a comprehensive dungeon escape game.
The game can be summarized by these core concepts:
The player buys supplies from merchants before starting the journey through the dungeon.
There are five locked rooms in the dungeon, each of which must be cleared (i.e., the monsters inside must be defeated). After clearing all five rooms, the exit of the dungeon will unlock.
There are two ways to find keys to unlock rooms: fighting monsters and investigating spaces.
There are opportunities to cook food from raw ingredients along the way.
There are chances to find additional merchants along the way.
The player must manage fullness levels of the party to avoid dying by hunger.
The player can find various treasures around the map which can be sold to merchants.
Misfortunes frequently occur.
Every time the player moves to a space which is not marked as explored, the Sorcerer's anger level rises by 1. Once the Sorcerer is defeated in the final room, the Sorcerer's anger level no longer increases.
The game ends when the player (and at least one of the companions) clear all the rooms and reach the end of the dungeon, when the player loses all their party members, or when the Sorcerer anger level reaches 100.
