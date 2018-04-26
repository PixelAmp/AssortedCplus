//If we list all the natural numbers below 10 that are multiples of 3 *or* 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.
#include <iostream>

using namespace std;
//1 2  3  4  5  6  7  8  9  10
//3 6  9  12 15 18 21 24 27 30
//5 10 15 20 25 30

int main()
{
    int sum = 0;
    //int sum = 0;
    int max = 1000;
    int count = 1;

    int mul3 = 0;
    int mul5 = 0;

    while (mul3 < (max-3))
    {
        sum += mul3 = (3 * count);
        cout << mul3 << " ";

        mul5 = mul3 +(count*2);
        if (mul5 < max && (count%3))
        {
            sum += mul5;
            cout << mul5;
        }


        cout << endl;
        count++;
    }


    cout << "\n" << sum;
    233168
    /*

    cout << "Three" << endl; //less than1000 is 166833
    for (int i = 3; i < max; i+=3)
    {
       // cout << i << endl;
        if(i%5)
       {
           sum += i;
       }
    }

    cout << "Sum of 3: " << sum << endl;

    cout << "Five" << endl; //1000 is 99500
    for (int i = 5; i < max; i+=5)
    {
       // cout << i << endl;
       if(i%3)
       {
           sum5 += i;
       }
    }
    //I got 266333 total, but apparently that is wrong
    //I saw it was 3 OR 5, so I adjusted accordingly and got 200003

    cout << "sum of 5: " << sum5 << endl;
    */

   // cout <<"Sum total:" << sum3+sum5 << endl;



}
