#include "Monster.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size);


// parametrized constructor (takes in a string name and int challenge_rating)
Monster::Monster(string name, int challenge_rating)
{
    name_ = name;
    challenge_rating_ = challenge_rating;
}

// default constructor sets name to an empty string and sets challenge_rating_ to -1
Monster::Monster()
{
    name_ = "";
    challenge_rating_ = -1;
}

// getters/accessors
string Monster::getMonsterName()
{
    return name_;
}

int Monster::getChallengeRating()
{
    return challenge_rating_;
}

// setters/mutators
void Monster::setMonster(string name)
{
    name_ = name;
}

void Monster::setChallengeRating(int rating)
{
    challenge_rating_ = rating;
}

// function reads in monsters from "monsters.txt" file and stores them in a 2d array based on challenge rating
void Monster::storeMonster(string file_name, Monster Monsters[][4])
{
    int i = 0;
    char separ = ',';
    ifstream fin;
    fin.open(file_name); // open file
    string line;
    string temp_array[2];        // create temp array of size 2
    Monster monster = Monster(); // declare monster object
    if (fin.fail())              // check if file opened
    {
        cout << "" << endl; // returns empty string if file fails to open
    }
    for (int i = 0; i < 6; i++) // loop through 2d monster array for rating
    {
        for (int l = 0; l < 4; l++) // loop through 2d monster array for name
        {
            if (!(Monsters[5][0].getMonsterName() == "Sorcerer")) // if the monster name is not sorcerer
            {
                getline(fin, line); // call getline
                if (line.length() > 1 && !(isspace(line[0]))) // check for valid line to read
                {
                    split(line, separ, temp_array, 2); // call split function to separate name and rating
                }
                Monsters[i][l] = Monster(temp_array[0], stoi(temp_array[1])); // stoi because challenge_rating_ is an integer
            }
            else
            {
                monster = Monster(); // else monster is default constructor
            }
        }
    }
    fin.close(); // close file
}

// int main()
// {
//     Monster monster;
//     Monster monstercontainer[6][4];
//     string file_name = "monsters.txt";
//     monster.storeMonster(file_name, monstercontainer);
//     //cout << monstercontainer[0][4].getMonsterName() << endl;
//     //cout << monstercontainer[0][3].getChallengeRating() << endl;
//     for(int i = 0; i < 6; i++)
//     {
//         cout << "Room # " << i + 1 << endl;
//         for(int l = 0; l < 4; l++)
//         {
//             cout << monstercontainer[i][l].getMonsterName() << endl;
//             cout << monstercontainer[i][l].getChallengeRating() << endl;
//         }
//     }

//     return 0;
// }
