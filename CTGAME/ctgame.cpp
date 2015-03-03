
# include <iostream>
# include <sstream>
# include <algorithm>
# include <cstdio>
# include <cmath>
# include <numeric>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>
# include <complex>

using namespace std;

long long int max(long long int a, long long int b){

  return (a>b)?a:b;

}

long long int leftto[1005], rightto[1005], width[1005], matrix[1005][1005];

long long int compute_sol(long long int row, int m){
	
    long long int i;
	stack<long long int> s;

    for(i=0;i<m;i++){
    	leftto[i] = 0;
    	rightto[i] = 0;
  	}

  	long long int temp;//to store indexes

  	//calculating leftto boundaries for each of the bar
  	for(i=0;i<m;i++){

    	while(!s.empty()){
      		//case when stack is not empty
      		if(matrix[row][s.top()]>=matrix[row][i]){
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
  	for(i=m-1;i>=0;i--){

    	while(!s.empty()){
      		//case when stack is not empty
      		if(matrix[row][s.top()]>=matrix[row][i]){
        	//if the incoming element is less than the top of the stack
        		s.pop();
      		}
      		else{
        		break;
        		//incoming element is more
      	   	}
    	}

    	if(s.empty()){
    		temp = m-1;
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

	//finding maximum width for each of the height present
	memset(width, 0, sizeof(width));
	long long int row_max = 0, value;

  	for(i=0;i<m;i++){
    	width[i] = leftto[i]+rightto[i]+1;
    	value = width[i]*matrix[row][i];
    	if(value > row_max){
    		row_max = value;
    	}
  	}

  	return row_max;

}

int main(){

	long long int test_cases;
	scanf("%llu", &test_cases);

	while(test_cases){

		long long int n, m;
		scanf("%lld %lld", &n, &m);

		long long int i, j;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				char input;
				scanf(" %c", &input);
				if(input=='R'){
					matrix[i][j] = 1;
					//cant be used
				}
				else if(input=='F'){
					matrix[i][j] = 0;
					//these will be used for building the necessary
				}
			}
		}
		
		//create a histogram so that max area can be calculated
		for(i=0;i<m;i++){
    		if(matrix[0][i]==0){
      			matrix[0][i] = 1;
    		}
    		else{
      			matrix[0][i] = 0;
    		}
  		}

  		for(i=1;i<n;i++){
    		for(j=0;j<m;j++){
      			if(matrix[i][j]==1){
        			matrix[i][j] = 0;
      			}
      			else{
        			matrix[i][j] += matrix[i-1][j] + 1;
      			}
    		}
  		}

  		long long int solution = 0;

  		for(i=0;i<n;i++){
  			long long int temp = compute_sol(i, m);
  			if(temp>solution){
  				solution = temp;
  			} 
  		}

  		printf("%llu\n", solution*3);
  		char extra;
  		scanf("%c", &extra);
		test_cases--;
	}

	return 0;
}
