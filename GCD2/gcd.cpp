
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

typedef long long int lld;

using namespace std;

lld get_gcd(lld a, lld b){

	if(b==0){
		return a;
	}
	else{
		return get_gcd(b, a%b);
	}
}

lld get_second(lld first, string number){

	lld index = 0;
	lld n = 0;

	while(number[index]){

		n = n*10 + number[index] -'0';
	
		n = n%first;//will be done in the gcd as well
		//will keep the number in limit
		index++;
	}

	return n;
}

int main(){

	lld test_cases;
	cin >> test_cases;

	while(test_cases){

		lld first;string second;
		cin >> first >> second;

		if(first==0){
			cout << second << endl;
			//case when the string b is itself the output
		}
		else{
		
			lld convert_second = get_second(first, second);

			lld solution = get_gcd(first, convert_second);

			cout << solution << endl;
		}
		test_cases--;
	}

	return 0;
}