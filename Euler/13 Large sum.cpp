#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

string NumBlock[100]; //entire number is held as a string
string TotSum="";

void StringRead() //reads in data and puts numbers into an array
{
    ifstream text;
    text.open("13 data.txt");
    string num;
    int i=0;
    while (i<100)
        {
        	text >> num;
            NumBlock[i] = num;
            i++;
        }
}


void RecAdd(int carry)
{
    cout << carry << endl;
    if (NumBlock[0].size() == 0)
    {
        ((TotSum[TotSum.size() -1] - 48) + carry)
        cout << "Done!" << endl;
        return;
    }

	//cout << NumBlock[0] << endl;
    string last= "";

    for (int i =0; i<100;i++) //adds numbers by the column
    {
        carry += (NumBlock[i][NumBlock[i].size()-1] - 48);
        NumBlock[i].pop_back();
    }



    TotSum += (carry%10) + 48;
    RecAdd(carry/10);
}

int main()
{
    StringRead();
    RecAdd(0);

    cout << TotSum << endl;
    reverse(TotSum.begin(), TotSum.end());
    cout << TotSum << endl;

    for (int i = 0; i < 10 ; i++)
    {
        cout << TotSum[i];
    }
    cout << endl;

    return 0;
}
