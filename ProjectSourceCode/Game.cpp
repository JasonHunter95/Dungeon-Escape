#include "Game.h"
#include "Party.h"
#include "Player.h"
#include "Riddles.h"
#include "Inventory.h"
#include "Merchant.h"
#include "Monster.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

void storeRiddle(string file_name, Riddles riddles[]);
char getDoorInput(); // function for BoulderParchmentShears
char getPlayerInput(); // function for BoulderParchmentShears
bool displayGame(); // function for BoulderParchmentShears

Game::Game() // default constructor for game class
{
    anger_level_ = 0;
    rooms_cleared_ = 0;
    keys_ = 0;
    choice = 0;
}

// function that randomizes spaces for NPCs and Rooms and adds 5 of each
// uses random 
// returns a void
// parameters: none
void Game::randomizeMap()
{
    srand(time(0));
    while (5 > counter) // creates 5 rooms
    {
        row = (rand() % 12) + 1;
        col = (rand() % 12) + 1;//generating random nums for row and col
        if (map_.isFreeSpace(row, col))//checking if you can add Room on the map
        {
            map_.addRoom(row, col); // adding a room to random spot on the map
            counter++;
        }
    }
    counter = 0;
    srand(time(0));
    while (5 > counter) // creates 5 npcs
    {
        row = (rand() % 12) + 1;
        col = (rand() % 12) + 1;//generating random nums for row and col
        if (map_.isFreeSpace(row, col))//checking if you can add NPC on the map
        {
            //map_.addRoom(row, col); // adding a room to random spot on the map
            map_.addNPC(row, col);  // adding a NPC to a random spot on the map
            counter++;
        }
    }
    counter = 0;
    map_.displayMap(); // display map
}

void Game::openMerchantMenu(int room_number) // function opens merchant menu based on num_rooms_cleared and applies cost multiplier
{
    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;
    cout << "Choose one of the following: " << endl;

    do // if user choice is valid
    {
        // print menu
        cout << "1. Ingredients: To make food, you have to cook raw ingredients. " << endl;
        cout << "2. Cookware: You will need something to cook those ingredients. " << endl;
        cout << "3. Weapons: It's dangerous to go alone, take this! " << endl;
        cout << "4. Armor: If you want to survive monster attacks, you will need some armor. " << endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands. " << endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale! " << endl;
        cin >> choice;   // get outer menu user choice
        if (choice == 1) // select ingredients
        {
            party_.buyItem("I", room_number); // buy ingredients
            choice = 0;                       // cancel
        }
        else if (choice == 2) // select cookware
        {
            choice = 0;   // reseting choice so the while loop runs
            choice_2 = 0; // reseting the value of choice just in case we already have a choice
            cout << "I have a several types of cookware, which one would you like? " << endl;
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
            while (choice_2 <= 0 || choice_2 > 4)
            {
                // print inner menu options
                cout << "Choose one of the following: " << endl;
                cout << "1. (25%) Ceramic Pot [2 Gold] " << endl;
                cout << "2. (10%) Frying Pan [10 Gold] " << endl;
                cout << "3. ( 2%) Cauldron [20 Gold] " << endl;
                cout << "4. Cancel" << endl;
                cin >> choice_2; // get inner menu choice
            }
            if (choice_2 == 1)
            {
                party_.buyItem("P", room_number); // buy pot(s)
            }
            else if (choice_2 == 2)
            {
                party_.buyItem("F", room_number); // buy pan(s)
            }
            else if (choice_2 == 3)
            {
                party_.buyItem("Ca", room_number); // buy cauldron(s)
            }
        }
        else if (choice == 3) // select weapons
        {
            choice = 0;
            choice_2 = 0;
            cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
            cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
            while (choice_2 <= 0 || choice_2 > 6)
            {
                // print inner menu options
                cout << "Choose one of the following: " << endl;
                cout << "1. Club [2 Gold]" << endl;
                cout << "2. Spear [2 Gold]" << endl;
                cout << "3. (+1) Rapier [5 Gold]" << endl;
                cout << "4. (+2) Axe [15 Gold]" << endl;
                cout << "5. (+3) Sword [50 Gold]" << endl;
                cout << "6. Cancel" << endl;
                cin >> choice_2;
            }
            if (choice_2 == 1)
            {
                party_.buyItem("Cl", room_number); // buy club(s)
            }
            else if (choice_2 == 2)
            {
                party_.buyItem("Sp", room_number); // buy spear(s)
            }
            else if (choice_2 == 3)
            {
                party_.buyItem("R", room_number); // buy rapier(s)
            }
            else if (choice_2 == 4)
            {
                party_.buyItem("Ax", room_number); // buy axe(s)
            }
            else if (choice_2 == 5)
            {
                party_.buyItem("Sw", room_number); // buy sword(s)
            }
        }
        else if (choice == 4) // select armour
        {
            choice = 0;
            choice_2 = 0;
            party_.buyItem("A", room_number); // buy armour
        }
        else if (choice == 5) // select sell treasures
        {
            choice = 0;
            choice_2 = 0;
            while (choice_2 <= 0 || choice_2 > 5)
            {
                // print inner menu options
                cout << "Would you like to sell treasure?" << endl;
                cout << "1. Rings " << endl;
                cout << "2. Necklaces " << endl;
                cout << "3. Bracelets " << endl;
                cout << "4. Circlets " << endl;
                cout << "5. Goblets " << endl;
                cin >> choice_2;
                // cout << choice_2 << endl;
            }
            if (choice_2 == 1)
            {
                party_.sellTreasure("R"); // sell rings
            }
            else if (choice_2 == 2)
            {
                party_.sellTreasure("N"); // sell necklaces
            }
            else if (choice_2 == 3)
            {
                party_.sellTreasure("B"); // sell bracelets
            }
            else if (choice_2 == 4)
            {
                party_.sellTreasure("C"); // sell circlets
            }
            else if (choice_2 == 5)
            {
                party_.sellTreasure("G"); // sell goblets
            }
        }
    } while (choice < 1 || choice > 6);//runs until user quits
    map_.displayMap();//shows the map
}

