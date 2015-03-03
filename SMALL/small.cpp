
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void precompute(int *primes){

	int i, j;
	for(i=2;i*i<=10000;i++){

		if(primes[i]==0){
			for(j=2;i*j<=10000;j++){

				primes[i*j] = 1;
			}
		}
	}

	primes[0] = 1;
	primes[1] = 1;

}

int main(){

	int test_cases;
	cin >> test_cases;
	int *primes =  (int *)calloc(10005, sizeof(int));
	int *prime_values = (int *)malloc(sizeof(int)*10000);

	precompute(primes);

	int i, index = 0;
	for(i=0;i<=10000;i++){
		if(primes[i]==0){//prime value it is
			//copy it to values 
			prime_values[index] = i;
			printf("%d\n", i);
			index++;
		}
	}

	while(test_cases){

		int number, solution = 1;
		cin >> number;
		
		int temp = 0;

		while(temp<=index-1 && prime_values[temp] <= number){
		
			solution = (solution*prime_values[temp])%1000000007;
			temp++;
		}

		cout << solution << endl;
		test_cases--;
	}

	return 0;
}