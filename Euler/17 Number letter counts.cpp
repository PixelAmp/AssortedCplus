#include <iostream>
using namespace std;


//three hundred and forty-two

int lcount(int num)
{
    cout << num << " ";
    int extraD = 0; //holds the front digit

    if (num <= 19) // catches 0-19
    {
        switch (num)
        {
            case 0 : cout << " YOU SHOULD'T SEE ME "; return 4; //zero
            case 1 : return 3; //one
            case 2 : return 3; //two
            case 3 : return 5; //three
            case 4 : return 4; //four
            case 5 : return 4; //five
            case 6 : return 3; //six
            case 7 : return 5; //seven
            case 8 : return 5; //eight
            case 9 : return 4; //nine
            case 10 : return 3; //ten
            case 11 : return 6; //eleven
            case 12 : return 6; //twelve
            case 13 : return 8; //thirteen
            case 14 : return 8; //fourteen
            case 15 : return 7; //fifteen
            case 16 : return 7; //sixteen
            case 17 : return 9; //seventeen
            case 18 : return 8; //eighteen <-- this caused me at least two gray hairs
            case 19 : return 8; //nineteen
        }
    }


    else if (num < 100) //catches 20-99
    {
        extraD = num / 10;

        if (extraD == 2)
        {
            if (num == 20) {return 6;}//no suffix

            return (lcount(num % 10) + 6);//twenty
        }

        else if (extraD == 3)
        {
            if (num == 30) {return 6;}//no suffix

            return (lcount(num % 10) + 6);//thirty
        }

        else if (extraD == 4)
        {
            if (num == 40) {return 5;}//no suffix

            return (lcount(num % 10) + 5);//forty
        }

        else if (extraD == 5)
        {
            if (num == 50) {return 5;}//no suffix

            return (lcount(num % 10) + 5);//fifty
        }

        else if (extraD == 8)
        {
            if (num % 10 == 0)//suffix is 0
            {
                return (lcount(num / 10) + 1); //eighty
            }

            return ((lcount(num / 10) + 1) + lcount(num % 10)); // -ly + suffix
        }

        else
        {
            if (num % 10 == 0)//suffix is 0 i.e. 60
            {
                return (lcount(num / 10) + 2);
            }

            return ((lcount(num / 10) + 2) + lcount(num % 10)); // -ly + suffix
        }
    }

    else if (num <= 999)
    {
        if ((num % 100) == 0) //no suffix i.e. 200
        {
            return (lcount(num / 100) + 7); //prefix + "hundred"
        }

        else
        {
           return (lcount(num / 100) + 7 + 3 + lcount(num % 100)); //prefix + "hundred and" ++ suffix
        }
    }


    else //1000
    {
        return 11;//one thousand
    }



}






int main()
{
    int sum = 0;
    int num = 0;

    for (int i = 1; i <= 1000; i++)
    {
        sum += num = lcount(i);
        cout << endl;
        cout << i << " " << num << endl;
        cout << endl;
    }

    cout << "Sum of all the letter is " << sum << endl;

    return 0;
}
