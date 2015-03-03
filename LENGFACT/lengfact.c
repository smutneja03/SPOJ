
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

	int test_cases;
	scanf("%d", &test_cases);

	while(test_cases){

		long long number;
		scanf("%lld", &number);
		if(number==0||number==1||number==2){
			printf("1\n");
		}
		else{
			long long value = (log(2*M_PI*number)/2 + number*(log(number)-1))/log(10);

			long long solution = floor(value) + 1;

			printf("%lld\n", solution);
		}

		test_cases--;
	}

	return 0;

}
