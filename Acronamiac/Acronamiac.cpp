#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class Acro
{
private:
    int playerNum; //amount of players
    int acroNum; //acronym size
    vector<string> answers; //holds user responses
    //using vector so that I can dynamically add and remove without worrying about size

    char charGen(); //uses Rand to return a letter

    bool winState();

public:
    Acro();
    string acronym;
    void input(); //user input
    void getAcro(); //creates acronym
    void game();
    void results();
};

Acro::Acro() //constructor
{
    playerNum = acroNum = 0; //acronym size
    answers.clear();
    acronym= "";
}

void Acro::input() //user input area
{
    bool work = false;

    cout << "Welcome to Acronamiac!" << endl;
    cout << "The rules are simple, make the most creative name " << endl;
    cout << "out of the given acronym to win! " << endl;

    while (!work)
    {
    cout << "\nEnter amount of players: (Up to 6 players)" << endl;
    cin >> playerNum;

    if (playerNum > 1 && playerNum < 7) //Check for player size
        {
            work = true;
        }

    else
        {
            cout << "Error with input! 2 player minimum, Up to 6 players" << endl;
        }
    cin.clear();
    cin.ignore();
    }
    work = false; //resets flag

    while (!work)
    {
    cout << "\nEnter size of acronym: (Up to 6 letters, recommend 3 letters)" << endl;
    cin >> acroNum;

    if (acroNum > 1 && acroNum < 7) //Check for player size
        {
            work = true;
        }

    else
        {
            cout << "Error with input! 2 letter minimum, Up to 6 letters" << endl;
        }
    cin.clear();
    cin.ignore();
    }
}


void Acro::getAcro() //crates acronym
{
    int x;
    char y;
    //v2 = rand() % 26 + 1;

    char letter;
    for (int i = 0; i < acroNum ; i++)
    {
        x = rand() % 26 + 65; //gets a random number
        y = x;
        acronym.push_back(y); //letter);
    }
}

void Acro::game() //actual game
{
    bool work = false;
    string user;
    cout << "Lets Play!\n" << endl;
    for (int i = 1; i <= playerNum; i++)
    {
        cout << "The acronym is " << acronym << endl;
        cout << "Player " << i << "!" << endl;
        cout << "Press enter to move on to the next letter" << endl;

        for (int j = 0; j< acroNum ; j++)
        {
            work = false;
            while (!work)
            cout << acronym[j] << ": ";
            getline(cin,user);


            //goes through input to make sure that they input one letter at a time by checking if there were spaces in input
            for (int k=0 ; k< user.size(); k++)
            {
                if (user[k] = ' ')
                {
                    cout << "Enter one word at a time please!" << endl;
                    work = false;
                }
                else
                {
                    work = true;
                }
            }

            cin.clear();
            cin.ignore();
        }
    }

}

void Acro::results()
{
    int spot = 0;
    for (int i = 1; i <= playerNum; i++)
    {
        cout << "Player " << i << "'s acronym: " << endl;

        for (int j = 0; j<3 ; j++) //outputs the players acronym
            {
                cout << answers[0] << " " ;
                answers.pop_back(); //removes the first word
            }
            cout << endl;
    }
}

int main()
{
    bool again = true;
    Acro chris;

    while (again)
    {
    chris.input();
    chris.getAcro();
    chris.game();
    chris.results();
    again = false;
    }
    return 0;
}
