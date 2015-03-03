
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

	lld number, i, solution = 0;
	cin >> number;
	
	lld range = sqrt(number);
	
	for(i=1;i<=range;i++){
		solution += number/i -i + 1;
	}

	cout << solution << endl;

	return 0;
}