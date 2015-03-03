
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void convert_string(string input){

	stack<char> stack_operators;
	queue<char> output;
	string operators = "+-*/^";
	string result;
	int i;

	for(i=0;i<input.size();i++){

		if(isalpha(input[i])){
			output.push(input[i]);
		}
		else if(operators.find(input[i]) != string::npos){
			//if character is an operand and not opening or closing braces
			while(operators.size()>0 && operators.find(stack_operators.top())!=string::npos 
					&& operators.find(input[i]) <= operators.find(stack_operators.top()) ){
				//while there are more operators in the stack
				//while the stack top contains valid operands
				//while the priority of incoming is less than the stack top
				//keep popping till this case arises
				output.push(stack_operators.top());
				stack_operators.pop();
			}
			stack_operators.push(input[i]);
		}
		else if(input[i]=='('){

			stack_operators.push(input[i]);
		}
		else if(input[i]==')'){

			while(!stack_operators.empty()){

				if(stack_operators.top()=='('){

					stack_operators.pop();
					break;
				}

				output.push(stack_operators.top());
				stack_operators.pop();
			}
		}
	}

	while(!stack_operators.empty()){
		output.push(stack_operators.top());
		stack_operators.pop();
	}

	while(!output.empty()){
		result = result + output.front();
		output.pop();
	}

	cout << result << endl;

}

int main(){

	int test_cases;
	scanf("%d", &test_cases);

	while(test_cases){

		string infix;
		cin >> infix;
		convert_string(infix);
		test_cases--;
	}

	return 0;
}