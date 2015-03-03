
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

	lld length, temp, i = 0, solution = 0;
	//cin >>length;
	scanf("%lld", &length);
	while(i<length){
		scanf("%lld", &temp);
		solution = solution ^ temp;
		i++;
	}
	printf("%lld\n", solution);
	//cout << solution << endl;
	return 0;
}