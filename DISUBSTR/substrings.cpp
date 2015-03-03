
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

typedef long long int lld;

using namespace std;

struct suffix{

	lld index;
	string suf;

};

struct suffix suffixes[1005];

lld *suffix_array = new lld[1005];

lld lcp(string a, string b){

	lld m = a.size();
	lld n = b.size();

	lld index = 0;
	lld solution = 0;
	while(index<m && index<n){
		//while index is less than both the strings
		if(a[index]==b[index]){
			solution++;
			index++;
		}
		else{
			return solution;
		}
	}

	return solution;
}

int cmpfunc(struct suffix a, struct suffix b){

	if(a.suf < b.suf){
		return 1;
	}
	else{
		return 0;//swap the strings in case of a false condition
	}

}

lld *build_suffix_array(string txt){
	
	lld length = txt.size();
	lld i;
	for(i=0;i<length;i++){
		suffixes[i].index = i;
		suffixes[i].suf = txt.substr(i, length);
	}
	//suffix array stores the suffixes of all the suffix
	//along with the start of the index of the string position

	sort(suffixes, suffixes+length, cmpfunc);

	for(i=0;i<length;i++){
		suffix_array[i] = suffixes[i].index;
	}

	return suffix_array;
}

lld get_count(string input, lld *suffix_array){

	lld length = input.size();
	lld solution = (suffixes[0].suf).size();
	lld i;
	for(i=0;i<length-1;i++){
		lld temp = (suffixes[i+1].suf).size() - lcp(suffixes[i+1].suf, suffixes[i].suf);
		if(temp<0){
			temp =  temp*-1;
		}
		solution += temp;
	}

	return solution;

}

int main(){

	lld test_cases;
	cin >> test_cases;
	while(test_cases){

		string input;
		cin >> input;
		lld *suffix_array = build_suffix_array(input);
		lld solution = get_count(input, suffix_array);
		cout << solution << endl;

		test_cases--;
	}

	return 0;
}