//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?
#include <iostream>
using namespace std;


bool isPrime(unsigned long long num)
{
    cout << "checking prime" << endl;

    unsigned long long div = 2;

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
    long long primes;
    bool found = false;
    int div=2;
    int num;
                                //13195;//
    unsigned long long bigNum = 600851475143; //

    cout << bigNum << endl;

    unsigned long long n = (bigNum/2);

    while (!found)
    {
        if ((bigNum%div) == 0)
        {
            num = bigNum/div;
            found = isPrime(num);
        }
        div++;
    }
    cout << "done " << endl;

    cout << "Biggest prime factor is " << num << endl; //6857
}


