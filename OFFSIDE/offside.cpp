
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <unistd.h>

typedef long long int lld;

using namespace std;

int main(){

	lld attackers, defenders;
	cin >> attackers >> defenders;

	while(attackers!=0 && defenders!=0){
		lld i = 0, min_value = 100000, temp;
		while(i<attackers){
			cin >> temp;
			if(temp<min_value){
				min_value = temp;
			}
			i++;
		}
		//now to avoid offside this min distance needs to be
		//greater than or equal to two players
		lld flag = 0;//offside
		i = 0;
		lld sol = 0;
		while(i<defenders){
			cin >> temp;
			if(min_value>=temp){
				sol++;
			}
			if(sol==2){
				flag = 1;
			}
			i++;
		}

		//check for the final condition
		if(flag==1){
			cout << "N" << endl;
		}
		else{
			cout << "Y" << endl;
		}

		cin >> attackers >> defenders;
	}
	
	return 0;
}