/*
Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
where each “_” is a single digit.
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

long long ConSqu = 0;


int main()
{
    for (int i = 10; i < 250 ; i++)
    {

        cout << i << " " << pow(i,2) << endl;
    }


}

