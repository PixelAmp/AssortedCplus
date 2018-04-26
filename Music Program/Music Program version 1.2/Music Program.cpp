//Main File (Music Program.cpp)
/*
Purpose: Designed to allow user to encrypt text into music and back again into text from music
*/
#ifndef MAIN_CPP
#define MAIN_CPP
#include "Music Body.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int choice;
    bool work = false;
    while (!work)
    {
        AGAIN: //jump label for if user wants to do something else

        cout << "What do you want to do? " << endl;
        cout << "Enter 1 to make text into music" << endl;
        cout << "Enter 2 to make music into text" << endl;
        cout << "Enter 3 to exit" << endl;
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3)
        {
            work = true;
        }
        if (!work)
        {
            cout << "error reading input, try again" << endl;
        }
        cin.clear();
        cin.ignore();
    }

    if (choice == 1) //text to music
    {
        toMusic music;
        music.inputChoice();
    }

    if (choice == 2) //music to text
    {
        toText text;
        text.inputChoice();
    }

    if (choice != 3)
    {

        cout << "Would you like to do anything else?" << endl;
        cout << "Enter 1 for yes" << endl;
        cout << "Enter anything else for no" << endl;

        cin >> choice;

            if (choice == 1)
            {
                work = false; //resets flag
                goto AGAIN; //jumps back and asks user if they want to do anything
            }
    }

    return 0;
}

#endif
