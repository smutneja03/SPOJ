
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print_array(long long int elements, char *string_number){
	
	long long int index = 0;
	while(index<elements){
		printf("%c", string_number[index]);
		index++;
	}

	printf("\n");
}

void swap(long long int a, long long int b, char *string_number){

	char temp = string_number[a];
	string_number[a] = string_number[b];
	string_number[b] = temp;
}

void sort_digits(long long int start, long long int elements, char *string_number){

	long long int i = start;
	long long int j = elements-1;

	int *count = (int *)calloc(10, sizeof(int));

	int k;
	for(k=i;k<=j;k++){
		int index = string_number[k]-'0';
		count[index]++;
	}
	//need to place these in the string_number string array now
	k = 0;
	char int_char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	while(k<=9){
		long long int c = count[k];
		while(c){
			string_number[i++] = int_char[k];
			c--;
			//i is the current position in the string
		}
		k++;
	}

}

void rearrange_number(long long int elements, char *string_number){

	long long int temp = elements-1;
	long long int i;

	while(temp >= 1 && string_number[temp]<=string_number[temp-1]){
		temp--;
	}
	
	if(temp==0){
		printf("-1\n");
	}
	
	else{
		//find the next bigger digit than this in the right
		char curr_digit =  string_number[temp-1];
		char bigger_digit = string_number[temp];
		long long int bigger_index = temp;
		for(i=temp+1;i<=elements-1;i++){
			if(string_number[i] > curr_digit && string_number[i] < bigger_digit){
				bigger_digit = string_number[i];
				bigger_index = i;
			}
		}
		swap(temp-1, bigger_index, string_number);

		sort_digits(temp, elements, string_number);

		print_array(elements, string_number);
		
	}
}

int main(){

	long long int test_cases, i;
	scanf("%llu", &test_cases);
	
	while(test_cases){

		long long int elements;
		scanf("%llu", &elements);
		long long int index = 0;
		char *string_number = (char *)malloc(sizeof(char) * (elements+1)) ;
		while(index<elements){
			int digit;
			scanf("%d", &digit);
			char int_char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			char ch = int_char[digit];
			string_number[index] = ch;
			index++;
		}
		
		//need to rearrange the array in order to satisfy the condition
		rearrange_number(elements, string_number);

		test_cases--;
	}

	return 0;
}