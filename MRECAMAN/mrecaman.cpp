
#include <iostream>
#include <string>
#include <algorithm>

long long array[3500000];
//will be a boolean are to store whether the number is present
long long solution[3500000];

int main(){
	
	
	solution[0] = 0;
	long long i, temp_more, temp_less;
	array[0] = 1;
	for(i=1;i<=500000;i++){
		//array[i] = array[i-1] + i or -i 
		temp_less = solution[i-1] - i;
		temp_more = solution[i-1] + i;
		if(temp_less>0 && array[temp_less]==0){
			array[temp_less] = 1;
			solution[i] = temp_less;
		}
		else{
			array[temp_more] = 1;
			solution[i] = temp_more;
		}
	}
	/*
	The limits clearly indicate that we should pre-compute the sequence, 
	which is a very easy task once you can estimate 
	what could be the maximum value upto which it can go. Here, i have taken it 
	to go till seven times the number itself.
	*/
	long long int number;
	scanf("%lld", &number);

	while(number!=-1){

		printf("%lld\n", solution[number]);
		scanf("%lld", &number);
	}


	return 0;
}