#include <iostream>
#include <algorithm>

using namespace std;

int array[35];

void precompute(){

	array[0] = 0;
	array[1] = 0;
	array[2] = 3;
	//for each increment of 2 we will be adding a value of 3 and for each
	//increment of 4 we will be adding a value of 2
	for(int i=3;i<=30;i++){
		array[i] = 3*array[i-2];
	}
}

int main(){

	precompute();

	int number;
	cin >> number;
	int i;
	while(number!=-1){
		
		cin >> number;
	}

}