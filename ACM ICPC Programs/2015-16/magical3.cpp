#include <iostream>

using namespace std;


int main()
{
    int user , result, test;


    while (user != 0)
    {
    user = result = 0;
    cout << "Enter input, and I shall return the magic number" << endl;
    cout << "Enter \" 0 \" when done" << endl;

    cin >> user;


    if (user == 0)
    {
        //this should exit the while loop
    }

    //special case for numbers that dont have a base
    else if ((user <= 2) || (user == 4) || (user == 5) || (user == 6))
    {
        cout << "No such base" << endl;
    }

    //starts on 4 because that is the smallest possible base


    else
    {
        test = 1;
        while ((user%test) != 3)
        {
            test++;
        }

        cout << "base is " << test << endl;
    }
    }



    cout << "Thanks!" << endl;
    cout <<"This was problem 1 off the 2015/2016 SOUTHERN CALIFORNIA REGIONAL ACM INTERNATIONAL COLLEGIATE PROGRAMMING CONTEST" << endl;

}
