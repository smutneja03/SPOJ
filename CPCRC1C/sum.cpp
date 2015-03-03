
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <set>
#include <vector>

#define mod 1000000007
typedef long long int lld;

using namespace std;

lld get_pow(lld a, lld b){

	if(b==0){
		return 1;
	}
	lld solution = 1;
	while(b>0){

		if(b%2==1){
			solution = solution * a;
		}

		a = a*a;
		b = b/2;

	}

	return solution;
}
//http://math.stackexchange.com/questions/817038/sum-of-digits-of-number-from-1-to-n
//for more explanation
lld sum_digits(lld number){

	if(number<10){
		return number*(number+1)/2;
	}
	//need to decompose the number in the form a10^k + b
	//D(a10k+b)=(45ak)10k−1+a(a−1)210k+a(b+1)+D(b) .
	lld temp = number;
	lld expo = 0;
	while(temp/10>0){
		expo++;
		temp = temp/10;
		//temp finally will be holding a single digit number,most significant digit
	}
	lld a = temp;
	lld b = number%get_pow(10, expo);
	lld k = expo;
	lld solution = (45*a*k)*get_pow(10, k-1) + a*(a-1)*get_pow(10, k)/2 + a*(b+1)
					+ sum_digits(b);

	return solution;

}

int main(){

	
	lld start, end;
	cin >> start >> end;

	while(start!=-1 && end!=-1){
		lld solution = sum_digits(end) - sum_digits(start-1);

		cout << solution << endl;
		
		cin >> start >> end;	
	}

	return 0;
}