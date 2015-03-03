
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b){

	return (*(int *)a - *(int *)b);
}

int main(){

	int test_cases;
	scanf("%d", &test_cases);

	while(test_cases){

		char c;
		scanf("%c", &c);

		int god_number, mecha_number;
		scanf("%d %d", &god_number, &mecha_number);
		int god_array[god_number];
		int mecha_array[mecha_number];
		int i;
		for(i=0;i<god_number;i++){
			scanf("%d", &god_array[i]);
		}
		for(i=0;i<mecha_number;i++){
			scanf("%d", &mecha_array[i]);
		}

		//need to sort the two arrays and extract from them
		qsort(god_array, god_number, sizeof(int), cmpfunc);
		qsort(mecha_array, mecha_number, sizeof(int), cmpfunc);

		int first = 0;
		int second = 0;

		while(first<god_number && second<mecha_number){

			if(god_array[first]<mecha_array[second]){
				first++;
			}
			else if(god_array[first]>mecha_array[second]){
				second++;
			}
			else{
				//both are same
				second++;
			}

		}
		if(first==god_number){
			//godzilla is over
			printf("MechaGodzilla\n");
		}
		else{
			printf("Godzilla\n");
		}

		test_cases--;
	}

	return 0;
}