#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b){
	return (a>b)?a:b;
}

int main(){

	int test_cases;
	int number_of_rows, i, j, k;
	scanf("%d", &test_cases);
	while(test_cases>0){
		scanf("%d", &number_of_rows);
		int input_matrix[number_of_rows][number_of_rows];
		int row = 1;
		while(row<=number_of_rows){
			int columns = 1;
			while(columns<=row){
				scanf("%d", &input_matrix[row-1][columns-1]);
				columns++;
			}
			row++;
		}
		int max_sum[number_of_rows][number_of_rows];
		max_sum[0][0] = input_matrix[0][0];
		for(i = 1;i<number_of_rows;i++){
			for(j=0;j<i+1;j++){
				if(j==0){
					max_sum[i][j] = input_matrix[i][j] + max_sum[i-1][j];
				}
				else if(j==i){
					max_sum[i][j] = input_matrix[i][j] + max_sum[i-1][j-1];
				}
				else{
					max_sum[i][j] = input_matrix[i][j] + maximum(max_sum[i-1][j], max_sum[i-1][j-1]);
				}
			}
		}
		int last_row = number_of_rows-1;
		int max_value = max_sum[last_row][0];
		for(k=1;k<number_of_rows;k++){
			if(max_sum[last_row][k] > max_value)
				max_value = max_sum[last_row][k];
		}
		printf("%d\n", max_value);
		test_cases--;
	}
	return 0;
}