#ifndef FROM_MUSIC_H
#define FROM_MUSIC_H
#include <string>
#include <vector>
using namespace std;

class toText
{
private:
    string output; //holds output
    char music[17][142]; //17 down, 75 across
    string spaces; //holds character count
    int length;

public:
    toText(); //constructor
    void inputChoice(); //asks user how they want to input
    void fromDoc(); //grabs data in document to be translated
    void fromUser(); //allows the user to enter in values manually
    void defaultStaff(); //Creates a user interface for entering data
    void transChar(const int&); //translates numbers into characters and adds them to text
    void outputChoice(); //asks user how they want the output to be delivered
    void outputToFile(); //Outputs text to file
    void outputToScreen(); //outputs text to screen
    void readDoc(); //reads and organizes data from document
    void decode(int, bool); //decodes passed numbers and adds it to the output
    void makeSpace();
};

#endif
