
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long int lld;

map<lld, lld> cnt;//will count the occurences
map<lld, lld> position;//will keep a record of the position of the number
lld arr[1001]; //to record the numbers

bool cmpfunc(const lld &a, const lld &b){
	//the comparator function to store the numbers ny their order
	if(cnt[a]==cnt[b]){
		return position[a] < position[b];
		//if position of a is lower then its true
		//else swap
	}

	else{
		return cnt[a] > cnt[b];
	}
}

int main(){

	lld length, range;
	cin >> length >> range;
	lld i = 0, temp;
	while(i<length){
		cin >> arr[i];//recordded the number
		cnt[arr[i]]++;//recorded the frequency
		i++;
	}
	//now need to recird the position of the numbers
	for(int i=length-1;i>=0;i--){
		position[arr[i]] = i;//number coming first will be placed first
	}
	sort(arr, arr + length, cmpfunc);
	//print the numbers
	for(int i=0;i<length;i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;

}