
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

	lld first, second, third;
	cin >> first >> second >> third;

	while(first!=0 || second!=0 || third!=0){
		//even if one id non zero go in the while loop
		if( (second-first) == (third-second) ){

			//the given series is an AP
			lld diff = second-first;
			lld term = third + diff;
			cout << "AP " << term << endl;

		}

		else{
			//if the sequence is not AP then its GP
			lld r = second/first;
			lld term = third * r;
			cout << "GP " << term << endl;
		}

		cin >> first >> second >> third;

	}
	return 0;
}