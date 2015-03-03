
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

	lld number;
	cin >> number;
	//if number is a power of two then it will stop
	if(!(number&(number-1))){
		cout << "TAK" << endl;
	}
	else{
		cout << "NIE" << endl;
	}

	return 0;
}