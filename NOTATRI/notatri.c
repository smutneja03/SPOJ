

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int cmpfunc (const void * a, const void * b){

   return ( *(int*)a - *(int*)b );
}

int main(){

	int sides;
	scanf("%d", &sides);

	while(sides!=0){

		int i = 0, j, k;
		int *array = (int *)malloc(sizeof(int)*sides);
		while(i<sides){
			scanf("%d", &array[i]);
			i++;
		}

		qsort(array, sides, sizeof(int), cmpfunc);

		i = sides-1;
		int count = 0;

		while(i>=2){
			k = 0;
			j = i-1;
			while(j>k){
				if(array[i] > array[j] + array[k]){
					count += j-k;//here k and i being two of the sides of triangle
					k++;
				}
				else if(array[i]<=array[j]+array[k]){
					j--;
				}
			}
			i--;
		}

		printf("%d\n", count);
		scanf("%d", &sides);

	}

	return 0;
}