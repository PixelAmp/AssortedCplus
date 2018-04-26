//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

//I know this code is really gross but it works, so I hope I don't have to use it again written (1/5/16)
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}


int main()
{
    //cout << 999 * 999 << endl; = 998001
    string pal = "hello";

    int num = 0;
    bool tag = false;
    int i = 999;
    int k = 999;
    //for(int i = 999; i > 100;i--)
    while(!tag && i >800)
    {
        k = 999;
        //for (int k = 999; k > 100; i--)
        while (!tag && k >800)
        {
            //cout << i << " " << k << endl;
            num = i*k;
            pal = convertInt(num);
            if (pal[0] == pal[pal.size()-1])
            {
                //cout << "one " << num << endl;
                if (pal[1] == pal[pal.size()-2])
                {
                    //cout << "two " << num << endl;
                    if (pal[2] == pal[pal.size()-3])
                    {
                        cout << i << " " << k << endl;
                        cout << "three " << num << endl;
                        tag = true;
                    }
                }
            }
            k--;
        }
        i--;
    }

    cout << "done" << endl; //580058 // 906609
}
