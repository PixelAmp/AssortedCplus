#include <iostream>
using namespace std;

bool isPrime(int num)//checks if the number is prime
{
    if (num == 2)
    {
        return true;
    }

    if(!(num%2))//if number is even
    {
        return false;
    }

    int div = 3;

    while (div < (num/2)) //while the count is less than half of passed number
    {
        if (!(num%div)) //as soon as a factor is found, return false
        {
            return false;
        }

        div+=2; //adds by 2 because even numbers aren't prime
    }

    return true; //if no factor is found
}


int main()
{
    int hold;
    int dig = 0;
    bool prime; //flags for if the digits are prime
    int sum = 2;//starts at 2 because 2 is the only even prime

    for (int i = 3; i < 1000000; i+=2)
    {
        if (i%100001 == 0)
        {
            cout << "loading... " << endl;
        }
        hold = i;
        if (isPrime(i))
        {
            prime = false;
            //cout << i << " is prime" << endl;
            while (hold > 0) //goes through all the digits in the number
            {
                dig = hold%10; //gets the digit on the end
                //cout << "digit" << dig << endl;
                if (isPrime(dig)) //if the digit is prime
                {
                    prime = true;
                }
                else
                {
                    prime = false;
                    break;
                }

                hold = (hold/10);//next digit
            }

            if (prime)
            {
                sum += i;
                //cout << i << " is completely prime" << endl;
            }
        }
    }


    cout << "sum " << sum << endl;

}
