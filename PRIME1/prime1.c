
#include <stdio.h>
#include <stdlib.h>

void precompute(int *primes){

	int i, j;
	for(i=2;i*i<=100000;i++){

		if(primes[i]==0){

			for(j=2;i*j<=100000;j++){

				primes[i*j] = 1;
				//number at i*j is not a prime
			}
		}
	}
	primes[0] = 1;
	primes[1] = 1;

}

int main(){

	//(1 <= m <= n <= 1000000000, n-m<=100000
	int *primes = (int *)calloc(100001, sizeof(int));
	//will store the primes til the top limit of sqrt(n)
	/*
	Notice that sieve works by eliminating composites using 
	their prime divisors, thus knowing all primes under sqrt(n), 
	we can use those to eliminate composites in range [m, n].
	*/	
	precompute(primes);

	int *prime_values = (int *)calloc(100001, sizeof(int));

	int i = 0;
	int index = 0;
	for(i=0;i<=100000;i++){

		if(primes[i]==0){
			prime_values[index] = i;
			index++;
		}

	}
	//till now with a total of index prime numbers in the range 2 to 100000

	//get input from the user
	int test_cases;
	scanf("%d", &test_cases);
	int begin;

	while(test_cases){

		int start, end, k;
		scanf("%d %d", &start, &end);
		int *solution = (int *)calloc(100001, sizeof(int));

		for(i=0;prime_values[i]*prime_values[i]<=end;i++){
			//prime values less than the sqrt(n) is only relevant to us
			int value = prime_values[i];
			//multiple of these values will be marked in the solution array
			if(start%value==0){
				begin = start;
			}
			else{
				begin = start/value*value + value;
			}

			if(begin==value){
				begin = 2*begin;
			}
			//begin is the first non prime value for a particular prime value
			//now from begin till we reach the end set the non prime values to 1
			for(k=begin;k<=end;k+=value){
				if(k<start){
					continue;
				}
				else{
					solution[k-start] = 1;
					//here we are setting the values that are not prime
				}
			}
		}

		//now we have all the values that are not prime
		//need to print the values that are prime
		for(i=0;i<=end-start;i++){
			if(solution[i]==0 && (i+start!=1)){

				printf("%d\n", i+start);
			}
		}

		printf("\n");
		test_cases--;
	}

	return 0;
}