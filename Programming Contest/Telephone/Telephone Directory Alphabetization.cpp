#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;


vector<string> address;
string Directory [1000][3];

void sort(string text)
{
    //cout << text[7] << endl;

    for (int i = 7; i < text.size(); i++)
    {
        cout << text[i] << endl;
        if (isalnum(text[i]))
        {
            cout << "number or digit" << endl;
        }

        else
        {
            cout << "not a letter or digit" << endl;
        }



    }


}

string translate(string text)
{




}


void readDoc()
{
    ifstream data;
    string fileName;//user inputed file name
    int count = 1; //starting at 1 for simplicity
    string text;//hold the data read from the file

    data.open("input.txt");

    getline(data, text);//gets the whole line in the document and makes it a string

    //sort(text); //even though it is the first one, it still needs to be decoded so it can be sorted later

    address.push_back(text);//puts the first data member in the vector


    while(!data.eof()) //reads entire document
        {
            getline(data, text);//gets the whole line in the document and makes it a string

            //sort(text);//sends obtained text to the sorting function

            address.push_back(text);//pushes text to the back of the vector
        }

    data.close();

}


int main()
{
    readDoc();

    for (int i = 0; i < address.size(); i++)
    {
        cout << address[i] << endl;
    }

    return 0;
}







