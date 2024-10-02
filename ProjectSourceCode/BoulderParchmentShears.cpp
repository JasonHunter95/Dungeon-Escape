#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

const char BOULDER = 'b';
const char PARCHMENT = 'p';
const char SHEARS = 's';

enum GameOutcome {WIN, LOSE, TIE};

void displayMenu()
{
    cout << "Enter (b) for BOULDER " << endl;
    cout << "Enter (p) for PARCHMENT " << endl;
    cout << "Enter (s) for SHEARS " << endl;
}

void displayInvalidChoiceMenu()
{
    cout << "Invalid Choice: " << endl;
    cout << "Please enter one of the following choices: " << endl;
    cout << "Enter (b) for BOULDER" << endl;
    cout << "Enter (p) for PARCHMENT" << endl;
    cout << "Enter (s) for SHEARS" << endl;
}

GameOutcome determineOutcome(char doorChoice, char playerChoice)
{
    if(doorChoice == playerChoice)
    {
        return TIE;
    }
    else if(doorChoice == BOULDER && playerChoice == PARCHMENT)
    {
        return WIN;
    }
    else if(doorChoice == PARCHMENT && playerChoice == SHEARS)
    {
        return WIN;
    }
    else if(doorChoice == SHEARS && playerChoice == BOULDER)
    {
        return WIN;
    }
    else
    {
        return LOSE;
    }       
}

// RNG for door's option (33%)
char getDoorInput()
{
    static const char options[] = {BOULDER, PARCHMENT, SHEARS};
    srand(time(0));
    int index = rand() % 3;
    return options[index];
}

// function to obtain player option
// prints menu that gives the player/party a choice
// takes player input an checks for validity
// if invalid reprint menu giving valid choices
char getPlayerInput()
{
    // print menu with choices
    displayMenu();
    char c;
    cin >> c;
    c = tolower(c); // convert to lowercase

    while (c != 'b' && c != 'p' && c != 's') // check for invalid inputs
    {
        // reprint menu if intial player choice is invalid
        displayInvalidChoiceMenu();
        cin >> c;
        c = tolower(c);
    }
    return c;
}

// run game here and compare door choice vs player choice
// game runs on loop until attempt counter reaches 0
// or if player wins
// if player wins, door access is granted
// if player loses, one member of the party is killed
bool displayGame()
{
    cout << "Welcome to Boulder, Parchment, Shears! A completely original take on Rock, Paper, Scissors!" << endl;
    cout << "Choose from the following options: " << endl;
    const int MAX_ATTEMPTS = 3;             // max attempts to beat the door
    bool hasWon = false;                    // bool to check if player has won
    for (int attempt_counter = MAX_ATTEMPTS; attempt_counter > 0; attempt_counter--) // loop through until results = 0
    {
        cout << "You have " << attempt_counter << " attempts to win " << endl;
        char door_choice = getDoorInput();               // obtain door choice
        char player_choice = getPlayerInput();           // obtain player choice
        GameOutcome outcome = determineOutcome(door_choice, player_choice); // determine outcome
            cout << "Door chose: " << door_choice << " "
                 << "Player chose: " << player_choice << endl;
        switch(outcome)
        {
            case WIN:
                hasWon = true;
                break;

            case LOSE:
                continue;

            case TIE:
                cout << "It's a tie!" << (attempt_counter > 1 ? " Play again." : "") << endl;
                continue;
        }
        break;
    }
    if(!hasWon)
    {
        cout << "You have not beaten the door, you will now lose a party member at random." << endl;
    }
    else 
    {
        cout << "You have gained access to the locked room despite lacking a key." << endl;
    }
    return hasWon;
}

// int main()
// {
//     displayGame();
//     return 0;
// }


