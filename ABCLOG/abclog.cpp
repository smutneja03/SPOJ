
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

string num_binary, sol_binary;

void get_binary(lld number){

	if(number>1)
		get_binary(number/2);

	int ch = number%2;
	num_binary = num_binary + to_string(ch);
}

int main(){

	lld number;
	cin >> number;
	while(number!=-1){

		num_binary = "";
		get_binary(number);
		reverse(num_binary.begin(), num_binary.end());
		//output the decimal representation of the binary
		lld decimal = 0, length = num_binary.size()-1;
		for(int counter = 0; counter <=length; counter++)
    		if(num_binary[counter] == '1')
      			decimal += pow(2, length-counter);
		cout << decimal << endl;
		cin >> number;
	}

	return 0;
}