#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool isPrime(long num)//4 returns false  positive for some reason
{
    //cout << "checking prime " << num << endl;

    long div = 2;

    while (div < (num/2))
    {
        if (!(num%div))
        {
            return false;
        }

        div++;
    }

    return true;
}



int main()
{
    long long sum = 5;//start with  2+3 because 4 breaks isPrime function for some reason
    for (int i = 5; i < 2000000; i++)
    {
        if (isPrime(i))
        {
            cout << "add " << i << endl;
            sum += i;
        }
        i++;//increase by 2 because even is not prime
    }


    cout << sum << endl;
    //142913828922 for 2 million

    return 0;
}
