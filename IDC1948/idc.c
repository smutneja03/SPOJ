
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int get_digits(long long int number){

	int count = 0;
	while(number>0){
		number = number/10;
		count++;

	}
	return count;
}

void precompute(int *primes){

	int i, j;
	for(i=2;i*i<=6000;i++){

		if(primes[i]==0){

			for(j=2;i*j<=6000;j++){

				primes[i*j] = 1;
				//number at i*j is not a prime
			}
		}
	}
	primes[0] = 1;
	primes[1] = 1;

}
int main(){

	int test_cases;
	scanf("%d", &test_cases);

	int *primes = (int *)calloc(6000, sizeof(int));

	precompute(primes);

	int *prime_values = (int *)calloc(6000, sizeof(int));

	int i = 0;
	int index = 0;
	for(i=0;i<=6000;i++){

		if(primes[i]==0){
			prime_values[index] = i;
			index++;
		}

	}

	while(test_cases){
		long long int number, solution;
		scanf("%lld", &number);
		int digits = get_digits(number);
		long long int value = pow(10, digits) -1;
		long long int first = number;
		long long int second = value;
		long long int diff = second - 2*first;
		//here we need to find out the smallest prime that divides diff
		diff = (diff<0)?-1*diff:diff;
		if(diff==1){
			printf("-1\n");
		}
		else{
			i = 0;
			for(i=0;i<index;i++){
				if(diff%prime_values[i]==0){
					solution = prime_values[i];
					break;
				}
			}
			if(i == index){
				solution = diff;
			}
			printf("%lld\n", solution);
		}

		test_cases--;
	}

	return 0;
}