
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>

typedef long long int lld;

using namespace std;

int main(){

	lld test_cases;
	cin >> test_cases;
	//(0, 0)-->0
	//(1, 1)-->1
	//(2, 0)-->2
	//(2, 2)-->4
	//(3, 1)-->3
	//(3, 3)-->5
	//(4, 2)-->6
	//(4, 4)-->8
	while(test_cases){

		lld x, y;
		cin >> x >> y;

		if(x==y || x==y+2){
			//it means the point is present in the graph
			//if the point is odd then 1 is subtracted
			lld diff = x&1;//will store 1 if x is odd
			//this number needs to be removed
			lld solution = x+y-diff;
			cout << solution << endl;

		}
		else{
			cout << "No Number" << endl;
		}

		test_cases--;
	}
	
	return 0;
}