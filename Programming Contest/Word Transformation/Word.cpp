#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string Dict[200]; //global dictionary
vector<string> trans; //holds the words that are going to be transformed from. evens are start, odds are end
int count = 0; //count for how many words are in the dictionary

void readDoc() //this will get replaced with just a cin in the main to get all the data, but I don't feel like typing in the dictionary every time
{
    ifstream data;
    string hold; //holds read number
    bool dictionary = true; //true while still entering in dictionary. turns false when taking in words that will be compared

    ifstream text;
    text.open("input.txt");

    while (text >> hold) //reads in all the data
        {
            if (hold == "*")
            {
                dictionary = false;
            }

            if (dictionary)
            {
                Dict[count] = hold; //puts the word into the dictionary
                count++; //increments count so that the next word gets put in front of this word
            }

            else
            {
                if (hold != "*")
                    trans.push_back(hold);
            }

        }

    data.close();
}

bool convert(int spot, string conv, string ending) //recursive function that looks for the next letter in the transformation
{
    for (int sizeofdict = 0; sizeofdict < count; sizeofdict++) //goes through the entire dictionary
    {
        conv.substr(spot,conv.length()); //gets the rest of the string past the spot


    }

}

int transform()
{
    string starting = trans[0]; //staring word
    string ending = trans[1]; //what the word should transform into
    string conversion = starting; //holds the word that is being transformed
    int letter = 0;// keeps track of the letter I'm looking at

    //for (int sizeofword = 0; sizeofword < starting.size(); sizeofword++)

    convert(0, conversion, ending);




}




int main()
{
    string input;

    readDoc();

    string conv = trans[1];
    cout << conv << endl;
    cout << conv.substr(1,conv.length()) << endl;
    /*
    for (int i = 0; i < trans.size(); i+=2)
    {
        cout << trans[i] <<  " to " << trans[i+1] << endl;
    }

    for (int i = 0; i < count; i++)
    {
        cout << Dict[i] << endl;
    }

    transform();
*/
    return 0;
}
