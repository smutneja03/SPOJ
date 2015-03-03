
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <unistd.h>
#include <cmath>
#include <set>
#include <iterator>

typedef long long int lld;

using namespace std;

int main(){

	lld test_cases, test_count = 1;
	cin >> test_cases;
	
	while(test_cases){
		set<int> first;
		set<int> second;
		lld n, r;
		cin >> n >> r;
		lld i = 0, flag = 0;//if flag = 0 everything is fine
		while(i<r){
			lld from, to;
			cin >> from >> to;
			first.insert(from);
			second.insert(to);
			i++;
		}
		//need to scan the two arrays and check if their is a common element
		set<int>::iterator f;
		set<int>::iterator s;
		f = first.begin();s = second.begin();
		int j = 0, k = 0;
		while(f!=first.end() && s!=second.end()){
			if(*f==*s){
				flag = 1;
				break;
			}
			else if(*f>*s){
				s++;
			}
			else{
				f++;
			}
		}

		if(flag==0)
			cout << "Scenario #" << test_count << ": " << "spying" << endl;
		else
			cout << "Scenario #" << test_count << ": " << "spied" << endl;

		//need to take empty line
		string extra;
		getline(cin, extra);
		test_cases--;test_count++;
	
	}
	return 0;
}