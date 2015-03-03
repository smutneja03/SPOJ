#include <iostream>
#include <algorithm>

using namespace std;

float array[1000];

void precompute(){

	array[0] = 0.00;
	int i;
	for(i=1;;i++){
		array[i] = array[i-1] + 1.00/(i+1);
		//cout << "Index max is " << i << " abd value us " << array[i];
		if(array[i]>=5.20){
			break;
		}
	}
}

int main(){

	precompute();

	double number;
	cin >> number;
	int i;
	while(number!=0.00){
		for(i=1;;i++){
			if(array[i]>=number){
				break;
			}
		}
		cout << i << " card(s)" << endl;
		cin >> number;
	}

}