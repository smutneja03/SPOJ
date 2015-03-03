
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[3005][3005];
char string1[3005];
char string2[3005];

int min(int a, int b, int c){

	if(a <= b && a <= c){
		return a;
	}
	else if(b <= a && b <= c){
		return b;
	}
	else{
		return c;
	}
}

int main(){

	int test_cases, i, j;
	scanf("%d", &test_cases);

	while(test_cases){

		scanf("%s", string1);
		scanf("%s", string2);
		int m = strlen(string1);
		int n = strlen(string2);
		
		//first row covers first word of length m
		for(i=0;i<=m;i++){
			dp[i][0] = i;
		}
		//first column covers second word of length n
		for(i=0;i<=n;i++){
			dp[0][i] = i;
		}

		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){

				if(string1[i-1]==string2[j-1]){
					dp[i][j] = dp[i-1][j-1];
				}
				else{
					dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1);
				}
			}
		}
		printf("%d\n", dp[m][n]);
		test_cases--;
	}

	return 0;
}