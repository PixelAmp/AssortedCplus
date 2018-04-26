//Southern California Regional of the ACM International Collegiate Programming Contest
//Factorial Factors

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;
vector<bool> prime_list;

vector<bool> generate(int n){
	vector<bool> input(n+1, true);
	int sqrtN = (int)sqrt(n);
	for(int i = 2; i <= sqrtN; i++){
		if(!input[i])
			continue;
		for(int j = i * i; j <= n; j+=i)
			input[j] = false;
	}
	input[0] = false;
	input[1] = false;
	return input;
}

int factors(int OGNUM)//this function gets passed a number and returns the number of factors that is has
{
  int div = 2; //number being used to divide
  int count = 0;//count how many factors have been found

  if (prime_list[OGNUM])//returns 1 if the number is prime
      return 1;

  while (!(prime_list[OGNUM]) && div <= (OGNUM+1)) //while the passed number is divisible by the factor keep doing it
    {
      while(!(OGNUM%div))//current number is divisible by the count
        {
            OGNUM = (OGNUM/div); //if the numebr is divisible, divide it and replace it with the result
            count++;
        }
      div++;//increments the factor test number
    }

  if ((div = OGNUM) && (div != 1))//adds the final factor so long as it's not a one
      count++;

  return count;
}

int tori(int NUM)
{
  int count = 0;
  int fac = 2;
  bool load = false;

  while(fac <= NUM) //counts all the way up to the number
    {
      count += factors(fac); //passes current position to the function to find out haw many factors that number has
      fac++;//increment number as the loop resets
    }

  return count; //returns result
}

void readDoc()
{
  ofstream out;
  int hold = 0; //holds read number
  int result; //this is only here so that I can output to scree and file at the same time


  out.open("output.txt");

  while (cin >> hold)
    {
      result = tori(hold); //if we just need one at a time, dlete the other and replace the "result" variable with the tori command
      cout << hold << "\t\t" << result << endl;
      out << result << endl;
    }


  out.close();
}


int main()
{
  prime_list = generate(2000000);
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




