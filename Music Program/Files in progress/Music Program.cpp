//Main File (Music Program.cpp)
/*Raul Perez
Purpose: Designed to allow user to encrypt text into music
*/

#include <iostream>
#include "From Music.cpp"
#include "To Music.cpp"

using namespace std;

int main()
{
    int choice;
    bool work = false;
    while (!work)
    {
        cout << "What do you want to do? " << endl;
        cout << "Enter 1 to make text into music" << endl;
        cout << "Enter 2 to make music into text" << endl;
        cin >> choice;

        if (choice == 1 || choice == 2)
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
        text.inputChoice();
    }

    if (choice == 2) //music to text
    {
        toText text;
        music.inputChoice();
    }

    return 0;
}
