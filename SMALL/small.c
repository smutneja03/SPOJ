
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int gcd(long long int a, long long int b){

	if(b==0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}

}

long long int find_lcm(long long int a, long long int b){

	long long int solution = a/gcd(a, b);

	solution = solution*b;

	return solution;

}

int main(){

	int test_cases;
	scanf("%d", &test_cases);

	while(test_cases){

		int number;
		scanf("%d", &number);
		long long int solution = 1;
		int i = 0;
		for(i=2;i<=number;i++){
			solution = find_lcm(solution, i);
		}

		printf("%llu\n", solution);
		test_cases--;
	}

}