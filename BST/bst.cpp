
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <locale>
#include <unistd.h>
#include <cmath>

using namespace std;

typedef long long int lld;

struct node{

	lld data;
	struct node *left;
	struct node *right;

};

struct node *new_node(lld value){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node *insert_node(struct node *root, lld temp, lld *count){


	if(root==NULL){
		cout << *count << endl;
		return new_node(temp);
		
	}

	else if(root->data < temp){
		(*count)++;
		root->right = insert_node(root->right, temp, count);
	}
	else{
		(*count)++;
		root->left = insert_node(root->left, temp, count);
	}

	return root;

}

int main(){

	lld count = 0;
	lld numbers, i, temp;
	cin >> numbers;
	struct node *root = NULL;
	while(i<numbers){
		cin >> temp;
		root = insert_node(root, temp, &count);
		i++;
	}

	return 0;
}