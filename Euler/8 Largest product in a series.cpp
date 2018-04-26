#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//MAKE A CASE FOR IF THE NUMBER IS ZERO!!!!!!!!!!!!!!!!!!!!!!!
//IT WILL BREAK THE FORMULA


void read(int data[])
{
    ifstream text;
    char hold;
    text.open("8 data.txt");
    int i =0;

   // cout << "read" << endl;

    while (text >> hold)
    {
        data[i] = (hold-48); //fills array with integers from list
        i++;
    }
    //cout <<"read in " << i << endl;

    text.close();
}


int product(int const data[])
{
    //cout << data.size() << endl;
    //cout << data << endl;
    int count = 13;
    __int64 mainp = 1;
    __int64 testp = 1;
    int size = 13;

    for (int i = 0; i < size; i++)
    {
        mainp *= data[i];
        //cout << data[i] << endl;
    }
     cout << mainp << endl;
     testp = mainp;

    while(count < (1000-size))
    {
        testp = 1;

        while (data[count] == 0)
        {
            count++;//= size; //skips 13 because 0 breaks formula

            //cout << "zero" << endl;
  //          cout << "count is now " << count << endl;
//            cout << "starting with " << data[count] << endl;

        }

        for (int i = count; i < (count+size); i++)
        {
            testp *= data[i];
        }
        //cout << "new product " << testp << endl;
/*
        testp /= data[count - 13];
        testp *= data[count];
*/
        if (testp > mainp)
        {
            mainp = testp;
            cout << "bigger number" << endl;
        }

        count++;
        //cout << count << endl;
        //cout << mainp << endl;
    }


    cout << "answer is " << mainp << endl;
}


int main()
{
    int data[1000];

    read(data);
    product(data);

}
