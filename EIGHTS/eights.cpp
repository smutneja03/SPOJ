
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

		lld index;
		cin >> index;
		lld solution = 192 + 250*(index-1);
		cout << solution << endl;

		test_cases--;
	}

	return 0;
}