
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>

#define mod 1000000007

typedef long long int lld;

using namespace std;

lld get_power(lld a, lld b){

	if(b==0){
		return 1;
	}
	lld solution = 1;

	while(b){	
		if(b%2==1){
			solution = (solution * a)%mod;
		}

		a = (a*a)%mod;
		b = b/2;
	}

	return solution%mod;
}

int main(){

	lld options, length;
	cin >> options >> length;

	while(options!=0 && length!=0){

		lld solution = 0, i;

		for(i=1;i<=length;i++){
			solution = (solution + get_power(options, i))%mod;
		}

		cout << solution%mod << endl;
		cin >> options >> length;
	}

	return 0;
}