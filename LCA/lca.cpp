
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

lld get_lca(lld *parent, lld a, lld b){
	
	lld *visited = new lld[1001];
	visited[a] = 1;
	while(parent[a]!=a){
		a = parent[a];
		visited[a] = 1;
		//here we reached the root of the tree
		//and on the way above we have marked all the nodes visited
	}
	visited[a] = 1;
	
	while(visited[b]!=1){
		b = parent[b];
	}

	return b;
}

int main(){

	lld test_cases;
	cin >> test_cases;
	lld case_number = 1;
	while(test_cases){

		lld nodes;
		cin >> nodes;
		lld *parent = new lld[1001];
		for(int i=1;i<=nodes;i++){
			parent[i] = i;
		}
		//setting the default value of the parent
		//only for the root value will be the same as node number
		lld i = 1;
		while(i<=nodes){
			//need to take the number of child nodes
			lld child_nodes;
			cin >> child_nodes;
			while(child_nodes){
				lld child;
				cin >> child;
				parent[child] = i;
				child_nodes--;
			}
			i++;
		}

		//till now value of the parent is set
		//need to find the LCA of the two nodes
		lld queries;
		cin >> queries;
		cout << "Case " << case_number << ":" << endl;
		while(queries){

			lld a, b;
			cin >> a >> b;
			lld solution = get_lca(parent, a, b);
			cout << solution << endl;
			queries--;
		}
		case_number++;
		test_cases--;
	}

	return 0;
}