
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int inputs, k, solution=0;
	int temp=0;
	int number;

	scanf("%d %d", &inputs, &k);

	while(temp<inputs){

		scanf("%d", &number);

		if(number%k==0){

			solution = solution+1;
		}

		temp+=1;

	}

	printf("%d\n", solution);

	return 0;

}