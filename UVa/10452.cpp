#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

using namespace std;

#define MAX 20
#define LEFT 1
#define RIGHT 2
#define FORTH 3


char str[] = {'I','E','H','O','V','A', '#', '\0'};
char map[MAX][MAX];
int rows, cols;

void searchPath(int row, int col, int index, int visited[MAX][MAX], int parent[]){

	visited[row][col] = 1;
	if(map[row][col] == '#'){
	   for(int i=0; i<7; i++){
	       if(i > 0)
	          printf(" ");
	       switch(parent[i]){
	            case LEFT: printf("left"); break;
	            case RIGHT: printf("right"); break;
	            case FORTH: printf("forth"); break;
	       }
	   }
	   printf("\n");
	   return;
	}
    
	if(col + 1 < cols && visited[row][col+1] == 0 && map[row][col+1] == str[index]){
	   parent[index] = RIGHT;
	   searchPath(row, col+1, index+1, visited, parent);
	}
	
    if(col - 1 >= 0 && visited[row][col-1] == 0 && map[row][col-1] == str[index]){
       parent[index] = LEFT;
	   searchPath(row, col-1, index+1, visited, parent);
	}

	if(row + 1 < rows && visited[row+1][col] == 0 && map[row+1][col] == str[index]){
	   parent[index] = FORTH;
	   searchPath(row+1, col, index+1, visited, parent);
	}

	if(row - 1 >= 0 && visited[row-1][col] == 0 && map[row-1][col] == str[index]){
	   parent[index] = FORTH;
	   searchPath(row-1, col, index+1, visited, parent);
	}

    
	visited[row][col] = 0;	
}

int main(){
int tests;
int visited[MAX][MAX];
int parent[MAX];

	scanf("%d", &tests);
	while(tests--){
		scanf("%d %d",&rows, &cols);
		for(int i=0; i<rows; i++)
		    scanf("%s", map[i]);
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		for(int i=0; i<rows; i++)
		    for(int j=0; j<cols; j++)
		        if(map[i][j] == '@'){
		           searchPath(i, j, 0, visited, parent);
		           break;
		        }
	}

}

