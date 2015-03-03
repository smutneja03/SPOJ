
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <unistd.h>
#include <cmath>

typedef long long int lld;

using namespace std;

int main(){

	lld test_cases;
	cin >> test_cases;

	while(test_cases){

		//on analysis answer is n/2 if n is even else (n+1)/2
		lld number, solution;
		cin >> number;
		if(number%2==0){
			//even number
			solution = number/2;
		}
		else{
			solution = (number+1)/2;
		}
		cout << solution << endl;
		test_cases--;
	}

	return 0;
}