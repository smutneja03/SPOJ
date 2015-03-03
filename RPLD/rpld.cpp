
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <unistd.h>
#include <cmath>
#include <set>


typedef long long int lld;

using namespace std;

lld **matrix;

int main(){

	lld test_cases, test_count = 1;
	cin >> test_cases;

	while(test_cases){

		set<pair <lld, lld> > list;
		lld n, r;
		cin >> n >> r;
		lld i = 0;
		while(i<r){
			lld student, code;
			cin >> student >> code;
			list.insert(make_pair(student, code));
			i++;
		}
		if(list.size()==r)
			cout << "Scenario #" << test_count << ": " << "possible" << endl;
		else
			cout << "Scenario #" << test_count << ": " << "impossible" << endl;

		//need to take empty line
		string extra;
		getline(cin, extra);
		test_cases--;test_count++;
	
	}
	return 0;
}