
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

long long int leftto[100005], rightto[100005], width[100005], matrix[1005][1005], solution[1005][1005];

void compute_sol(long long int row, int m){
	
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

  for(i=0;i<m;i++){
    width[matrix[row][i]] = max(width[matrix[row][i]], leftto[i]+rightto[i]+1);
    //at row = 0, we can have an height of 0 or 1
    //at row = 1, we can have an height of 0 or 1 or 2
  }

  long long int length = 0;

  for(i=0;i<=row;i++){
    length = max(length, width[row+1-i]);
    //length of significant width height will be considered
    //height of o widths are not considered
    solution[row][i] = length * (row+1-i);
    //at one row if we are checking width[i]
    //then in the row above it width[i-1] will be satisfied 
    //multiplication of row diff which will give us the result
  }

  for(i=row;i>=0;i--){

    if(row>0)
      solution[row][i] = max(solution[row][i], solution[row-1][i]);
    solution[row][i] = max(solution[row][i], solution[row][i+1]);
  }

}

int main(){

	long long int n, m, k, i, j;

  scanf("%llu %llu", &n, &m);

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      scanf("%llu", &matrix[i][j]);
      solution[i][j] = 0;
    }
  }


  //calculating histogram from the zero and 1 values in the matrix
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
  //till now we have created a multidimensional histogram

  for(i=0;i<n;i++){
    compute_sol(i, m);//passing the row histogram on which operation needs to be done
  }

  int queries;
  scanf("%d", &queries);

  while(queries){

    int low, high;
    scanf("%d %d", &low, &high);
    printf("%llu\n", solution[high-1][low-1]);
    queries--;
  }

  return 0;
}
