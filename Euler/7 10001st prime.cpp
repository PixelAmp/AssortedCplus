//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//What is the 10 001st prime number?

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num)
{
    int div = (num/2);

    while (div > 1)
    {
        if (!(num%div))
        {
            return false;
        }
        div--;
    }

    return true;
}



int main()
{
    int count =1;
    int num = 1;
    int max = 10001;

    while (count <= max)
    {
        num++;
        if (isPrime(num))
        {
            //cout << num << endl;
            count++;
        }
    }

    cout << "prime #" << max << ": " << num << endl;
    //104743
}
