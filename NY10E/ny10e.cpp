#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lld;

lld dp[65][10];
//dp[i][j] stores the solution for i number of digits where the last digit can be j

void precompute(){

	lld i, j, k;

	for(i=0;i<10;i++){
		dp[0][i] = 1;
		//number of combinations for length 0 is 1
		//base case
	}
	//uses the concept of memoization
	for(i=1;i<=65;i++){
		//i is the length of the number
		for(j=0;j<10;j++){
			//j is the max value of the last digit that is possible
			for(k=0;k<=j;k++){
				//k checks for all the lesser and equal values to the last digit 
				//with one digit less
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	
}

int main(){

	precompute();

	int test_cases;
	cin >> test_cases;

	while(test_cases){

		int index, number;
		cin >> index >> number;
		cout << index << " " << dp[number][9] << endl;

		test_cases--;
	}

	return 0;
}