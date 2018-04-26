//Body File (music.cpp)
/*Raul Perez
Purpose: holds all of the code for the program to actually work
*/
#ifndef Family_C
#define Family_C
#include "From Music.h"
#include "To Music.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//From music code

toText::toText() //constructor
{
    output = spaces = "";
    length = 0;
}

void toText::inputChoice() //asks user how they want to input
{
    string name;
    int choice;
    bool work = false;
    while (!work)
    {
        cout << "How do you want to input? " << endl;
        cout << "Enter 1 to read from document" << endl;
        cout << "Enter 2 to enter data manually " << endl;
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

    if (choice == 1) //read from document
    {
        fromDoc();
    }

    if (choice == 2) //read from input
    {
        fromUser();
    }
}

void toText::fromDoc() //grabs data in document to be translated
{
    readDoc();

    char hold,sharp;
    int across = 0;
    int total = (length/3) ; //total amount of sts of notes in piece

    for (int note = 0; note < total ; note++) //program moves one note at a time
    {
        for (int down = 0; down < 16; down++) //makes it so that it goes to the next bar line
        {
            across = (note*3); //sets the checkpoint to look for the next note

                for (int next = 0; next < 3; next++) //looks through 3 characters at a time looking for a note
                {
                    hold = music[down][across];
                    if (hold == 'O') //finds the note
                    {
                        int fix = (down + 6); //fixes the code because I originally had numbers, makes it z = 0

                        sharp = music[down][across-1];

                        if (sharp == '#') //if it is sharp
                        {
                            decode(fix, true);
                        }
                        else
                        {
                            decode(fix, false);
                        }
                    }
                    across++; //moves onto the next character
                }
        }
    }

    makeSpace();

    outputChoice();
}

void toText::decode(int down, bool sharp) //decodes passed numbers and adds it to the output
{
    switch (down)
    {
            break;
        case 6:
                output.push_back('z');
            break;
        case 7:
                output.push_back('j');
            break;
        case 8:
            if (sharp)
            {
                output.push_back('v');
            }
            else
            {
                output.push_back('p');
            }
            break;
        case 9:
            if (sharp)
            {
                output.push_back('c');
            }
            else
            {
                output.push_back('y');
            }
            break;
        case 10:
                output.push_back('m');
            break;
        case 11:
            if (sharp)
            {
                output.push_back('w');
            }
            else
            {
                output.push_back('d');
            }
            break;
        case 12:
            if (sharp)
            {
                output.push_back('s');
            }
            else
            {
                output.push_back('n');
            }
            break;
        case 13:
            if (sharp)
            {
                output.push_back('o');
            }
            else
            {
                output.push_back('t');
            }
            break;
        case 14:
                output.push_back('e');
            break;
        case 15:
            if (sharp)
            {
                output.push_back('a');
            }
            else
            {
                output.push_back('h');
            }
            break;
        case 16:
            if (sharp)
            {
                output.push_back('r');
            }
            else
            {
                output.push_back('i');
            }
            break;
        case 17:
                output.push_back('l');
            break;
        case 18:
            if (sharp)
            {
                output.push_back('u');
            }
            else
            {
                output.push_back('g');
            }
            break;
        case 19:
            if (sharp)
            {
                output.push_back('f');
            }
            else
            {
                output.push_back('b');
            }
            break;
        case 20:
            if (sharp)
            {
                output.push_back('k');
            }
            else
            {
                output.push_back('q');
            }
            break;
        case 21:
                output.push_back('x');
            break;
    }
}

void toText::readDoc()  //reads and organizes data from document
{
    ifstream data;
    string fileName;
    int count=0;
    char text;
    int down = 0;
    int across = 0; //sets across to zero

    cout << "Enter a file name: (music.txt)" << endl;
    getline(cin,fileName);

    string check;

    for (int i = (fileName.size() -4); i <= fileName.size(); i++) //checks if user added a .txt to the file name
    {
        check.push_back(fileName[i]);
    }

    if (check != ".txt") //adds .txt to end of fileName
    {
        fileName.push_back('.');
        fileName.push_back('t');
        fileName.push_back('x');
        fileName.push_back('t');
    }

    data.open(fileName.data());

    data >> noskipws >> text;

    music[0][0] = text;
    across++; //adds one to across

    for (int down = 0; down < 16 ; down++) //sorts data into 22 layer array in order to be read
        {
            for (int treble = 0; treble < 8 ; treble++)//skips over the treble cleft
            {
                data >> noskipws >> text;
                music[down][across] = text;
                across++;
            }


            while (text != '|') //fills array with the contents of the line, prevents overfilling
            {
                data >> noskipws >> text;
                music[down][across] = text;
                across++; //incements amount of  letters read
                if (across > 143)
                {
                    cout << "error, overflow" << endl;
                }
            }
            length = across;
            across = 0; //resets the count for how far across it has gone
        }
            length--; //subtracts one from the length because of reasons

        while(!data.eof()) //gets the data for the spaces
        {
            data >> noskipws >> text;
            spaces.push_back(text);
        }

    data.close();
}

void toText::makeSpace()
{


    int total = ((length/3)) ; //total amount of sts of notes in piece

    for(int across = 0; across <= (total+9); across ++) //only checks the amount of characters that I have
    {
        char text = spaces[across];
        if (text == '\t')
        {
            output.insert(across-1, " "); //inserts a space
        }
    }
}

void toText::fromUser() //allows the user to enter in values manually
{

    cout << "**Warning the output of this program will not contain spaces!" << endl;
    int input;
    int character;
    vector<int> num;
    defaultStaff();
    cout << "Please press enter after each number" << endl;
    cout << "Enter 0 when done" << endl;
    while (input != 0)
    {
        cin >> input;

        if (input > 0 && input <= 26)
        {
            transChar(input);
        }

        else if (input < 0 || input > 26)
        {
            cout << "Error reading input" << endl;
        }

        cin.clear();
        cin.ignore();
    }

    outputChoice();

}

void toText::transChar(const int& num) //translates numbers into characters and adds them to text
{
    switch (num)
    {
        case 1:
            output.push_back('Z');

        break;
        case 2:
            output.push_back('J');

        break;
        case 3:
            output.push_back('V');

        break;
        case 4:
            output.push_back('P');

        break;
        case 5:
            output.push_back('C');

        break;
        case 6:
            output.push_back('Y');

        break;
        case 7:
            output.push_back('M');

        break;
        case 8:
            output.push_back('W');

        break;
        case 9:
            output.push_back('D');

        break;
        case 10:
            output.push_back('S');

        break;
        case 11:
            output.push_back('N');

        break;
        case 12:
            output.push_back('O');

        break;
        case 13:
            output.push_back('T');

        break;
        case 14:
            output.push_back('E');

        break;
        case 15:
            output.push_back('A');

        break;
        case 16:
            output.push_back('H');

        break;
        case 17:
            output.push_back('R');

        break;
        case 18:
            output.push_back('I');

        break;
        case 19:
            output.push_back('L');

        break;
        case 20:
            output.push_back('U');

          break;
        case 21:
            output.push_back('G');

        break;
        case 22:
            output.push_back('F');

        break;
        case 23:
            output.push_back('B');

        break;
        case 24:
            output.push_back('K');

        break;
        case 25:
            output.push_back('Q');

        break;
        case 26:
            output.push_back('X');

        break;
    }
}

void toText::defaultStaff() //Creates a user interface for entering data
{
cout << "  |)                                                                                   " << endl;
cout << "-----|----1----------------------------------------------------------------------------" << endl;
cout << "  /  |       2                                                                         " << endl;
cout << "-----|---------#3--4-------------------------------------------------------------------" << endl;
cout << " /|  |               #5  6                                                             " << endl;
cout << "-----|----------------------7----------------------------------------------------------" << endl;
cout << "/(|,\|                        #8  9                                                    " << endl;
cout << "-----|------------------------------#10--11--------------------------------------------" << endl;
cout << "\_|_/|                                    #12  13                                      " << endl;
cout << "-----|-------------------------------------------14------------------------------------" << endl;
cout << "  |                                                #15  16                             " << endl;
cout << "  |                                                      #17--18 - -  -  -  -  -  -  - " << endl;
cout << " ()                                                              19                    " << endl;
cout << "                                                                  #20-21 -  -  -  -  - " << endl;
cout << "                                                                        #22  23        " << endl;
cout << "                                                                              #24-25 - " << endl;
cout << "                                                                                     26" << endl;
}

void toText::outputChoice() //asks user how they want the output to be
{
  bool work = false;
    int choice;
    while (!work)
    {
        cout << "How do you want to Output? \nEnter 1 to print to document \nEnter 2 to print data to screen \n";
        cin >> choice;

        if (choice == 1 || choice == 2)
        {
            work = true;
        }
        if (!work)
        {
            cout << "Error reading input, try again" << endl;
        }
        cin.clear();
        cin.ignore();
    }

    if (choice == 1)
    {
        outputToFile();
    }

    if (choice == 2)
    {
        outputToScreen();
    }
}

void toText::outputToScreen()
{
    cout << endl;
    cout << "Message: " << output << endl;

}

void toText::outputToFile()
{
    ofstream Out;
    string fileName;
    cout << "Enter a name for output file: (music.txt)" << endl;
    getline(cin,fileName);

    string check;

    for (int i = (fileName.size() -4); i <= fileName.size(); i++) //checks if user added a .txt to the file name
    {
        check.push_back(fileName[i]);
    }

    if (check != ".txt") //adds .txt to end of fileName
    {
        fileName.push_back('.');
        fileName.push_back('t');
        fileName.push_back('x');
        fileName.push_back('t');
    }

    Out.open(fileName.data());
    Out << "Message: " << output << endl;

    Out.close();

    cout << "\n " << endl;
    cout << "Output success! File named \"" << fileName << "\"" <<endl;
    cout << "\n " << endl;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------

//To Music code


void toMusic::outputChoice() //asks user how they want the output to be
{
    bool work;
    int choice;
    while (!work)
    {
        cout << endl;
        cout << "How do you want to Output? \nEnter 1 to print to document \nEnter 2 to print data to screen \n";
        cin >> choice;

        if (choice == 1 || choice == 2)
        {
            work = true;
        }
        if (!work)
        {
            cout << endl;
            cout << "Error reading input, try again" << endl;
            cout << endl;
        }
        cin.clear();
        cin.ignore();
    }

    if (choice == 1)
    {
        outputToFile();
    }

    if (choice == 2)
    {
        outputToScreen();
    }

}

void toMusic::inputChoice() //fills vector with data from document or from user
{
    string text;
    int choice;
    bool work = false;
    while (!work)
    {
        cout << endl;
        cout << "How do you want to input? \nEnter 1 to read from document \nEnter 2 to enter data manually \n";
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

    if (choice == 1) //read from document
    {
        ifstream data;
        string fileName;
        cout << "Enter a file name: (text.txt)" << endl;

        getline(cin,fileName);

        string check;

        for (int i = (fileName.size() -4); i <= fileName.size(); i++) //checks if user added a .txt to the file name
        {
            check.push_back(fileName[i]);
        }

        if (check != ".txt") //adds .txt to end of fileName
        {
            fileName.push_back('.');
            fileName.push_back('t');
            fileName.push_back('x');
            fileName.push_back('t');
        }


        data.open(fileName.data());

        data >> text;
        music.push_back(text);
        while(!data.eof())
        {
        data >> text;
        music.push_back(text);
        }
        data.close();



        vectorToMusic();
    }

    if (choice == 2) //read from input
    {
        bool check = false;
        int amount = 0;

        while (check == false)
        {
            cout << "Enter text to be translated: (45 character max)" << endl;
            getline(cin,text);
            amount = text.size();

            for (int space = 0; space < text.size(); space++) //removes spaces from count, since they dont count towards total
            {
                if (text[space] == ' ')
                {
                    amount = amount-1;
                }
            }

            if (amount > 45) //makes sure that message is below 25 characters
            {
                cout << "Overflow! Max of 45 characters! (That was " << amount << " characters)" << endl;
            }
            else
            {
                check = true;
            }
        }
        treble(); //builds the treble clef art :D
        char letter;
        for (int i = 0; i< text.size() ; i++)
        {
            letter = text[i];
            letter = tolower(letter); //makes sure letter is in lowercase
            transTextToNums(letter);
        }
        outputChoice();
    }
}

void toMusic::transTextToNums(const char letter) //writes letter value to music
{
    if (letter != ' ')//makes sure there are no gaps
    {
        fillLine(); //fills vectors with default values
    }

  switch (letter)
    {
          break;
        case 'z':
            line6.pop_back(); //removes 3 characters
            line6.push_back("-O-"); //fills vector with intended characters

          break;
        case 'j':
            line7.pop_back(); //removes 3 characters
            line7.push_back(" O "); //fills vector with intended characters

          break;
        case 'v':
            line8.pop_back(); //removes 3 characters
            line8.push_back("#O-"); //fills vector with intended characters

          break;
        case 'p':
            line8.pop_back(); //removes 3 characters
            line8.push_back("-O-"); //fills vector with intended characters

          break;
        case 'c':
            line9.pop_back(); //removes 3 characters
            line9.push_back("#O "); //fills vector with intended characters

          break;
        case 'y':
            line9.pop_back(); //removes 3 characters
            line9.push_back(" O "); //fills vector with intended characters

          break;
        case 'm':
            line10.pop_back(); //removes 3 characters
            line10.push_back("-O-"); //fills vector with intended characters

          break;
        case 'w':
            line11.pop_back(); //removes 3 characters
            line11.push_back("#O "); //fills vector with intended characters

          break;
        case 'd':
            line11.pop_back(); //removes 3 characters
            line11.push_back(" O "); //fills vector with intended characters

          break;
        case 's':
            line12.pop_back(); //removes 3 characters
            line12.push_back("#O-"); //fills vector with intended characters

          break;
        case 'n':
            line12.pop_back(); //removes 3 characters
            line12.push_back("-O-"); //fills vector with intended characters

          break;
        case 'o':
            line13.pop_back(); //removes 3 characters
            line13.push_back("#O "); //fills vector with intended characters

          break;
        case 't':
            line13.pop_back(); //removes 3 characters
            line13.push_back(" O "); //fills vector with intended characters

          break;
        case 'e':
            line14.pop_back(); //removes 3 characters
            line14.push_back("-O-"); //fills vector with intended characters

          break;
        case 'a':
            line15.pop_back(); //removes 3 characters
            line15.push_back("#O "); //fills vector with intended characters

          break;
        case 'h':
            line15.pop_back(); //removes 3 characters
            line15.push_back(" O "); //fills vector with intended characters

          break;
        case 'r':
            line16.pop_back(); //removes 3 characters
            line16.push_back("#O-"); //fills vector with intended characters

          break;
        case 'i':
            line16.pop_back(); //removes 3 characters
            line16.push_back("-O-"); //fills vector with intended characters

          break;
        case 'l':
            line16.pop_back(); //removes 3 characters
            line16.push_back(" - "); //fills vector with intended characters
            line17.pop_back(); //removes 3 characters
            line17.push_back(" O "); //fills vector with intended characters

          break;
        case 'u':
            line16.pop_back(); //removes 3 characters
            line16.push_back(" - "); //fills vector with intended characters
            line18.pop_back(); //removes 3 characters
            line18.push_back("#O-"); //fills vector with intended characters

          break;
        case 'g':
            line16.pop_back(); //removes 3 characters
            line16.push_back(" - "); //fills vector with intended characters
            line18.pop_back(); //removes 3 characters
            line18.push_back("-O-"); //fills vector with intended characters

          break;
        case 'f':
            line16.pop_back(); //removes 3 characters
            line16.push_back(" - "); //fills vector with intended characters
            line18.pop_back(); //removes 3 characters
            line18.push_back(" - "); //fills vector with intended characters
            line19.pop_back(); //removes 3 characters
            line19.push_back("#O "); //fills vector with intended characters

          break;
        case 'b':
            line16.pop_back(); //removes 3 characters
            line16.push_back(" - "); //fills vector with intended characters
            line18.pop_back(); //removes 3 characters
            line18.push_back(" - "); //fills vector with intended characters
            line19.pop_back(); //removes 3 characters
            line19.push_back(" O "); //fills vector with intended characters

          break;
        case 'k':
            line16.pop_back(); //removes 3 characters
            line16.push_back(" - "); //fills vector with intended characters
            line18.pop_back(); //removes 3 characters
            line18.push_back(" - "); //fills vector with intended characters
            line20.pop_back(); //removes 3 characters
            line20.push_back("#O-"); //fills vector with intended characters

          break;
        case 'q':
            line16.pop_back(); //removes 3 characters
            line16.push_back(" - "); //fills vector with intended characters
            line18.pop_back(); //removes 3 characters
            line18.push_back(" - "); //fills vector with intended characters
            line20.pop_back(); //removes 3 characters
            line20.push_back("-O-"); //fills vector with intended characters

          break;
        case 'x':
           line16.pop_back(); //removes 3 characters
           line16.push_back(" - "); //fills vector with intended characters
           line18.pop_back(); //removes 3 characters
           line18.push_back(" - "); //fills vector with intended characters
           line20.pop_back(); //removes 3 characters
           line20.push_back(" - "); //fills vector with intended characters
           line21.pop_back(); //removes 3 characters
           line21.push_back(" O "); //fills vector with intended characters

          break;
        case ' ':
            line22.push_back("\t"); //adds a tab under the barline to inidicate there is a space
    }

}

void toMusic::fillLine() //fills vectors with default values
{
    line6.push_back("---");
    line7.push_back("   ");
    line8.push_back("---");
    line9.push_back("   ");
    line10.push_back("---");
    line11.push_back("   ");
    line12.push_back("---");
    line13.push_back("   ");
    line14.push_back("---");
    line15.push_back("   ");
    line16.push_back("   ");
    line17.push_back("   ");
    line18.push_back("   ");
    line19.push_back("   ");
    line20.push_back("   ");
    line21.push_back("   ");
    line22.push_back(" ");
}

void toMusic::vectorToMusic() //sorts vector into individual letters
{
    int max = music.size();
    string word;
    char letter;

    treble();

    for (int i = 0; i<max ; i++)
    {
        word = music[i];

        for (int j = 0; j< word.size() ; j++)
        {
            letter = word[j];
            letter = tolower(letter); //makes sure letter is in lowercase
            transTextToNums(letter);
        }
    }

    outputChoice();
}

void toMusic::outputToScreen() //outputs contents of vectors to the screen
{
    int size = line6.size();
    cout << "size: " << (size-1) << endl; //takes the treble ceft into account

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line6[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line7[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line8[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line9[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line10[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line11[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line12[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line13[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line14[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line15[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line16[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line17[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line18[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line19[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line20[i];
        }
        cout << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            cout << line21[i];
        }
        cout << endl;
}

void toMusic::outputToFile()  //outputs to file
{
    ofstream Out;
    string fileName;
    cout << "Enter a name for output file: (music.txt)" << endl;

    getline(cin,fileName);

    string check;

    for (int i = (fileName.size() -4); i <= fileName.size(); i++) //checks if user added a .txt to the file name
    {
        check.push_back(fileName[i]);
    }

    if (check != ".txt") //adds .txt to end of fileName
    {
        fileName.push_back('.');
        fileName.push_back('t');
        fileName.push_back('x');
        fileName.push_back('t');
    }


    Out.open(fileName.data());

    int size = line6.size();


        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line6[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line7[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line8[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line9[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line10[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line11[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line12[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line13[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line14[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line15[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line16[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line17[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line18[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line19[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line20[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line6.size() ; i++) //outputs line individually
        {
            Out << line21[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line22.size() ; i++) //outputs space individually
        {
            Out << line22[i];
        }

    Out.close();
    cout << endl;
    cout << "Output success! File named \"" << fileName << "\"" << endl;
    cout << endl;
}

void toMusic::treble() //Adds treble cleft to the music
{
    line6.push_back ("-----|");
    line7.push_back ("  /  |");
    line8.push_back ("-----|");
    line9.push_back (" /|  |");
    line10.push_back("-----|");
    line11.push_back("/\(|,\\|");
    line12.push_back("-----|");
    line13.push_back("\\_|_/|");
    line14.push_back("-----|");
    line15.push_back("  |   ");
    line16.push_back("  |   ");
    line17.push_back(" ()   ");
    line18.push_back("      ");
    line19.push_back("      ");
    line20.push_back("      ");
    line21.push_back("      ");
}


#endif
