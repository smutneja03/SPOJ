
#include <iostream>
#include <list>

using namespace std;

int rows, columns;
bool **visited;
char **matrix;
int traps;

void DFSUtil(int r, int c, bool **visited, char **matrix){

	if(r<0 || r>=rows || c<0 || c>=columns){
		return;
	}
	if(visited[r][c]==true){
		return;
		//done with the trap
	}
	visited[r][c] = true;//implies the point is visited
	//initilally checking for all the adjacent positions
	//whose movement can result into current position
	/*
	for(int i = 0;i<rows;i++){
		for(int j = 0;j<columns;j++){
			cout << visited[i][j] << " ";
		}
		cout << "\n" ;
	}
	cout << endl;
	*/
	if(c-1>=0 && matrix[r][c-1]=='E'){
		DFSUtil(r, c-1, visited, matrix);
	}
	if(c+1<columns && matrix[r][c+1]=='W'){
		DFSUtil(r, c+1, visited, matrix);
	}
	if(r-1>=0 && matrix[r-1][c]=='S'){
		DFSUtil(r-1, c, visited, matrix);
	}
	if(r+1<rows && matrix[r+1][c]=='N'){
		DFSUtil(r+1, c, visited, matrix);
	}
	//now checking for the current posiiton when all the adjacenet posiitons are done
	if(matrix[r][c]=='N'){
		DFSUtil(r-1, c, visited, matrix);
	}
	else if(matrix[r][c]=='S'){
		DFSUtil(r+1, c, visited, matrix);
	}
	else if(matrix[r][c]=='E'){
		DFSUtil(r, c+1, visited, matrix);
	}
	else if(matrix[r][c]=='W'){
		DFSUtil(r, c-1, visited, matrix);
	}
}

void DFS(bool **visited, char **matrix){

	traps = 1;
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			if(visited[i][j]==false){
				DFSUtil(i, j, visited, matrix);
				traps++;
			}
		}
	}
	
	cout << traps-1 << endl;
}

int main(){

	cin >> rows >> columns;
	matrix = new char *[rows];
	for(int i = 0;i<rows;i++){
		matrix[i] = new char[columns];
	}
	for(int i = 0;i<rows;i++){
		cin >> matrix[i];
	}

	visited = new bool *[rows];
	for(int i = 0;i<rows;i++){
		visited[i] = new bool[columns];
	}
	for(int i = 0;i<rows;i++){
		for(int j=0;j<columns;j++){
			visited[i][j] = false;
		}
	}
	//now nede to do dfs from the start till all are completed
	DFS(visited, matrix);
    return 0;


}