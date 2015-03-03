
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>

typedef long long int lld;

using namespace std;

int main(){

	lld test_cases, i;
	cin >> test_cases;

	while(test_cases){

		lld length, number;
		cin >> length;
		lld i = 0;
		lld sum = 0;
		while(i<length){
			cin >> number;
			sum+=number;
			i++;
		}

		if(sum%length==0){
			//numbers can be rearranged around the center and all can be equal
			//if the sum of the numbers is divible by the number of numbers
			cout << length << endl;
		}
		else{
			//else other than 1 all can be managed to have the same value
			cout << length-1 << endl;
		}

		test_cases--;
	}

	return 0;
}