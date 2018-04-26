#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class toMusic
{
protected:
    /*
    vector<string> line1; //01
    vector<string> line2; //23
    vector<string> line3; //4
    vector<string> line4; //56
    vector<string> line5; //78
    */
    vector<string> line6; //9Z
    vector<string> line7; //J
    vector<string> line8; //VP
    vector<string> line9; //CY
    vector<string> line10; //M
    vector<string> line11; //WD
    vector<string> line12; //SN
    vector<string> line13; //OT
    vector<string> line14; //E
    vector<string> line15; //AH
    vector<string> line16; //RI
    vector<string> line17; //L
    vector<string> line18; //UG
    vector<string> line19; //FB
    vector<string> line20; //KQ
    vector<string> line21; //X
    vector<string> line22; //Spaces & Tabs

    vector<string> music; //place holder

public:
    void vectorToMusic(); //sorts vector into individual letters
    void transTextToNums(const char); //writes letter value to music
    void inputChoice(); //fills vector with data from document or from user
    void outputToScreen(); //outputs to screen
    void outputToFile(); //outputs to file
    void outputChoice(); //asks user how they want the output to be
    void fillLine(); //fills vectors with default values
    void treble(); //Adds treble cleft to the music
};

void toMusic::outputChoice() //asks user how they want the output to be
{
    bool work;
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

void toMusic::inputChoice() //fills vector with data from document or from user
{
    string text;
    int choice;
    bool work = false;
    while (!work)
    {
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
        cin >> fileName;
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
        /*
        case '0':
            line1.pop_back(); //removes 3 characters
            line1.push_back("#O "); //fills vector with intended characters
            line2.pop_back(); //removes 3 characters
            line2.push_back(" - ");//adds the little line thingy
            line4.pop_back(); //removes 3 characters
            line4.push_back(" - ");//adds the little line thingy


          break;
        case '9':
            line1.pop_back(); //removes 3 characters
            line1.push_back(" O "); //fills vector with intended characters
            line2.pop_back(); //removes 3 characters
            line2.push_back(" - ");//adds the little line thingy
            line4.pop_back(); //removes 3 characters
            line4.push_back(" - ");//adds the little line thingy

          break;
        case '8':
            line2.pop_back(); //removes 3 characters
            line2.push_back("#O-"); //fills vector with intended characters
            line4.pop_back(); //removes 3 characters
            line4.push_back(" - ");//adds the little line thingy

          break;
        case '7':
            line2.pop_back(); //removes 3 characters
            line2.push_back("-O-"); //fills vector with intended characters
            line4.pop_back(); //removes 3 characters
            line4.push_back(" - ");//adds the little line thingy

          break;
        case '6':
            line3.pop_back(); //removes 3 characters
            line3.push_back(" O "); //fills vector with intended characters
            line4.pop_back(); //removes 3 characters
            line4.push_back(" - ");//adds the little line thingy

          break;
        case '5':
            line4.pop_back(); //removes 3 characters
            line4.push_back("#O-"); //fills vector with intended characters

          break;
        case '4':
            line4.pop_back(); //removes 3 characters
            line4.push_back("-O-"); //fills vector with intended characters

          break;
        case '3':
            line5.pop_back(); //removes 3 characters
            line5.push_back("#O "); //fills vector with intended characters

          break;
        case '2':
            line5.pop_back(); //removes 3 characters
            line5.push_back(" O "); //fills vector with intended characters

          break;
        case '1':
            line6.pop_back(); //removes 3 characters
            line6.push_back("#O-"); //fills vector with intended characters
*/
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
    /*
    line1.push_back("   ");
    line2.push_back("   ");
    line3.push_back("   ");
    line4.push_back("   ");
    line5.push_back("   ");
    */

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
        /*
        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            cout << line1[i];
        }
        cout << endl;

        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            cout << line2[i];
        }
        cout << endl;

        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            cout << line3[i];
        }
        cout << endl;

        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            cout << line4[i];
        }
        cout << endl;

        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            cout << line5[i];
        }
        cout << endl;
*/
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
    cin >> fileName;
    Out.open(fileName.data());

    int size = line6.size();
    //cout << "size: " << size << endl;
    /*
        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            Out << line1[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            Out << line2[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            Out << line3[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            Out << line4[i];
        }
        Out << "|" << endl;

        for(int i = 0; i < line1.size() ; i++) //outputs line individually
        {
            Out << line5[i];
        }
        Out << "|" << endl;
*/
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
        //Out << endl;

    Out.close();
    cout << "Output success! File named " << fileName << endl;
}

void toMusic::treble() //Adds treble cleft to the music
{
    /*
    line1.push_back ("         ");
    line2.push_back ("         ");
    line3.push_back ("         ");
    line4.push_back ("         ");
    line5.push_back ("  |)     ");
    */
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

int main()
{
    toMusic music;
    music.inputChoice();
}

