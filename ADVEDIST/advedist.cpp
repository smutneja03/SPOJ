
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <unistd.h>
#include <cmath>
#include <set>
#include <iterator>

using namespace std;

int dp[1005][1005];

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

	string string1, string2;
	cin >> string1 >> string2;
	int i, j;
	while(string1!="*" && string2!="*"){

		
		int m = string1.size();
		int n = string2.size();
		
		//first row covers first word of length m
		for(i=0;i<=m;i++){
			dp[i][0] = i;
		}
		//first column covers second word of length n
		for(i=0;i<=n;i++){
			dp[0][i] = i;
		}
		int cost;
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){

				cost = (string1[i-1]==string2[j-1])?0:1;
				
				dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1]+cost);
				
				if(i>1 && j>1 && string1[i-1]==string2[j-2] && string1[i-2]==string2[j-1]){
					dp[i][j] = min(dp[i][j], dp[i-2][j-2]+cost);
					//cost for transposition is 0
				}
			}
		}
		printf("%d\n", dp[m][n]);
		cin >> string1 >> string2;
	}

	return 0;
}