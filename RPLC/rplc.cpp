
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <unistd.h>
#include <cmath>

typedef long long int lld;

using namespace std;

int main(){

	lld test_cases, test_count = 1;
	cin >> test_cases;
	while(test_cases){

		lld length, i = 0;
		cin >> length;
		lld solution = 0, sum = 0;
		while(i<length){
			lld temp;
			cin >> temp;
			sum+=temp;
			if(sum<solution){
				solution = sum;
			}
			i++;
		}
		cout << "Scenario #" << test_count << ": ";
		if(solution==0){
			cout << "1" << endl;
		}
		else{
			solution *=-1;
			solution+=1;
			cout << solution << endl;
		}
		//need to take empty line
		string extra;
		getline(cin, extra);
		test_cases--;test_count++;
	}
	return 0;
}