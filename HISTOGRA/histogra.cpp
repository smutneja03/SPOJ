
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cstring>//used for memset

using namespace std;

long long int leftto[100005], rightto[100005], width[100005];

long long int get_area(long long int *array, long long int size){
	
  long long int i;
	stack<long long int> s;

  	for(i=0;i<size;i++){
    	leftto[i] = 0;
    	rightto[i] = 0;
  	}

  	long long int temp;//to store indexes

  	//calculating leftto boundaries for each of the bar
  	for(i=0;i<size;i++){

    	while(!s.empty()){
      		//case when stack is not empty
      		if(array[s.top()]>=array[i]){
        	//if the incoming element is less than the top of the stack
        		s.pop();
      		}
      		else{
        		break;
        		//incoming element is more
      	   	}
    	}

    	if(s.empty()){
    		temp = 0;
    	}
    	else{
    		temp = s.top()+1;
    	}

    	leftto[i] = i - temp;
    	s.push(i);
    	
	}
	//empty the stack to store the rightto indexes

	while(!s.empty()){
		s.pop();
	}

	//calculating rightto boundaries for each of the bar
  	for(i=size-1;i>=0;i--){

    	while(!s.empty()){
      		//case when stack is not empty
      		if(array[s.top()]>=array[i]){
        	//if the incoming element is less than the top of the stack
        		s.pop();
      		}
      		else{
        		break;
        		//incoming element is more
      	   	}
    	}

    	if(s.empty()){
    		temp = size-1;
    	}
    	else{
    		temp = s.top()-1;
    	}

    	rightto[i] = temp-i;
    	s.push(i);

	}
	//empty the stack to store the rightto indexes

	while(!s.empty()){
		s.pop();
	}

	//finding width for each of the bar present
	memset(width, 0, sizeof(width));

	for(i=0;i<size;i++){
		width[i] = leftto[i] + 1 + rightto[i];
	}

	long long int solution = width[0]*array[0];

	for(i=1;i<size;i++){

		long long int area = width[i]*array[i];
		if(solution<area){
			solution = area;
		}
	}

	return solution;

}

int main(){

	long long int numbers;
	scanf("%llu", &numbers);
	long long int *array = (long long int *)malloc(sizeof(long long int) * 100005);

	while(numbers!=0){

		long long int i = 0;
		while(i<numbers){
			scanf("%llu", &array[i]);
			i++;
		}

  		long long int solution = get_area(array, numbers);

  		printf("%llu\n", solution);
  		
  		scanf("%llu", &numbers);
  	}

  	return 0;
}
