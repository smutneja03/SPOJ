
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <set>
#include <vector>
#include <sstream>

typedef long long int lld;

using namespace std;

int main(){

	string input;

	while(getline(cin, input)){

		lld length = input.size();
		string solution = "";
		lld i = 0;

		while(i<length){

			char ch = input[i];
			i++;
			lld count = 1;
			while(i<length && input[i]==ch){
				i++;
				count++;
				if(count==9){
					break;
				}
			}
			//after the count is done, possibilities arises
			//1. run length is 1, check the continuous 1 lengths
			//2. run length is more than 1 less than equal to 9, append to string
			//3. greter than add to string, move ahead
			if(count>1){
				//case2 and case 3 taken care of
				string cnt = to_string(count);
				solution = solution + cnt + ch;
			}

			else{
				//here count is 1 of the character
				//i is pointing to the next character
				solution = solution + '1';
				//add the starting 1 to the solution and the starting ch
				i--;//needs
				while( (i==0 || i<length-1) && input[i]!=input[i+1]){
					if(input[i]=='1')
						solution+= "11";
					else
						solution+= input[i];
					i++;
				}
				if(i==length-1){
					if(input[i]=='1'){
						solution+="11";
					}
					else{
						solution+=input[i];
					}
					i++;
				}
				solution = solution + '1';
			}
		}

		cout << solution << endl;
	}

	return 0;
}