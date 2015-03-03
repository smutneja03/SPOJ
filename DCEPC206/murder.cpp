
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <queue>
#include <vector>

#define mod 1000000007

typedef long long int lld;

lld array[100004];

using namespace std;

lld solution;

void merge(lld *array, lld start, lld mid, lld end){

	lld i;
	queue <lld> a, b, c;
	for(i=start;i<=mid;i++){
		a.push(array[i]);
	}
	for(i=mid+1;i<=end;i++){
		b.push(array[i]);
	}

	while(!a.empty() && !b.empty()){
		if(a.front() < b.front()){
			c.push(a.front());
			solution+=a.front()*b.size();
			a.pop();
		}
		else{
			c.push(b.front());
			b.pop();
		}
	}

	while(!a.empty()){
		c.push(a.front());
		a.pop();
	}

	while(!b.empty()){
		c.push(b.front());
		b.pop();
	}

	i = start;
	while(!c.empty()){
		array[i++] = c.front();
		c.pop();
	}

}

void merge_sort(lld *array, lld start, lld end){

	if(start<end){

		lld mid = (start+end)/2;
		merge_sort(array, start, mid);
		merge_sort(array, mid+1, end);
		merge(array, start, mid, end);

	}

}

int main(){

	lld test_cases;
	cin >> test_cases;

	while(test_cases){

		lld length, i = 0;
		cin >> length;
		while(i<length){
			cin >> array[i];
			i++;
		}
		solution = 0;
		merge_sort(array, 0,  length-1);
		//solution is the sum of all the values smaller than the concerned value for every index
		//lying before the given index
		cout << solution << endl;
		test_cases--;
	}

	return 0;
}