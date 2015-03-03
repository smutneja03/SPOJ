
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

lld get_gcd(lld a, lld b){

	if(b==0){
		return a;
	}
	else{

		return get_gcd(b, a%b);
	}

}

lld get_lcm(lld a, lld b){

	return (a*b)/get_gcd(a, b);

}

int main(){


	lld a, b, solution;
	cin >> a >>b;

	while(a!=0 && b!=0){

		lld lcm = get_lcm(a, b);
		solution = (lcm/a)*(lcm/b);
		cout << solution << endl;
		cin >> a >> b;
	}

	return 0;
}