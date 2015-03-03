
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

typedef long long int lld;
using namespace std;

int main(){

	lld test_cases;
	cin >> test_cases;

	while(test_cases){

		lld height;
		cin >> height;
		lld balls = (height)*(height+1)/2;
		//min number of ballls required to invert a triangle is equal to 
		//balls/3
		lld solution = balls/3;

		cout << solution << endl;


		test_cases--;
	}

	return 0;
}