
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

typedef long long int lld;

using namespace std;

lld lucky_numbers[3003];
int is_lucky[34003];

void precompute(){

	lld i, j;
	lld index = 0;
	for(i=2;i<=34000;i++){
		if(is_lucky[i]==0){//implies its a lucky number
			lucky_numbers[index] = i;
			index++;
			if(index==3001){
				break;
			}
			lld distance = 0;
			j = i+1;
			while(j<=34000){
				//i is marked as lucky
				//now every number at a distance i from it needs to be marked
				if(is_lucky[j]==0){
					distance++;//only move if the number is not marked
				}
				if(distance==i){
					distance = 0;
					is_lucky[j] = 1; 
				}
				
				j++;

			}
		}
	}
	
	is_lucky[0] = 1;
	is_lucky[1] = 1;//1 implies it is not lucky i.e. its not a prime number
}

int main(){

	precompute();

	lld number;
	cin >>number;

	while(number){

		cout << lucky_numbers[number-1] << endl;
		cin >> number;
	}

	return 0;
}