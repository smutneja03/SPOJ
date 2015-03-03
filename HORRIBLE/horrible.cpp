
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
 
long long tree[500000];
long long lazytree[500000];
 
void Build(long long start, long long end, long long index){

	lazytree[index] = 0;
	tree[index] = 0;
	if(start!=end){
		Build(start, (start + end)/2, index*2 + 1 );
		Build((start + end)/2 + 1, end, index*2 + 2 );
	}
}

void MarkChild(long long start, long long end, long long index){

	lazytree[2*index + 1] += lazytree[index];
	lazytree[2*index + 2] += lazytree[index];
	tree[index] += (end - start + 1)*lazytree[index];
	lazytree[index] = 0;
}

long long Query(long long start, long long end, long long range_start, long long range_end, long long index){

	if(range_start > end || range_end < start)
		return 0;

	else if(range_start <= start && range_end >= end){
		return tree[index] + (end - start + 1)*(lazytree[index]);
		
	}

	else{
		
		MarkChild(start, end, index);
		
		return Query(start, (start + end)/2, range_start, range_end, 2*index + 1) 
				+ Query((start + end)/2 + 1, end, range_start, range_end, 2*index + 2);
	}
}


long long update(long long start, long long end, long long range_start, long long range_end, long long value, long long index){
	
	if(range_start > end || range_end < start)
		return 0;
	else if(range_start <= start && range_end >= end){
		lazytree[index] += value;
		return (end - start + 1)*value;
	}
	else{

		long long vc = update(start, (start + end)/2, range_start, range_end, value, index*2 + 1)
						 + update((start + end)/2 + 1, end, range_start, range_end, value, index*2 + 2);
		tree[index] += vc;//after the childrens are updated its turn of their parent
		return vc;
	}
} 
 
int main(){

	long long int test_cases, p, q, v, length, type, commands;
	
	cin >> test_cases;

	while(test_cases){
		cin >> length >> commands;
		Build(0, length-1, 0);
		long long int i;
		for(i = 0; i < commands; i++){
			cin >> type;
			if(type==0){
				cin >> p >> q >> v;
				p--;q--;
				update(0, length-1, p, q, v, 0);
			}
			else{
				cin >> p >> q;
				p--;q--;
				cout << Query(0, length-1, p, q, 0) << endl;
			}
		}
		test_cases--;
	}
	return 0;
}
