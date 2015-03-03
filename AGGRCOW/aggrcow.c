
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmpfunc (const void * a, const void * b){

   return ( *(long long int*)a - *(long long int*)b );
}

long long int check_cows(long long int *positions, long long int n, long long int distance, long long int cows){

	long long int cows_number = 1;
	long long int last_position = positions[0];
	long long int i;
	for(i=1;i<n;i++){

		if(positions[i]-last_position>=distance){

			cows_number++;

			if(cows_number==cows){
				return 1;
			}

			last_position = positions[i];
		}
	}
	return 0;

}


int main(){

	long long int test_cases;
	scanf("%lld", &test_cases);

	while(test_cases){

		long long int stalls, cows;
		scanf("%lld %lld", &stalls, &cows);
		long long int *positions = (long long int *)malloc(sizeof(long long int) * stalls);
		long long int i = 0;
		while(i<stalls){
			scanf("%lld", &positions[i]);
			i++;
		}//all the positions are recorded

		qsort(positions, stalls, sizeof(long long int), cmpfunc);
		//all are in sorted order
		//need to maximise the minimum distance between k cows
		//binary search with the distance between the cows as the parameter
		long long int start = 0;//this distance can be obtained by all
		long long int end = positions[stalls-1] - positions[0];//this distance cannot be obtaned
		

		while(start+1<end){

			long long int mid = (start+end)/2;
			if(check_cows(positions, stalls, mid, cows)){
				//mid amount of maximum minimum distance is achievable
				//increase the distance
				start = mid;
			}
			else{
				end = mid;
				//decrease the distance
			}

		}

		printf("%lld\n", start);
		test_cases--;
	}

	return 0;
}