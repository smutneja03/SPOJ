#include <iostream>
typedef long long int lld;
using namespace std;
int main(){
	lld t;
	cin>>t;
	while(t){
		lld a,b,k;
		cin>>k>>a>>b;
		while(a!=b){
			if(a>b)
				a=(a+k-2)/k;
			else
				b=(b+k-2)/k;
		}
		cout<<a<<endl;
		t--;
	}	
	return 0;
}