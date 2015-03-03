
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <unistd.h>
#include <cmath>

typedef long long int lld;

using namespace std;

int main(){

	lld integer;
	cin >> integer;

	if(integer%10==0){
		//in this case second person always wins
		cout << "2" << endl;
	}
	else{
		cout << "1\n" << integer%10 << endl;
	}

	return 0;
}