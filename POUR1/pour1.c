
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int min(int a, int b){

	return (a>b)?b:a;

}

int gcd(int a, int b){

	if(b==0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}

}

int get_moves(int A, int B, int C){

	int a, b;
	a = A;b = 0;
	int moves = 1;
	//a and b are the current level in the first and the second container resp.
	//transfer will be made from a to b
	//so the min of a and the remaining from b will be the transfered amount

	while(a!=C && b!=C){

		int temp = min(a, B-b);
		a = a-temp;
		b = b+temp;
		moves++;

		if(a==C || b==C){
			break;
		}
		if(a==0){
			a = A;
			moves++;
		}
		if(b==B){
			b = 0;
			moves++;
		}
	}
	return moves;

}

int main(){

	int test_cases;
	scanf("%d", &test_cases);
	/*
	fill A, empty it into B. whenever A becomes empty fill 
	it back, whenever B becomes full empty it. 
	(all the above mentioned actions count as individual moves).
	 Continue this process until you arrive at the required amount of water 
	 in any one of the vessels. Get the number of moves here. (say C1). 
	 method 2 - fill B, empty it into A. whenever B becomes empty 
	 fill it back, whenever A becomes full empty it. Continue this 
	 until you arrive at the required amount. Get the number of moves 
	 say C2). The answer is min(C1,C2).
	*/
	while(test_cases){
		int A, B, C;
		scanf("%d", &A);
		scanf("%d", &B);
		scanf("%d", &C);

		if(C>A && C>B){
			printf("-1\n");
		}
		else if(C==A || C==B){
			printf("1\n");
			//initially both are empty
		}
		else if(C%gcd(A, B)!=0){
			printf("-1\n");//this is to make sure the required amount is obtained
			//else the amount will be in the order of gcd only, no solution
		}
		else{
			int moves = min(get_moves(A, B, C), get_moves(B, A, C));
			printf("%d\n", moves);
		}

		test_cases--;
	}

	return 0;
}