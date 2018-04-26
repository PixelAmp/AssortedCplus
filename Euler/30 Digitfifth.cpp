#include <iostream>
#include <math.h>
using namespace std;


int main()
{
  //cout << pow(3,2) << endl;
  int first, second, third, fourth, fifth, sixth;
  int hold;
  int sum = 0;
  for (int i = 2; i <= 999999; i++)
    {
      hold = i;
      
      first = pow(double(hold%10),5);
      //cout << first << endl;
      
      hold = (hold/10);//next digit
      second = pow(double(hold%10),5);
      // cout << second << endl;
      
      hold = (hold/10);
      third = pow(double(hold%10),5);
      //cout << third << endl;
      
      hold = (hold/10);
      fourth = pow(double(hold%10),5);
      //cout << fourth << endl;

      hold = (hold/10);
      fifth = pow(double(hold%10),5);
      //cout << fifth << endl;

      hold = (hold/10);
      sixth = pow(double(hold%10),5);
      //cout << sixth << endl;


      if(i == (first + second + third + fourth+ fifth+sixth))
	{
	  cout << "Match " << i << endl;
	  sum += i;
	}
      

      //cout << endl;
    }
  

  cout << "sum " << sum << endl;
  return 0;
  
  
}
