#ifndef RIDDLES_H
#define RIDDLES_H

#include <iostream>
#include <string>

using namespace std;

class Riddles
{
private:
    string riddle_;
    string answer_;
    int rand_riddle_ = 0;
    int riddle = 0;

public:
    Riddles();                             // default constructor
    Riddles(string riddle, string answer); // parametrized constructor
    int randomRidNum();
    void storeRiddle(string file_name, Riddles array);

    // setters/mutators
    void setRiddle(string riddle);
    void setAnswer(string answer);

    // getters/accessors
    string getRiddle();
    string getAnswer();
};

#endif