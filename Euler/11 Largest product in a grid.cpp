#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void read(int data[][])
{
    ifstream text;
    char hold;
    text.open("11 data.txt");
    int i =0;

   // cout << "read" << endl;

    while (text >> hold)
    {
        for (int x = 0; x < 20; i++)
        {
            for (int y = 0; y < 20 ; y++)
            {
                data[x][y] = (hold-48); //fills array with integers from list
                i++;
            }
        }
    }
    //cout <<"read in " << i << endl;

    text.close();
}


int main()
{
int data[20][20];

    read(data);

    product(data);


    return 0;
}
