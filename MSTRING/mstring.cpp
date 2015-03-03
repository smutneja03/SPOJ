
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>

typedef long long int lld;

#define inf 33333

lld occurence[1003][1003], dp[1003][1003];
using namespace std;

lld min(lld a, lld b){

	return (a<=b)?a:b;
}

int main(){

	string first, second;
	lld i, j, k, l, n, m;
	cin >> first >> second;
	n = first.size();
	m = second.size();
	//need to find the smallest subsequence of first
	//that is not present in second
	//algo
	//if a character is not present, then smallest subsequence is 1
	//else option is that chaarcetr is included or not

	for(i=0;i<n;i++){
		lld prev = -1;
		for(j=0;j<m;j++){
			if(first[i]==second[j]){
				prev = j;//exact position, 0 indexed
			}
			occurence[i+1][j+1] = prev;//here it stores that ith characetr of string 1
			//is found in string 2 at which latest location

		}
	}

	for(i=1;i<=n;i++){
		dp[i][0] = 1;
		//dp gives us the smallest subsequence of string a which is not present in string b
		//length of b is 0 implies the solution to be 1
	}

	for(i=0;i<=m;i++){
		dp[0][i] = inf;
		//shortest subsequence is infinite if string 1 is empty
		//there is no way to find out the occurence of characters in string 2
	}

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(occurence[i][j]==-1){
				//checking if the i-1th characetr exists till j-1 positions in the string
				//if it doesnt exist
				dp[i][j] = 1;
			}
			else{
				//if the chaarcetr exists
				dp[i][j] = min(1 + dp[i-1][occurence[i][j]], dp[i-1][j]);
				//cout << dp[i][j] << " is dp[" << i <<"]"<<"["<<j<<"]"; 
				//if the character is present 
				//option is its a part of the smallest subsequence
				// or it is not a part of the sequence
			}
		}
	}

	cout << dp[n][m] << endl;
	return 0;
}

