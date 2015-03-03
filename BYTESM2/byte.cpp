
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

typedef long long int lld;
using namespace std;

lld matrix[101][101];
lld solution_matrix[101][101];

lld max2(lld a, lld b){

	return (a>b)?a:b;
}

lld max3(lld a, lld b, lld c){

	if(a<=b && a<=c){
		return max2(b, c);
	}
	else if(b<=c && b<=a){
		return max2(a, c);
	}
	else{
		return max2(a, b);
	}

}

int main(){

	lld test_cases, i;
	cin >>test_cases;

	while(test_cases){

		lld rows, columns;
		cin >> rows >> columns;
		lld i, j;
		for(i=0;i<rows;i++){
			for(j=0;j<columns;j++){
				cin >> matrix[i][j];
			}
		}

		//building the solution matrix
		//initially building the row0
		for(i=0;i<columns;i++){
			solution_matrix[0][i] = matrix[0][i];
		}

		//now doing for every element, row wise
		for(i=1;i<rows;i++){
			for(j=0;j<columns;j++){
				//doing for each of the column in each row, one at a time
				//if its the first element
				if(j==0){
					solution_matrix[i][j] = matrix[i][j] + 
									 max2(solution_matrix[i-1][j], solution_matrix[i-1][j+1]);
				}
				else if(j==columns-1){
					solution_matrix[i][j] = matrix[i][j] + 
									 max2(solution_matrix[i-1][j], solution_matrix[i-1][j-1]);
				}
				else{
					//j lies in the middle
					solution_matrix[i][j] = matrix[i][j] +
							max3(solution_matrix[i-1][j-1], solution_matrix[i-1][j], solution_matrix[i-1][j+1]);
				}
			}
		}		

		//need to check the max value in the last row
		lld last_row = rows-1;
		lld max_value = solution_matrix[last_row][0];

		for(i=0;i<columns;i++){
			if(solution_matrix[last_row][i] > max_value){
				max_value = solution_matrix[last_row][i];
			}
		}

		cout << max_value << endl;

		test_cases--;
	}

	return 0;
}