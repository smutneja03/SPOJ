
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long int solve_ncr(int n, int r){

	long long int solution = 1;
	int i;

	if(r>n/2){
		r = n-r;
	}
	
	for(i=0;i<r;i++){
		solution = solution*n;
		solution = solution/(i+1);
		n--;
	}
	return solution;
}

int main(){

	int test_cases;
	cin >> test_cases;

	while(test_cases){

		long long int r, n;
		//here n are the different colors of the marble
		//r is the number of stones that needs to be selected
		cin >> r >> n;
		//one stone of each is intially required
		r = r-n;
		//now r stones need to be put together with n diff colors with repetitions allowed
		//(n+r-1)Cr
		n = n + r -1;

		long long int solution = solve_ncr(n, r);

		cout << solution << endl;

		test_cases--;
	}

	return 0;
}