
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

	//take input till the number is not 0
	int square_length;
	cin >> square_length;
	while(square_length){
		//taking input till its not zero
		//solution is the sum of numbers from 1 to N
		lld solution = 0;
		for(int i=1;i<=square_length;i++){
			solution = solution + i*i;
		}
		cout << solution << endl;
		cin >> square_length;
	}

	return 0;
}