/*Gets a random monster from our container then user the fightmonster function with the equation for the battle result
uses storeMonster to fill in the monstercontainer
gets a random number from 0 to 4 
checks that the monsters challange rating isn't 0
if room_number equals 5 it will set chance equal to 0 so you get the sorcerer
stores the result of the fightMonster into result
if true (defeating the monster) changes the monsters challange rating to 0 so it can't be choosen again and increments tot he num_monsters_defeated
else it will return false if you didn't win the battle
Parameters: monstercontainer[][4](Monster), room_number(int)
returns: true or false
*/
bool Game::Battle(Monster monstercontainer[][4], int room_number)
{
    string file_name = "monsters.txt";//monster file
    if (counter < 1)//checking we haven't stored the array already
    {
        monster_.storeMonster(file_name, monstercontainer);
    }
    srand(time(0));
    int chance = rand() % 4;
    while (monstercontainer[room_number][chance].getChallengeRating() == 0)// if the challange rating of the monster is 0 than it get a different random number
    {
        chance = rand() % 4;
    }
    if(room_number == 5)//if room_number is 5 chance is 0 because of sorcerer
    {
        chance = 0;
    }
    //getting the result of the fight
    bool result = party_.fightMonster(monstercontainer[room_number][chance].getChallengeRating(), monstercontainer[room_number][chance].getMonsterName());
    if (result == true)
    {
        //updating the monster challenge rating to 0 so it won't show up again after defeated
        monstercontainer[room_number][chance].setChallengeRating(0); // setting challange rating to 0 so the monster can't be picked again
        counter = 1;
        num_monsters_defeated++;//counting how many monster we defeatd
        return true;//returning true for winning the battle
    }
    else
    {
        return false;//returnd false for losing the battle
    }
}

