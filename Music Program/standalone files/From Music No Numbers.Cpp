#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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

toText::toText() //sets global variables
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
    //char music[21][75]; //22 down, 75 across
    ifstream data;
    string fileName;
    int count=0;
    char text;
    int down = 0;
    int across = 0; //sets across to zero

    cout << "Enter a file name: (text.txt)" << endl;
    cin >> fileName;

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
    cout << length << endl;
    cout << "Message: " << output << endl;
}

void toText::outputToFile()
{
    ofstream Out;
    string fileName;
    cout << "Enter a name for output file: (music.txt)" << endl;
    cin >> fileName;
    Out.open(fileName.data());

    Out << "Message: " << output << endl;

    Out.close();
    cout << "Output success! File named " << fileName << endl;
}

int main()
{
    toText text;
    text.inputChoice();

    return 0;
}

