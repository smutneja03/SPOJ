
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long int lld;

lld lcs[6200][6200];

lld max(lld a, lld b){
	if(a>=b){
		return a;
	}
	else{
		return b;
	}
}

lld get_lcs(string input, string reverse){

	lld m, n;
	m = input.size();
	n = reverse.size();

	lld i, j;

	for(i=0;i<=m;i++){

		for(j=0;j<=n;j++){

			if(i==0||j==0){
				lcs[i][j] = 0;
				//no common character if one of the string is empty
			}
			else if(input[i-1]==reverse[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
				//one common character found
			}
			else{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
				//if the current character of both the strings does not match
				//check for the max of the value with 
				//same chaarcter of the string and prev character of the strng
			}
		}
	}

	return lcs[m][n];

}

lld get_number(string input){

	lld length = input.size();
	lld i;
	string reverse;
	for(i=0;i<length;i++){
		reverse = input[i] + reverse;
	}//reverse will now store the reverse of the string

	//now we need to get the maximum length of the sequence with same characters
	lld len_common = get_lcs(input, reverse);
	//this will give us the length of the characters whose reverse which is required for the
	//palindrome is already present
	//length - len_common gives us the solution

	lld solution = length - len_common;

	return solution;

}

int main(){

	lld test_cases;
	cin >> test_cases;

	while(test_cases){

		string input;
		cin >> input;

		lld solution =  get_number(input);

		cout << solution << endl;

		test_cases--;
	}

	return 0;
}