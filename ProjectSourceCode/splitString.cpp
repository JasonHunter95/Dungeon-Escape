#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;


// function splits string into pieces when it reaches a delimiter,
// and fills an array with the pieces until the array is full.
// 
int split(string input_string, char separator, string arr[], int arr_size)
{
    int num_elements = 0;
    //delimiter is ""
    string new_string = "";

    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == separator)
        {
            //if delimiter is not found return -1;
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
