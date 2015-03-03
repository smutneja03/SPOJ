
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define mod 1000000007

long long int get_fibonacci(long long int number){

	if(number==0){
		return 0;
	}
	else if(number==1){
		return 1;
	}
	else if(number==2){
		return 1;
	}
	
	//F(n)=2*F(n-1)+3*F(n-2) this is the fibonacci
	number = number-2;//we already know the first two terms
	long long int sum=0, i, j, k;
	long long int M[2][2] = {1, 1, 1, 0};
	long long int temp[2][2] = {1, 0, 0, 1};

	while(number>0){

		if(number%2!=0){
			//number formed is odd
			long long int a = (temp[0][0]*M[0][0] + temp[0][1]*M[1][0]);
			long long int b = (temp[0][0]*M[0][1] + temp[0][1]*M[1][1]);
			long long int c = (temp[1][0]*M[0][0] + temp[1][1]*M[1][0]);
			long long int d = (temp[1][0]*M[0][1] + temp[1][1]*M[1][1]);

			temp[0][0] = a%mod;
			temp[0][1] = b%mod;
			temp[1][0] = c%mod;
			temp[1][1] = d%mod;
		}


		number = number/2;

		if(number>0){
			long long int a = (M[0][0]*M[0][0] + M[0][1]*M[1][0]);
			long long int b = (M[0][0]*M[0][1] + M[0][1]*M[1][1]);
			long long int c = (M[1][0]*M[0][0] + M[1][1]*M[1][0]);
			long long int d = (M[1][0]*M[0][1] + M[1][1]*M[1][1]);

			M[0][0] = a%mod;
			M[0][1] = b%mod;
			M[1][0] = c%mod;
			M[1][1] = d%mod;
		}
	}

	long long int solution = (temp[0][0]*1 + temp[0][1]*1)%mod;
	return solution;

}

int main(){
	
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases){
		long long int start, end;
		scanf("%llu %llu", &start, &end);
		//sum(m) = fib[m+2] - 1
		//sum of first m fibonacci terms can be derived from fibonacci series itself

		long long int solution = (get_fibonacci(end+2) - get_fibonacci(start+1) + mod)%mod;
		printf("%llu\n", solution);
		test_cases--;
	}
	
	return 0;
}