int Game::getKeys()//getters
{
    return keys_;
}

int Game::getAngerLevel()
{
    return anger_level_;
}

void Game::setAngerLevel()//setters
{
    anger_level_++;
}
/*
Prints out a menu with mutiple options
if option 1 is selected you can move around the map and it will raise the anger level of the sorcerer if you move to an unexplored space and haven't cleared all 5 rooms yet. Also your players in your 
party have a chance to lose fullness when you move
If you select option 2 you can enter a room which will result in a fight with a monster if you can get in and may have a misfortune. Or you can talk to NPC
which you have answer a riddle which will have diffrent results according to if you get the riddle right
there are mutiple random things that could happend when you investigate you can find a key, treasure or get into a fight with a monster
Option 3 pulls a random monster with the challange rating according to how many rooms you have cleared and according to the fight
result you may have gain stuff or lose players/stuff in your inventory
Option 4 you can cook and eat depending if you have the required tools. It will restore the users fullness but according to what
tool you have it may break when you use it.
Parameters: monstercontainer[6][4](Monster), riddle_array[20](Riddles) 
returns: None
*/
void Game::printMenu(Monster monstercontainer[6][4], Riddles riddle_array[20])
{
    do // do while loop that will run until the user defeats the game or the user loses in the game
    {  // printing out the menu
        cout << "Select one: " << endl;
        cout << "1. Move " << endl;
        cout << "2. Investigate " << endl;
        cout << "3. Pick a Fight" << endl;
        cout << "4. Cook and Eat " << endl;
        cout << "5. Give up " << endl;
        cin >> choice;
        if (choice == 1)
        {
            do // do while loop which willl run until player selects a valid answer
            {
                cout << "w. To move up " << endl;
                cout << "a. To move left " << endl;
                cout << "s. To move down " << endl;
                cout << "d. To move right " << endl;
                cin >> direction; // gets what direction the player is moving in
            } while ((direction != 'a') && (direction != 's') && (direction != 'd') && (direction != 'w'));
            map_.move(direction);                                                   // moves using the move function
            if ((map_.isExplored(map_.getPlayerRow(), map_.getPlayerCol()) == false) && rooms_cleared_ != 5) // checking if the space the player has moved to is exlpored
            {
                setAngerLevel(); // if the space is not exlpored than it will run the setAngerLevel() funtion which increases anger level
            }
            party_.decreaseFullness(); // decreases player fullness
            choice = 0;        // resets choice
        }
        else if (choice == 2) // player decides to investigate space
        {
            row = map_.getPlayerRow();   // gets the players row
            col = map_.getPlayerCol();   // gets the players col
            map_.exploreSpace(row, col); // uses the exploreSpace to explore the current space is the user
            spaces_explored++;// counts the amount of spaces explored
            if (map_.isDungeonExit(row, col))//checking if the space is the exit 
            {
                if(rooms_cleared_ == 5)//if you cleared all 5 rooms you can leave otherwise prints statement
                {
                    break;
                }
                else
                {
                    cout << "You have not cleared all the rooms so you can't leave" << endl;
                }
            }
            if (map_.isRoomLocation(row, col) == true)//checks if the space they're investagating is a room 
            {
                if (keys_ > 0)//if they have a key unlocks room
                {
                    cout << "You have used a key to unlock the room" << endl;
                    keys_ = keys_ - 1; // subtracts from key amount
                    result = Battle(monstercontainer, (rooms_cleared_ + 1));//getting the result of the fight
                    if (result == true)// if party won
                    {
                        rooms_cleared_++;//increase rooms cleared
                        // misfortune 60%
                        srand(time(0));
                        int rand_misfortune = (rand() % 100) + 1;//60% chance of misfortune happening
                        if (rand_misfortune <= 60)
                        {
                            party_.handleMisfortune();//runs our misfortune function which can affect the party in different ways
                        }
                        map_.removeRoom(row, col);//removes the room from the map
                    }
                    else//if the battle is lost
                    {
                        cout << "You have lost the battle" << endl;
                        srand(time(0));
                        int rand_misfortune = (rand() % 100) + 1;
                        if (rand_misfortune <= 40)//40% chance of misfortune
                        {
                            party_.handleMisfortune();//runs our misfortune function which can affect the party in different ways
                        }
                    }
                }
                else//if they don't have a key rock paper shoot game runs
                {
                    getDoorInput();//runs our getdoorinput function
                    getPlayerInput();//runs our playerinput function
                    result = displayGame();//then returns a bool depending on who won
                    if (result == true)// if you one the game 
                    {
                        result = Battle(monstercontainer, (rooms_cleared_ + 1));//you get to fight the monster in the room
                        if (result == true)// if you win the fight
                        {
                            rooms_cleared_++;//increase the amount of rooms cleared
                            // misfortune 60%
                            srand(time(0));
                            int rand_misfortune = (rand() % 100) + 1;
                            if (rand_misfortune <= 60)//%60 chance of misfortune
                            {
                                party_.handleMisfortune();//runs our misfortune function which can affect the party in different ways
                            }
                            map_.removeRoom(row, col);//removes the room from the map
                        }
                        else//if you lose the battle
                        {
                            cout << "You have lost the battle" << endl;
                            srand(time(0));
                            int rand_misfortune = (rand() % 100) + 1;
                            if (rand_misfortune <= 40)//%40 chance of misfortune
                            {
                                party_.handleMisfortune();//runs our misfortune function which can affect the party in different ways
                            }
                        }
                    }
                    else//if you lose rock paper shoot you lose a player
                    {
                        party_.losePlayer();
                    }
                }
                choice = 0;//reseting choice for our menu because we reuse it
            }
            if (map_.isNPCLocation(row, col) == true)//checking if there is a NPC in that location
            {
                choice = 0;//reseting choice
                do
                {
                    cout << "You have found an NPC " << endl;
                    cout << "1. Move " << endl;
                    cout << "2. Speak to NPC " << endl;
                    cout << "3. Give up " << endl;
                    cin >> choice;
                } while (choice < 1 || choice > 3);//will run until a valid answer is given
                if (choice == 1)//if 1 is selected
                {
                    do
                    {
                        cout << "w. To move up " << endl;
                        cout << "a. To move left " << endl;
                        cout << "s. To move down " << endl;
                        cout << "d. To move right " << endl;
                        cin >> direction;
                    } while ((direction != 'a') && (direction != 's') && (direction != 'd') && (direction != 'w'));
                    if ((map_.isExplored(map_.getPlayerRow(), map_.getPlayerCol())) == false && (rooms_cleared_ != 5))
                    {
                        setAngerLevel();
                    }//increase angerlevel if requirements are meet
                    map_.move(direction);//lets player move
                    party_.decreaseFullness();//running our functino that decrease the party's fullness
                }
                else if (choice == 2)//if choice 2 is selected
                {
                    string answer;//initializing our variables
                    storeRiddle("riddles.txt", riddle_array);//running our storeriddle functino
                    int rand_riddle = riddles_.randomRidNum();//getting a random riddle
                    cout << riddle_array[rand_riddle].getRiddle() << endl;//printing the random riddle
                    cin >> answer;//getting users answer
                    if (answer == riddle_array[rand_riddle].getAnswer())//if correct opens the merchant menu
                    {
                        openMerchantMenu(rooms_cleared_);
                        choice = 0;
                    }
                    else//otherwise the NPC spawns in a monster you have to fight
                    {
                        cout << "You have incorrectly answered the riddle. A monster has been summoned to fight!" << endl;
                        Battle(monstercontainer, rooms_cleared_);
                    }
                }
                else if (choice == 3)
                {
                    break;//giving up
                }
            }
            map_.removeNPC(row, col); // remove npc from map
            // randomizer for finding a key
            srand(time(0)); // seed random function
            int rand_key = (rand() % 10) + 1; // generate 10% chance
            if (rand_key == 1) // if 10% chance is hit
            {
                cout << "Your party has discovered a key!" << endl; // display message that a key was found
                keys_++; // increment keys
            }
            // randomizer for finding treasure
            srand(time(0)); // seed random function
            int rand_treasure = (rand() % 5) + 1; // generate 20% chance
            if (rand_treasure == 1) // if 20% chance is hit
            {
                cout << "You have found a treasure!" << endl; // display message that treasure was found
                party_.findTreasure(rooms_cleared_); // find treasure based on the number of rooms cleared
            }
            // randomizer for finding a monster;
            srand(time(0)); // seed random function
            int rand_monster = (rand() % 10) + 1; // generate 10% chance
            if ((rand_monster == 1) && (rooms_cleared_ != 5)) // if 10% chance is hit and the player hasn't cleared all 5 rooms yet
            {
                cout << "A monster has appeared!" << endl;
                Battle(monstercontainer, rooms_cleared_); // call battle function
            }
            choice = 0;
        }
        else if (choice == 3)
        {
            bool result = Battle(monstercontainer, rooms_cleared_); // call battle function
            // randomizer for finding a key
            if (result == true)
            {
                srand(time(0)); // seed random function
                int rand_key = (rand() % 10) + 1; // generate 10% chance
                if (rand_key == 1) // if 10% chance is hit
                {
                    cout << "Upon slaying the opponent, your party has discovered a key!" << endl; // message for discovering key
                    keys_ = keys_ + 1; // add key
                }
            }
            result = party_.checkPartyStats(); // check party stats
            if (result == false)
            {
                cout << "You have died to a Monster." << endl; // display death by monster message
                break;
            }
            choice = 0;
        }
        else if (choice == 4) // if option 4 is chosen
        {
            choice = 0;
            party_.cookAndEat(); // call cookAndEat() function
        }
        else if (choice == 5) // if option 5 is chosen
        {
            break;
        }
        if (anger_level_ == 100) // if anger level reaches 100
        {
            cout << "The sorcerer's anger has reached level 100 which ends the game" << endl; // display sorcerer's max anger level message
            cout << "You lose!" << endl;
            break;
        }
        num_turns++; // increment number of turns by 1
        party_.checkFullness(); // check player fullness levels
        printStatusUpdate(); // print status update
        map_.displayMap(); // display map
    } while (choice < 1 || 6 < choice);
}

