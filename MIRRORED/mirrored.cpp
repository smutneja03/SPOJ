
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

	char input[100];
	cin.getline(input, sizeof(input));
	cout << "Ready" << endl;
	while(1){
		if(input[0]==' ' && input[1]==' '){
			break;
		}
		else if( (input[0]=='b' && input[1]=='d') || (input[0]=='d' && input[1]=='b')){
			cout << "Mirrored pair" << endl;
		}
		else if((input[0]=='p' && input[1]=='q') || (input[0]=='q' && input[1]=='p')){
			cout << "Mirrored pair" << endl;
		}
		else{
			cout << "Ordinary pair" << endl;
		}
		//usleep(1000000);
		//cout << input << endl;
		cin.getline(input, sizeof(input));
	}	

	return 0;
}