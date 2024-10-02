#include "Riddles.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size)
{
    int num_elements = 0;
    // delimiter is ""
    string new_string = "";

    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == separator)
        {
            // if delimiter is not found return -1;
            if (new_string != "")
            {
                if (num_elements == arr_size)
                {
                    return -1;
                }
                arr[num_elements++] = new_string;
                new_string = "";
            }
        }
        else
        {
            new_string += input_string[i];
        }
    }
    if (new_string != "")
    {
        if (num_elements == arr_size)
        {
            return -1;
        }
        arr[num_elements++] = new_string;
        new_string = "";
    }

    return num_elements;
}

Riddles::Riddles() // default constructor
{
    riddle_ = "";
    answer_ = "";
}

Riddles::Riddles(string riddle, string answer) // parametrized constructor
{
    riddle_ = riddle;
    answer_ = answer;
}

void Riddles::setRiddle(string riddle)
{
    riddle_ = riddle;
}

void Riddles::setAnswer(string answer)
{
    answer_ = answer;
}

string Riddles::getRiddle() // obtain riddle
{
    return riddle_;
}
string Riddles::getAnswer() // obtain answer
{
    return answer_;
}

// generate random riddle from 1 to 20
// return random riddle
int Riddles::randomRidNum()
{
    srand(time(0));                       // seed random function
    int rand_riddle_ = (rand() % 20) + 1; // calculate 5% chance
    return rand_riddle_;                  // return random riddle generated
}

// read in riddle from file and store it in riddles array
void storeRiddle(string file_name, Riddles riddles[])
{
    int i = 0;
    char separ = '~';
    ifstream file;
    file.open(file_name); // open file
    string line;
    string temp_array[2];
    if (file.fail()) // check if file is open
    {
        cout << "" << endl;
    }
    while (getline(file, line)) // loop through file line by line
    {
        if (line.length() > 1 && !(isspace(line[0])))
        {
            split(line, separ, temp_array, 2); // split line between riddle/hint and answer
        }
        Riddles riddle = Riddles(temp_array[0], temp_array[1]);
        riddles[i] = riddle;
        i++;
    }
    file.close(); // close file
}

// int main()
// {
//     Riddles riddle_array[20];
//     string file_name = "riddles.txt";
//     Riddles riddles;
//     int result = riddles.randomRidNum();
//     storeRiddle(file_name, riddle_array);
//     cout << riddle_array[result].getRiddle() << endl;
//     cout << riddle_array[result].getAnswer() << endl;
// }