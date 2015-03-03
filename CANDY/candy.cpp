
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>

typedef long long int lld;

using namespace std;

lld array[10003];

int main(){

	lld length, i;
	cin >> length;

	while(length!=-1){

		lld i = 0, sum = 0, solution = 0;
		while(i<length){
			cin >> array[i];
			sum+=array[i];
			i++;
		}

		if(sum%length==0){
			lld average = sum/length;
			for(i=0;i<length;i++){
				if(array[i]>average){
					solution += array[i]-average;
				}
			}
			cout << solution << endl;
		}
		else{
			cout << "-1" << endl;
		}

		cin >> length;
	}

	return 0;
}