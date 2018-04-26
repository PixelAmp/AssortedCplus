//Southern California Regional of the ACM International Collegiate Programming Contest
//Factorial Factors
#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> generate(int n) //fills the prime_list vector with primes up to the passed number
{
	std::vector<bool> input(n+1, true); //makes them all true by default?
	int sqrtN = (int)sqrt(n); //gets the square root of the max number
	for(int i = 2; i <= sqrtN; i++){
		if(!input[i]) continue;
		for(int j = i * i; j <= n; j+=i)
			input[j] = false;
        }
	return input; //returns completed vector
}

std::vector<bool> prime_list = generate(1000000); //this is where the generate function is called


int factorial(int n){
	int p = 2; //count
	int r = 0; //resulting sum
	while(p <= n){
		int max_i = round(log(n) / log(p));
		for(int i = 1; i <  max_i + 1; i++)
			r += n / pow(p, i);
		do{p++;} while(!prime_list[p]);
	}
	return r;
}

int main(){
  	int hold;
  	while(std::cin >> hold) //reads in all available data
     		std::cout << factorial(hold) << std::endl; //sends it to the factorial function
  	return 0;
}
