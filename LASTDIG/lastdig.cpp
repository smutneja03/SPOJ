
#include <iostream>
using namespace std;

int l_d(long long int a, long long int b){

	if(b==0 && a==0){
		return 1;
	}
	long long int sol = 1;
	while(b>0){
		if(b%2==1){
			sol = sol*a;
		}
	
		a = a*a;
		a = a%10;//at each  step we only want the last significant bit
		sol = sol%10;
		if(sol==0){
			break;
		}
		b = b/2;
		
	}
	return sol;
}

int main(){

	long long int t, a, b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << l_d(a, b) << endl;
 	}

	return 0;
}