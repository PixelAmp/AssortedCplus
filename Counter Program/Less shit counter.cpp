#include <iostream>
#include <fstream>

using namespace std;

class counter
{
public:
    void read();
private:
    int leCnt[128] = {0}; //covers regular ascii characters
    int count = 0;
    //void input();
    void output();
};

void counter::read()
{
    char text;
    ifstream input;

    input.open("GoT.txt");

    input >> text;
    count++;
    while(!input.eof())
    {
      input >> text;
      leCnt[int(tolower(text))]++;
      count++;
    }
    input.close();
    output();
}

void counter::output()
{
    cout << count << " characters processed" << endl;
    for (int i = 0; i < 128; i++)
    {
        if (leCnt[i] != 0)
        {
            cout << char(i) << "\t" << leCnt[i] << endl;
        }
    }
}


int main()
{
    counter thing;
    thing.read();
    return 0;
}
