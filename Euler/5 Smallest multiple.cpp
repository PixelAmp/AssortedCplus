/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include<iostream>

using namespace std;

bool loop(int num)
{
    if (!(num%10000))
        {
            cout << num << endl;
        }

    for (int i = 2; i <= 10 ; i++)
    {

        if (num == 240123904)
        {
            cout << "MAX REACHED" << num << endl;
            return true;
        }

        if (num%i != 0)
        {
            return false;
        }

    }
cout << num << endl;
    return true;
}


int main()
{
    bool found = false;
    int num = 100;

    while(found == false)
    {
        found = loop(num);
        num += 2; //keep it even
    }


    cout << "found! " <<num << endl;
}
//max is 240123904 20!
//       232792562
//232792560 because an extra 2 is added!


