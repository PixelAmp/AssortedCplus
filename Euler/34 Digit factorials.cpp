/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/
#include <iostream>
using namespace std;

int main()
{
    int hold;
    int dig = 0;
    int fac = 1;
    int sum;

    for (int i = 1; i <= 1000000; i++)
    {
        sum = 0; //resets the sum
        hold = i;//holds the current position

        while (hold > 0) //goes through all the digits in the number
        {
            fac = 1;
            dig = hold%10; //gets the digit on the end;
            //cout << "digit " << dig;
            for(int i = 1; i <= dig; i++)
            {
                fac *= i;
            }
            //cout << " factorial " << fac << endl;

            sum += fac;
            hold = (hold/10);//next digit
        }

        //cout << "number " << i << " Factorial sum " << sum << endl;

        //cout << endl;

        if (fac == i)
            cout << "match " << i << endl;

        //cout << i << endl;
    }



    return 0;
}
