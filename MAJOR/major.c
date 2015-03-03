
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int array[1000005];

long long int get_count(long long int *array, int n, int element){

	long long int count = 0, i;
	for(i=0;i<n;i++){
		if(array[i]==element){
			count++;
		}
	}

	return count;

}

long long int get_majority(long long int *array, int n){

	long long int count = 1;
	long long int majority = array[0];
	long long int i;
	for(i=1;i<n;i++){
		if(array[i]==majority){
			count++;
		}
		else{
			count--;
		}

		if(count==0){
			majority = array[i];
			count = 1;
		}
	}

	return majority;

}

int main(){

	int test_cases;
	scanf("%d", &test_cases);

	while(test_cases){

		long long int number;
		scanf("%lld", &number);
		int i = 0;
		while(i<number){
			scanf("%lld", &array[i]);
			i++;
		}

		long long int majority = get_majority(array, number);
		long long int count_majority = get_count(array, number, majority);

		if(count_majority>number/2){
			printf("YES %lld\n", majority);
		}
		else{
			printf("NO\n");
		}
		test_cases--;
	}
	return 0;
}