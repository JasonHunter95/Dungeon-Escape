#include <vector>
#include "Party.h"
#include "Player.h"
#include "Inventory.h"
#include "Monster.h"
#include "Merchant.h"
#include "Game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

Party::Party() // constructor asks for party leader and player names and stores them in the player vector
{
    cout << "Please enter party leader name: " << endl; // ask for party leader name
    cin >> username_;
    party.push_back(Player(username_));
    for (int i = 0; i < 4; i++) // loop through for party size
    {
        cout << "Please enter player name: " << endl; // ask for player name
        cin >> username_;
        party.push_back(Player(username_));
    }
}

// function prints names of party and their individual fullness levels
// returns void
// parameters: none
void Party::printPartyInfo()
{
    inventory_.printInventory(); // prints party's inventory
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;

    // sort party for fullness
    for (int i = 1; i < party.size(); i++) // the sorter that sorts the part by how much fullness left
    {
        for (int j = 1; j < party.size(); j++)
        {
            // comparison
            if (party[j].getFullness() < party[j + 1].getFullness())
            {
                // swap
                Player temp = party[j];
                party[j] = party[j + 1];
                party[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < party.size(); i++) // loops through party vector
    {
        cout << "| " << party[i].getName() << " | Fullness: " << party[i].getFullness() << endl; // prints party member names and respective fullness levels
    }
    cout << "+-------------+" << endl;
}

// function computes an algorithm that calculates whether or not a party kills a monster
// function gets various stats of the player and plugs them into the equation provided
// if the result is > 0, you won
// if the result is < 0, you lost
// returns a bool
// parameters: int monster_rating, string monster_name
bool Party::fightMonster(int monster_rating, string monster_name)
{
    srand(time(0));            // seed random function
    int r1 = (rand() % 6) + 1; // dice roll 1
    srand(time(0));            // seed random function
    int r2 = (rand() % 6) + 1; // dice roll 2
    // get monster_challenge_rating
    int a = inventory_.getArmour();                                                                                                                // get number/amount of armour
    int number_weapons = 0;                                                                                                                        // initialize number of weapons to 0
    number_weapons = ((inventory_.getClubs() + inventory_.getAxes() + inventory_.getRapiers() + inventory_.getSpears() + inventory_.getSwords())); // checking how many weapons we have
    if (party.size() < 5 && number_weapons > 0)
    {
        number_weapons = ((inventory_.getClubs() + inventory_.getAxes() + inventory_.getRapiers() + inventory_.getSpears() + inventory_.getSwords())); // if party size is less than 5 and weapons is greater than 0 it will make it the same as party size
    }
    if (number_weapons == 0) // if num of weapons are zero
    {
        cout << "You must surrender. You will lose a player from your party." << endl;
        party.pop_back();                      // removing a player from the party
        srand(time(0));                        // seed random function
        for (int i = 0; i < party.size(); i++) // can remove the fullness of a random player by 1
        {
            int fullness_chance = (rand() % 2) + 1;
            if (fullness_chance == 1)
            {
                party[i].setFullness(-1);
            }
        }
        return false; // returns false so we knwo they lost the battle
    }
    else
    {
        attack = number_weapons + (1 * (inventory_.getRapiers())) + (2 * (inventory_.getAxes())) + (3 * (inventory_.getSwords())); // gets weapon count and party size
    }
    // don't know how to compute this for each party member having different weapons
    if (a == 0)
    {
        battle_result = ((r1 * (attack + number_weapons)) - ((r2 * monster_rating))); // equation with no armor
    }
    else if (a > 0)
    {
        battle_result = (r1 * (attack + number_weapons)) - ((r2 * monster_rating) / a); // equation to compute battle result with armour
    }
    if (battle_result > 0) // checking if you defeated the monsters
    {
        updated_gold = (10 * monster_rating);
        ingreds = (5 * monster_rating);
        inventory_.setGold(updated_gold);
        inventory_.setIngredients(ingreds); // rewards you get and updates party inventory
        cout << "You defeated " << monster_name << " and have gained " << updated_gold << " gold "
             << "and " << ingreds << " ingredients." << endl; // cout statement saying everything you have won
        // inventory_.printInventory();
        srand(time(0));                        // seed the randomizer
        for (int i = 0; i < party.size(); i++) // can lower the fullness of a random player by 1
        {
            int fullness_chance = (rand() % 2) + 1;
            if (fullness_chance == 1)
            {
                party[i].setFullness(-1);
            }
        }
        return true; // returning true to say the battle was won
    }
    else if (battle_result <= 0) // loseing the battle
    {
        current_gold = inventory_.getGold();   // getting the gold
        updated_gold = current_gold / -4;      // dividing the gold by -4 to subtract that amount because you lost
        inventory_.setGold(updated_gold);      // updating the gold
        srand(time(0));                        // seeding it
        chance = ((rand() % 30) + 1);          // random numb from 1 to 30
        if (inventory_.getIngredients() <= 30) // lose all ingredients if you have
        {
            ingreds = inventory_.getIngredients();
            inventory_.setIngredients(-ingreds);
        }
        else
        {
            inventory_.setIngredients(-chance); // you will lose the ingreds according to the chance
        }
        for (int i = 0; i < party.size(); i++)
        {
            if (inventory_.getArmour() > i) // if player has armour they have better odds at surviving
            {
                srand(time(0));
                chance = (rand() % 20) + 1;
                if (chance == 1)
                {
                    cout << "You have lost a member of your party" << endl;
                    party.pop_back(); // removing a player from the party
                }
            }
            else // no amrour worse odds at surviving
            {
                srand(time(0));
                chance = (rand() % 10) + 1;
                if (chance == 1)
                {
                    cout << "You have lost a member of your party" << endl;
                    party.pop_back(); // removing a player from the party.
                }
            }
        }
    }
    for (int i = 0; i < party.size(); i++) // chance to lose fullness for each party memeber
    {
        srand(time(0));
        int fullness_chance = (rand() % 2) + 1;
        if (fullness_chance == 1)
        {
            party[i].setFullness(-1);
        }
    }
    return false; // returns false because you lost the fight
}

// function that updates fullness
void Party::decreaseFullness()
{
    // used this to check if our cook&Eat function worked
    srand(time(0));
    for (int i = 0; i < party.size(); i++)
    {
        int fullness_chance = (rand() % 5) + 1; // generate 20% chance
        if (fullness_chance == 1)               // if 20% chance is hit
        {
            party[i].setFullness(-1); // reduce player fullness by 1
        }
    }
}

// function that provides functionally for cooking food using ingredients and adding fullness
// prints menu with cooking options
// adds functionality for breaking cookware
// computes ingredients to meals ratio and updates party fullness levels
// returns void
// parameters: none
void Party::cookAndEat()
{
    inventory_.printInventory();                                   // print inventory
    cout << "Which cooking supply would you like to use?" << endl; // offer cooking supply options
    cout << "1. Pots" << endl;
    cout << "2. Frying pan" << endl;
    cout << "3. Cauldron" << endl;
    cin >> choice; // get user choice
    cout << inventory_.getPots() << endl;
    if (choice == 1) // user selects pots
    {
        if (inventory_.getPots() > 0) // check if party has any pots in inventory
        {
            amount = 6;                            // intializing it to 6 so it goes into while loop
            ingreds = inventory_.getIngredients(); // update and get ingredients
            while ((amount % 5) != 0 || amount > ingreds)
            {
                cout << "How many ingredients do you want to cook? Please choose a multiple of 5" << endl;
                cin >> amount;
                if (amount > ingreds) // check if proper amount of ingredients are held
                {
                    cout << "You don't have enough ingredients" << endl; // display lack of ingredients message
                }
            }
            inventory_.setIngredients(-amount); // set ingredients to new amount once used
            amount = (amount / 5);              // ingredients are used in increments of 5
            for (int i = 0; i < 5; i++)
            {
                party[i].setFullness(amount); // update player fullness by amount of ingredients cooked
            }
            srand(time(0));            // seed random function
            chance = (rand() % 4) + 1; // 25% chance to break
            if (chance == 1)           // if 25% chance is hit
            {
                cout << "Your pot has broken" << endl; // display message
                inventory_.setPots(-1);                // reduce pot count by 1
            }
        }
        else
        {
            cout << "You don't have the necessary items to cook" << endl; // display lack of cooking equipment message
        }
    }
    else if (choice == 2) // user selects pans
    {
        if (inventory_.getPans() > 0) // check if party has any pans in inventory
        {
            amount = 6;
            ingreds = inventory_.getIngredients(); // update and get ingredients
            while ((amount % 5) != 0 || amount > ingreds)
            {
                cout << "How many ingredients do you want to cook? Please choose a multiple of 5" << endl;
                cin >> amount;
                if (amount > ingreds) // check if proper amount of ingredients are held
                {
                    cout << "You don't have enough ingredients" << endl; // display lack of ingredients message
                }
            }
            inventory_.setIngredients(-amount); // set ingredients to new amount once used
            amount = (amount / 5);              // ingredients are used in increments of 5
            for (int i = 0; i < 5; i++)         // loop through party to update fullness
            {
                party[i].setFullness(amount);
            }
            srand(time(0));             // seed random function
            chance = (rand() % 10) + 1; // 10% chance to break
            if (chance == 1)            // if 10% chance is hit
            {
                cout << "Your pan has broken" << endl; // display message
                inventory_.setPans(-1);                // reduce pan count by 1
            }
        }
        else
        {
            cout << "You don't have the necessary items to cook" << endl; // display lack of cooking equipment message
        }
    }
    else if (choice == 3) // user selects cauldrons
    {
        if (inventory_.getCauldrons() > 0) // check if party has any cauldrons in inventory
        {
            amount = 6;
            ingreds = inventory_.getIngredients();
            while ((amount % 5) != 0 || amount > ingreds)
            {
                cout << "How many ingredients do you want to cook? Please choose a multiple of 5" << endl;
                cin >> amount;
                if (amount > ingreds) // check if proper amount of ingredients are held
                {
                    cout << "You don't have enough ingredients" << endl; // display lack of ingredients message
                }
            }
            inventory_.setIngredients(-amount); // set ingredients to new amount once used
            amount = (amount / 5);              // ingredients are used in increments of 5
            for (int i = 0; i < 5; i++)         // loop through party to update fullness
            {
                party[i].setFullness(amount); // update player fullness
            }
            srand(time(0));
            chance = (rand() % 50) + 1; // 2% chance to break
            if (chance == 1)            // if 2% chance is hit
            {
                cout << "Your cauldron has broken" << endl;
                inventory_.setCauldrons(-1); // reduce cauldron count by 1
            }
        }
        else
        {
            cout << "You don't have the necessary items to cook" << endl; // display lack of cooking equipment message
        }
    }
}

// function finds treasure based on number of rooms the player has cleared
// updates inventory with new treasure found
// returns void
// parameters: int num_rooms_cleared
void Party::findTreasure(int num_rooms_cleared)
{
    if (num_rooms_cleared == 1 || num_rooms_cleared == 0) // when you investigate you get a treasure according to the amount of rooms cleared
    {
        inventory_.addRings(1); // adding one to the inventory
    }
    else if (num_rooms_cleared == 2)
    {
        inventory_.addNecklaces(1); // adding one to the inventory
    }
    else if (num_rooms_cleared == 3)
    {
        inventory_.addBracelets(1); // adding one to the inventory
    }
    else if (num_rooms_cleared == 4)
    {
        inventory_.addCirclets(1); // adding one to the inventory
    }
    else if (num_rooms_cleared == 5)
    {
        inventory_.addGoblets(1); // adding one to the inventory
    }
}

// function computes the various misfortunes that may occur throughout the game
// possibility of getting robbed
// losing health
// returns void
// parameters: none
void Party::handleMisfortune()
{
    srand(time(0));
    int misfortune = (rand() % 100) + 1;
    if (misfortune <= 30) // 30% team is robbed lose 10kg ingreds. 1 cookware and 1 armor
    {
        if (inventory_.getIngredients() < 10) // if the ingredients are less than 10 you will loss all remaining ingredients
        {
            ingreds = inventory_.getIngredients();
            inventory_.setIngredients(-ingreds);
        }
        else
        {
            inventory_.setIngredients(-10); // it will subtract 10 ingredients from your inventory
        }
        if (inventory_.getArmour() > 0)
        {
            inventory_.setArmour(-1); // you lose one armour if you have an armour to lose
        }
        if ((inventory_.getCauldrons()) > 0 || (inventory_.getPans() > 0) || (inventory_.getPots() > 0))
        {
            if ((inventory_.getCauldrons()) > 0 && (inventory_.getPans() > 0) && (inventory_.getPots() > 0)) // if you have all 3 cookwares you will lose one at random
            {
                srand(time(0));
                int random_cookware = (rand() % 3) + 1;
                if (random_cookware == 1)
                {
                    inventory_.setPots(-1);
                }
                else if (random_cookware == 2)
                {
                    inventory_.setPans(-1);
                }
                else if (random_cookware == 3)
                {
                    inventory_.setCauldrons(-1);
                }
            }
            else if (inventory_.getPots() > 0) // checking which cookwares you have and then you will lose one at random
            {
                if (inventory_.getPans() > 0)
                {
                    srand(time(0));
                    int random_cookware = (rand() % 2) + 1;
                    if (random_cookware == 1)
                    {
                        inventory_.setPots(-1);
                    }
                    else if (random_cookware == 2)
                    {
                        inventory_.setPans(-1);
                    }
                }
                else if (inventory_.getCauldrons() > 0) // checking which cookwares you have and then you will lose one at random
                {
                    srand(time(0));
                    int random_cookware = (rand() % 2) + 1;
                    if (random_cookware == 1)
                    {
                        inventory_.setPots(-1);
                    }
                    else if (random_cookware == 2)
                    {
                        inventory_.setCauldrons(-1);
                    }
                }
                else
                {
                    inventory_.setPots(-1);
                }
            }

            else if (inventory_.getPans() > 0) // checking which cookwares you have and then you will lose one at random
            {
                if (inventory_.getPots() > 0)
                {
                    srand(time(0));
                    int random_cookware = (rand() % 2) + 1;
                    if (random_cookware == 1)
                    {
                        inventory_.setPots(-1);
                    }
                    else if (random_cookware == 2)
                    {
                        inventory_.setPans(-1);
                    }
                }
                else if (inventory_.getCauldrons() > 0) // checking which cookwares you have and then you will lose one at random
                {
                    srand(time(0));
                    int random_cookware = (rand() % 2) + 1;
                    if (random_cookware == 1)
                    {
                        inventory_.setPans(-1);
                    }
                    else if (random_cookware == 2)
                    {
                        inventory_.setCauldrons(-1);
                    }
                }
                else
                {
                    inventory_.setPans(-1);
                }
            }
            else if (inventory_.getCauldrons() > 0) // checking which cookwares you have and then you will lose one at random
            {
                if (inventory_.getPans() > 0)
                {
                    srand(time(0));
                    int random_cookware = (rand() % 2) + 1;
                    if (random_cookware == 1)
                    {
                        inventory_.setCauldrons(-1);
                    }
                    else if (random_cookware == 2)
                    {
                        inventory_.setPans(-1);
                    }
                }
                else if (inventory_.getPots() > 0)
                {
                    srand(time(0));
                    int random_cookware = (rand() % 2) + 1;
                    if (random_cookware == 1)
                    {
                        inventory_.setPots(-1);
                    }
                    else if (random_cookware == 2)
                    {
                        inventory_.setCauldrons(-1);
                    }
                }
                else
                {
                    inventory_.setCauldrons(-1);
                }
            }
        }
        cout << "You have been robbed! of 10 ingredients and a random piece of cookware" << endl;
    }
    else if (misfortune > 30 && misfortune <= 40) // 10% 1 weapon or armor breakes
    {
        if (inventory_.getArmour() > 0)
        {
            inventory_.setArmour(-1); // checking that you have atleats one armour
        }
        if ((inventory_.getClubs() > 0) || (inventory_.getAxes() > 0) || (inventory_.getSpears() > 0) || (inventory_.getSwords() > 0) || (inventory_.getRapiers() > 0)) // checking you atleast have a weapon
        {
            if ((inventory_.getClubs() > 0) && (inventory_.getAxes() > 0) && (inventory_.getSpears() > 0) && (inventory_.getSwords() > 0) && (inventory_.getRapiers() > 0)) // if you have each weapon it will remove one randomly
            {
                srand(time(0));
                int rand_weap = (rand() % 5) + 1;
                if (rand_weap == 1)
                {
                    inventory_.setClubs(-1);
                }
                else if (rand_weap == 2)
                {
                    inventory_.setAxes(-1);
                }
                else if (rand_weap == 3)
                {
                    inventory_.setSpears(-1);
                }
                else if (rand_weap == 4)
                {
                    inventory_.setSwords(-1);
                }
                else if (rand_weap == 5)
                {
                    inventory_.setRapiers(-1);
                }
            }
            else
            {
                int counter = 0; // seeding and initializing my varaibles
                srand(time(0));
                while (counter < 100) // will remove a random weapon but checking if you have one to remove otherwise it will run again until it finds a weapon it can remove
                {
                    int rand_weap = (rand() % 5) + 1;
                    if (rand_weap == 1)
                    {
                        if (inventory_.getClubs() > 0)
                        {
                            inventory_.setClubs(-1);
                            break;
                        }
                    }
                    else if (rand_weap == 2)
                    {
                        if (inventory_.getAxes() > 0)
                        {
                            inventory_.setAxes(-1);
                            break;
                        }
                    }
                    else if (rand_weap == 3)
                    {
                        if (inventory_.getSpears() > 0)
                        {
                            inventory_.setSpears(-1);
                            break;
                        }
                    }
                    else if (rand_weap == 4)
                    {
                        if (inventory_.getSwords() > 0)
                        {
                            inventory_.setSwords(-1);
                            break;
                        }
                    }
                    else if (rand_weap == 5)
                    {
                        if (inventory_.getRapiers() > 0)
                        {
                            inventory_.setRapiers(-1);
                            break;
                        }
                    }
                }
            }
            cout << "A piece of armour and a weapon have broken" << endl;
        }
        else if (misfortune > 40 && misfortune <= 70) // 30% 1 player loses 10 fullness
        {
            srand(time(0));
            int rand_damage = (rand() % party.size()) + 1; // getting random number from the range of the player size
            party[rand_damage].setFullness(-10);           // then removing 10 fullness from that player
            cout << "A player has lost 10 fullness" << endl;
        }
        else if (misfortune > 70 && misfortune <= 100) // 30% 1 player gets locked
        {
            if (party.size() == 1) // if there is only 1 player left then it will remove that player
            {
                party.pop_back();
            }
            else // otherwise it will remove a rnadom player from the party
            {
                srand(time(0));
                int rand_locked = (rand() % party.size()) + 1;
                party.erase(party.begin() + rand_locked);
            }
            cout << "A player has been locked in the previous room" << endl;
        }
    }
}

// function that checks player fullness
// if player fullness is 0, the player is removed from the party
// returns void
// parameters: none
void Party::checkFullness()
{
    for (int i = 0; i < party.size(); i++) // if any of the players fullness gets to 0 then it will remove then from the party
    {
        if (party[i].getFullness() == 0)
        {
            cout << party[i].getName() << " has died." << endl;
            party.erase(party.begin() + i);
        }
    }
}

// function that purchases various items from the merchant
// returns void
// parameters: string item_name, int room_number
void Party::buyItem(string item_name, int room_number)
{
    price.Merchant_updater(room_number); // updating the merchants prices according to how many room_numbers you have cleared
    if (item_name == "I")                // if user wants to buy ingredients
    {
        amount = -1;
        while (amount < 0)
        {
            cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
            cin >> amount;
            break;
        }
        if ((amount % 5) == 0 && amount != 0)
        {
            cout << "You want to buy " << amount << " kg of ingredients for " << amount << " Gold? (y/n)" << endl;
            cin >> result;

            if (result == 'y') // making sure the user buys ingredients in increments of 5
            {
                item_price = price.getIngredientsPrice(); // getting the price of ingredients
                updated_gold = (item_price * amount);     // how much gold you are going to use
                if (updated_gold <= inventory_.getGold()) // making sure you have enough gold to buy the item
                {
                    inventory_.setGold(-updated_gold);
                    inventory_.setIngredients(amount);
                    inventory_.printInventory(); // updating the amount in the inventory and how much gold you have thrn printing your inventory
                }
                else
                {
                    cout << "You can't afford that" << endl;
                    inventory_.printInventory(); // prints inventory
                }
            }
        }
    }
    else if (item_name == "P") // if you're buying pots
    {
        amount = -1;
        while (amount < 0) // setting amount equal to -1 because they may have bought something before hand and set amounts value to something else
        {
            cout << "How many would you like?(Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
        }                                         // runs until we get a valid answer
        item_price = price.getPotPrice();         // getting the price
        updated_gold = (item_price * amount);     // how much gold you're going to spend
        if (updated_gold <= inventory_.getGold()) // if you can afford the item and updates gold and inventory
        {
            inventory_.setGold(-updated_gold);
            inventory_.setPots(amount);
            inventory_.printInventory(); // print inventory
        }
        else
        {
            cout << "You can't afford that" << endl;
            inventory_.printInventory(); // print inventory
        }
    }
    else if (item_name == "F") // if you're buying frying pans
    {
        amount = -1;
        while (amount < 0) // reupdating amount because we are resuing and may already have a value
        {
            cout << "How many would you like?(Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
        }                                         // runs until user enters a valid input
        item_price = price.getPanPrice();         // getting the price of the item
        updated_gold = (item_price * amount);     // getting how much gold its going to cost
        if (updated_gold <= inventory_.getGold()) // checks if you afford the item. updating the gold how many of the item you have and then prints out inventory
        {
            inventory_.setGold(-updated_gold);
            inventory_.setPans(amount);
            inventory_.printInventory(); // print inventory
        }
        else
        {
            cout << "You can't afford that" << endl;
            inventory_.printInventory();
        }
    }
    else if (item_name == "Ca") // checking which item you want to buy
    {
        amount = -1;       // reupdating the value because we are resuing
        while (amount < 0) // runs until user enters a valid input
        {
            cout << "How many would you like?(Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
        }
        item_price = price.getCauldronPrice(); // getting the price
        updated_gold = (item_price * amount);  // how much gold it will cost
        if (updated_gold >= 0)                 // checking if you can afford it and then updates gold the amount of items you have then prints inventory
        {
            inventory_.setGold(-updated_gold);
            inventory_.setCauldrons(amount);
            inventory_.printInventory(); // print inventory
        }
        else
        {
            cout << "You can't afford that" << endl;
            inventory_.printInventory(); // print inventory
        }
    }
    else if (item_name == "Cl") // checking which item you wanna buy
    {
        amount = -1;       // reupdating value because we are resing it
        while (amount < 0) // runs until user enters a valid answer
        {
            cout << "How many would you like?(Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
        }
        item_price = price.getClubPrice();        // getting the price of item
        updated_gold = (item_price * amount);     // getting how much it will cost
        if (updated_gold <= inventory_.getGold()) // checking you have enough gold to buy item then updating your gold and amount of the item then prints out inventory
        {
            inventory_.setGold(-updated_gold); // update inventory with updated gold
            inventory_.setClubs(amount);       // updates amount
            inventory_.printInventory();       // print inventory
        }
        else
        {
            cout << "You can't afford that" << endl;
            inventory_.printInventory(); // print inventory
        }
    }
    else if (item_name == "Sp") // which item you want to buy
    {
        amount = -1;       // updating because we are resuing
        while (amount < 0) // will run until user enters valid answer
        {
            cout << "How many would you like?(Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
        }
        item_price = price.getSpearPrice();   // getting price
        updated_gold = (item_price * amount); // getting how much it will cost
        if (updated_gold <= inventory_.getGold())
        {
            inventory_.setGold(-updated_gold); // update inventory with updated gold
            inventory_.setSpears(amount);      // updates item amount
            inventory_.printInventory();       // prints inventory
        }
        else
        {
            cout << "You can't afford that" << endl;
            inventory_.printInventory(); // print inventory
        }
    }
    else if (item_name == "R") // checking which item you want to buy
    {
        amount = -1;       // reupdating the amount
        while (amount < 0) // runs until user enters a valid response
        {
            cout << "How many would you like?(Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
        }
        item_price = price.getRapierPrice();      // item price
        updated_gold = (item_price * amount);     // update gold
        if (updated_gold <= inventory_.getGold()) // checking if you can afford item
        {
            inventory_.setGold(-updated_gold); // update inventory with updated gold
            inventory_.setRapiers(amount);
            inventory_.printInventory(); // print inventory
        }
        else
        {
            cout << "You can't afford that" << endl;
            inventory_.printInventory(); // print inventory
        }
    }
    else if (item_name == "Ax")
    {
        amount = -1;
        while (amount < 0)
        {
            cout << "How many would you like?(Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
        }
        item_price = price.getAxePrice();
        updated_gold = (item_price * amount); // update gold
        if (updated_gold <= inventory_.getGold())
        {
            inventory_.setGold(-updated_gold); // update inventory with updated gold
            inventory_.setAxes(amount);
            inventory_.printInventory(); // print inventory
        }
        else
        {
            cout << "You can't afford that" << endl;
            inventory_.printInventory(); // print inventory
        }
    }
    else if (item_name == "Sw")
    {
        amount = -1;
        while (amount < 0)
        {
            cout << "How many would you like?(Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
        }
        item_price = price.getSwordPrice();
        updated_gold = (item_price * amount); // update gold
        if (updated_gold <= inventory_.getGold())
        {
            inventory_.setGold(-updated_gold); // update inventory with updated gold
            inventory_.setSwords(amount);
            inventory_.printInventory(); // print inventory
        }
        else
        {
            cout << "You can't afford that" << endl;
            inventory_.printInventory(); // print inventory
        }
    }
    else if (item_name == "A")
    {
        amount = -1;
        while (amount < 0)
        {
            cout << "How many would you like?(Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
        }
        item_price = price.getArmourPrice();  // get armour price
        updated_gold = (item_price * amount); // update gold
        if (updated_gold <= inventory_.getGold())
        {
            inventory_.setGold(-updated_gold); // update inventory with updated gold
            inventory_.setArmour(amount);      // update armour
            inventory_.printInventory();       // print inventory
        }
        else
        {
            cout << "You can't afford that" << endl; // display message
            inventory_.printInventory();             // print inventory
        }
    }
}

// function that allows the player to sell treasure that was found throughout the game
// checks if player has proper items to sell
// sells items and updates gold in inventory
// returns void
// parameters: string item_name
void Party::sellTreasure(string item_name)
{
    if ("R" == item_name) // if item is a ring
    {
        amount = inventory_.getRings(); // call getter
        if (amount > 0)                 // if there are any rings
        {
            item_price = price.getRingPrice();    // get ring price
            updated_gold = (item_price * amount); // update gold
            inventory_.sellRings(amount);         // sell rings
            inventory_.setGold(updated_gold);     // update inventory with updated gold
            inventory_.printInventory();          // print inventory
        }
        else
        {
            cout << "Unfortunately you don't have any Rings to sell" << endl; // display message that tells the user they dont have the item to sell
        }
    }
    else if ("N" == item_name) // if item is a necklace
    {
        amount = inventory_.getNecklaces(); // call getter
        if (amount > 0)                     // if there are any necklaces
        {
            item_price = price.getNecklacePrice(); // get necklace price
            updated_gold = (item_price * amount);  // update gold
            inventory_.sellNecklaces(amount);      // sell necklaces
            inventory_.setGold(updated_gold);      // update inventory with updated gold
            inventory_.printInventory();           // print inventory
        }
        else
        {
            cout << "Unfortunately you don't have any Necklaces to sell" << endl; // display message that tells the user they dont have the item to sell
        }
    }
    else if ("B" == item_name) // if item is a bracelet
    {
        amount = inventory_.getBracelets(); // call getter
        if (amount > 0)                     // if there are any bracelets
        {
            item_price = price.getBraceletPrice(); // get bracelet price
            updated_gold = (item_price * amount);  // update gold
            inventory_.sellBracelets(amount);      // sell bracelets
            inventory_.setGold(updated_gold);      // update inventory with updated gold
            inventory_.printInventory();           // print inventory
        }
        else
        {
            cout << "Unfortunately you don't have any Bracelets to sell" << endl; // display message that tells the user they dont have the item to sell
        }
    }
    else if ("C" == item_name) // if item is a circlet
    {
        amount = inventory_.getCirclets(); // call getter
        if (amount > 0)                    // if there are any circlets
        {
            item_price = price.getCircletPrice(); // get circlet price
            updated_gold = (item_price * amount); // update gold
            inventory_.sellCirclets(amount);      // sell circlets
            inventory_.setGold(updated_gold);     // update inventory with updated gold
            inventory_.printInventory();          // print inventory
        }
        else
        {
            cout << "Unfortunately you don't have any Circlets to sell" << endl; // display message that tells the user they dont have the item to sell
        }
    }
    else if ("G" == item_name) // if item is a goblet
    {
        amount = inventory_.getGoblets(); // call getter
        if (amount > 0)                   // if there are any goblets
        {
            item_price = price.getGobletPrice();  // get goblet price
            updated_gold = (item_price * amount); // update gold
            inventory_.sellGoblets(amount);       // sell goblets
            inventory_.setGold(updated_gold);     // update inventory with updated gold
            inventory_.printInventory();          // print inventory
        }
        else
        {
            cout << "Unfortunately you don't have any Goblets to sell" << endl; // display message that tells the user they dont have the item to sell
        }
    }
}

// function that checks if the party size is 0
// returns a bool
// parameters: none
bool Party::checkPartyStats()
{
    if (party.size() == 0) // if party size is 0
    {
        return false;
    }
    else
    {
        return true;
    }
}

// function that removes a player from party vector
// returns void
// parameters: none
void Party::losePlayer()
{
    party.pop_back(); // remove player from back of the player vector
}

// int main()
// {
//     // //Player player;
//     // //Merchant merchant;
//     // Inventory inventory;
//     // Party party;
//     // party.buyItem("P");
//     // //inventory.printInventory();
//     // //int index = 0;
//     // //party.printPartyInfo();
//     // //cout << name << endl;
//     // //result.getName();
//     // return 0;

// }