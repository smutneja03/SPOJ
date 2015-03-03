
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

typedef long long int lld;

using namespace std;

lld dp[5005];

lld get_codings(string code, int length){

	lld i;
	memset(dp, 0, sizeof(dp));

	if(code[0]!='0'){
		dp[0] = 1;
		//character can be formed
		//base case
	}

	string temp;
	for(i=1;i<length;i++){

		if(code[i]!='0'){
			dp[i] = dp[i-1];
			//assuming it to be a valid single character
		}
	

		if(code[i-1]=='1' || (code[i-1]=='2' && code[i]<='6')){
			//assuming it it forms a two letter character
			if(i-2>=0){
				dp[i] += dp[i-2];
			}
			else{
				dp[i] += 1;
			}
		}
	}

//	for(i=0;i<length;i++){
//		cout << "dp is " << dp[i] << endl;
//	}
	return dp[length-1];
}

int main(){

	string code;
	cin >> code;
	
	while(code!="0"){
		int length = code.size();

		lld solution = get_codings(code, length);

		cout << solution << endl;
		
		cin >> code;
	}
	
	return 0;
}
