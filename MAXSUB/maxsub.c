
#include <stdio.h>
#include <stdlib.h>
#import <math.h>

#define mod 1000000009

long long get_power(int a, int b){

	if(b==0){
		return 1;
	}
	
	long long temp = get_power(a, b/2);

	if(b%2==0){
		return (temp*temp)%mod;
	}
	else{
		
		long long var = (temp*temp)%mod;
		return (a*var)%mod;

	}

}

int main(){

	int test_cases;
	scanf("%d", &test_cases);
	long long *array = (long long *)malloc(sizeof(long long ) * 50005);
	
	while(test_cases){

		int numbers;
		scanf("%d", &numbers);
		
		int i = 0, count = 0;
		while(i<numbers){

			scanf("%lld", &array[i]);
			if(array[i]<0){
				count++;
			}
			i++;
		}
		if(count==numbers){
			//all numbers are negative
			//get the count of the minimum element
			long long min_element = array[0];
			count = 1;
			for(i=1;i<numbers;i++){
				if(array[i]==min_element){
					count++;
				}
				else if(array[i]>min_element){
					min_element = array[i];
					count = 1;
				}
			}

			printf("%lld %d\n", min_element, count);
		}
		else{
			//elements are positive 
			int zeros = 0;
			long long solution = 0;
			int flag = 0;//case when only zeros are present
			for(i=0;i<numbers;i++){
				if(array[i]>0){
					solution+=array[i];
					flag = 1;
				}
				else if(array[i]==0){
					zeros++;
					//count equal to 2^zeros
				}
			}
			long long subsets = get_power(2, zeros)%mod;

			if(flag==0){
				//only zeros are present
				subsets = subsets-1;
			}

			printf("%lld %lld\n", solution, subsets);
		}

		test_cases--;
	}

	return 0;
}