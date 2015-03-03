

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>

typedef long long int lld;

using namespace std;

int main(){

	lld test_cases;
	cin >> test_cases;
	//numbered by divisors means multiples of divisors
	//the player that moves first will always win, as he will pick 1
	//and all its multiple that is all will be removed
	while(test_cases){

		lld number, player;
		cin >> number >> player;

		if(player==0){
			cout << "Airborne wins." << endl;
		}
		else{
			cout << "Pagfloyd wins." << endl;
		}

		test_cases--;
	}
	
	return 0;
}