// function that displays the status of the game so far
// including rooms cleared, keys held, and the sorcerer's current anger level
// calls printPartyInfo() to get party info
//Patarmeters: none
//Returns : none
void Game::printStatusUpdate()
{
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << rooms_cleared_ << "| Keys: " << keys_ << "| Anger Level: " << getAngerLevel() << endl;
    party_.printPartyInfo(); // print party info
}

// prints game stats
void Game::endGame()
{
    cout << "       End game stats" << endl;
    cout << "+-----------------------------+" << endl;
    printStatusUpdate(); // print status update
    cout << "Number of spaces explored: " << spaces_explored << endl; // display spaces explored
    cout << "Number of monsters defeated: " << num_monsters_defeated << endl; // display monsters defeated
    cout << "Number of turns: " << num_turns << endl; // display turns taken
    cout << "+-----------------------------+" << endl;
}

// this function contains everything
// it makes the game run
// monster and riddles arrays are declared
// map is randomized
// intial merchant menu is called
// main menu is printed
// game runs until end of game
// parameters: none
// returns a void
void Game::gameLoop()
{
    Monster monstercontainer[6][4]; // monstercontainer is declared
    Riddles riddles_array[20]; // riddles array is declared
    randomizeMap(); // randomly adds 5 rooms and 5 npcs to the map
    openMerchantMenu(0); // opens the initial merchant menu with base prices
    printMenu(monstercontainer, riddles_array); // function prints the main menu for the game
    endGame(); // function prints the end game stats
}
