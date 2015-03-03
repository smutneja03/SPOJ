
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	char string[1005];

	while(scanf("%s", string)!=EOF){

		int length = strlen(string);
		int count = 0;
		int flag, i, current_flag;
		
		//changing from the second character
		char ch = string[0];
		if(ch>='A' && ch<='Z'){
			flag = 1; //upper case character
		}
		else{
			flag = 0; //lower case character
		}
		for(i=1;i<length;i++){
			ch = string[i];
			if(ch>='A' && ch<='Z'){
				current_flag = 1;
			}
			else{
				current_flag = 0;
			}

			if( (flag==1 && current_flag==1) || (flag==0 && current_flag==0) ){

				count++;
				if(current_flag){
					flag = 0;//if current character is upper case
					//it is converted to lower case
				}
				else{
					flag = 1;//current to upper case
				}
			}

			else{
				flag = current_flag;
			}
		}

		//changing the first character itself
		ch = string[0];
		if(ch>='A' && ch<='Z'){
			flag = 0; //transformed to lower case character
		}
		else{
			flag = 1; //transformed to upper case character
		}
		int count_second = 1;
		for(i=1;i<length;i++){
			ch = string[i];
			if(ch>='A' && ch<='Z'){
				current_flag = 1;
			}
			else{
				current_flag = 0;
			}

			if( (flag==1 && current_flag==1) || (flag==0 && current_flag==0) ){

				count_second++;
				if(current_flag){
					flag = 0;//if current character is upper case
					//it is converted to lower case
				}
				else{
					flag = 1;//current to upper case
				}
			}

			else{
				flag = current_flag;
			}
		}

		printf("%d\n", (count<count_second)?count:count_second);

	}

	return 0;
}