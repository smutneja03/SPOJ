
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

typedef long long int lld;

using namespace std;

//making space for the pair combinations
vector <pair<lld, lld> > permut(100000+5);
vector <pair<lld, lld> > inverse(100000+5);
//here we are having bvector of pairs
int main(){

	lld numbers;
	cin >> numbers;	

	while(numbers){
		lld index = 1;
		pair <lld, lld> temp;
		while(index<=numbers){
			cin >> temp.first;
			temp.second = index;
			permut[index] = temp;
			//storing the same in the second pair
			inverse[index] = temp;
			//reversing the order fot inverse
			index++;
		}
		//need to sort the inverse pair on the basis of the second value
		lld i;
	
		sort(inverse.begin() + 1, inverse.begin() + numbers+1);
		
		lld flag = 0;//0 everything is same
		for(i=1;i<=numbers;i++){
			if(permut[i].first!=inverse[i].second || permut[i].second!=inverse[i].first){
				flag = 1;
				break;
			}
		}

		if(flag==0){
			cout << "ambiguous" << endl;
		}
		else{
			cout << "not ambiguous" << endl;
		}
		cin >> numbers;
	}

	return 0;
}