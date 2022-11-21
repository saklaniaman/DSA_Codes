#include<stdio.h>
#include<stdlib.h>

//made global so that every function can access it
int visited[7]= {0,0,0,0,0,0,0};
	int a[7][7]= {
		{0,1,1,1,0,0,0},
		{1,0,1,0,0,0,0},
		{1,1,0,1,1,0,0},
		{1,0,1,0,1,0,0},
		{0,0,1,1,1,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	};
	
void DFS(int i){
	printf("%d ",i);
	visited[i]=1;
	for(int j=0;j<7;j++){
		
		if(a[i][j]==1 && visited[j]==0){
			DFS(j);
		}
	}
}

int main() {
	
	//DFS implementations
	DFS(2 );


	return 0;
}
