//Southern California Regional of the ACM International Collegiate Programming Contest
//Factorial Factors

#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int num)//checks if the number is prime
{
    if(!(num%2))//if number is even
    {
        return false;
    }

    if (num == 4) //4 returns false  positive for some reason
    {
        return false;
    }

    int div = 2;

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

int factors(int OGNUM)//this function gets passed a number and returns the number of factors that is has
{
  int div = 2; //number being used to divide
  int count = 0;//count how many factors have been found

  if (isPrime(OGNUM))//returns 1 if the number is prime
  {
      return 1;
  }

  while (!(isPrime(OGNUM)) && div <= (OGNUM+1)) //while the passed number is divisible by the factor keep doing it
    {
        while(OGNUM%div == 0)
        {
            //cout << "Factor " << div << endl;
            OGNUM = (OGNUM/div);
            count++;
        }
        div++;//increments the factor test number
    }

    if ((div = OGNUM) && (div != 1))//adds the final factor so long as it's not a one
    {
        //cout << "factor " << div << endl;
        count++;
    }

    //cout << "Number of factors is " << count << endl;
    return count;
}

int tori(int NUM)
{
    int count = 0;
    int fac = 2;
    bool progress = false;

    while(fac <= NUM) //counts all the way up to the number
    {

        if((fac%100000) == 0)//progress bar when the number is REALLY big
        {
            //cout << fac << " ";
            cout << "working... " ;
            progress = true;
        }



        count += factors(fac); //passes current position to the function to find out haw many factors that number has
        fac++;//increment number as the loop resets
    }

    if (progress)
        cout << endl; //this is to make the output prettier

    //cout << "Maximum number of factors is " << count;
    return count; //returns result
}

void readDoc()
{
    ifstream data;
    ofstream out;
    string fileName;//user inputed file name
    int hold = 0; //holds read number
    int result; //this is only here so that I can output to scree and file at the same time

    ifstream text;
    text.open("input.txt");
    out.open("output.txt");



    cout << "Input\t\tOutput" <<endl; //formating for output
    out << "Input\t\tOutput" <<endl;
    while (text >> hold)
        {
            result = tori(hold); //if we just need one at a time, dlete the other and replace the "result" variable with the tori command
            cout << hold << "\t\t" << result << endl;
            out << hold << "\t\t" << result << endl;
        }


    data.close();
    out.close();
}


int main()
{
    readDoc();
}

/*
Sample Input    Sample Output
2               1
1000000         3626619
1996            5957
5               5
8               11
123456          426566
*/




