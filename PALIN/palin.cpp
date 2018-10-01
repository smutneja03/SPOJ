
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

	int test_cases;
	cin >> test_cases;

	while(test_cases){

		string palindrome;
		cin >> palindrome;
	       unsigned int length = palindrome.length();

		//need to make it uniform at both ends
		//start copying from the start till the end
		int i = 0, j = length-1;
		bool number_increased = false;
		while(i<=j){
			if(palindrome[i] > palindrome[j]){
				palindrome[j] = palindrome[i];
				number_increased = true;
			}
			else if(palindrome[i]<palindrome[j]){
				palindrome[j] = palindrome[i];
				number_increased = false; //number is given a smaller value
			}
			i++;j--;
		}
		i--;
		//i now points to the middle element
		if(number_increased==false){
			//next greatest palindrome needs to be formed
			if(i>=0 && i<length){
				//i lies in the middle, both for even and odd length
				if(palindrome[i]!='9'){
					palindrome[i]++;
					palindrome[length-1-i] = palindrome[i];
				}
				else{
					while(i>=0 && palindrome[i]=='9'){
						//move towards the start and replace it with 0
						palindrome[i] = '0';
						palindrome[length-1-i] = '0';
						i--;
					}

					if(i>=0){
						//means reached a digit which is not 9
						palindrome[i]++;
						palindrome[length-i-1] = palindrome[i];
					}
					else{
						//reached the start
						//need to insert a 1 before the string, 1+ 00000 +1
						palindrome = '1' + palindrome;
						palindrome[palindrome.length()-1] = '1';
					}
				}
			}

		}
		cout << palindrome << endl;
		test_cases--;
	}

	return 0;
}
