#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 500
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int N;
char board[MAX][MAX];
bool visited[MAX][MAX];

void floodFill(int x, int y, char search, char replace){

	if(x < 0 || x >= N || y < 0 || y >= N)
	   return;
	if(board[x][y] != search || visited[x][y])
	   return;
	visited[x][y] = true;
	board[x][y] = replace;
	
	floodFill(x-1, y-1, search, replace);
	floodFill(x-1, y,   search, replace);
	floodFill(x,   y-1, search, replace);
	floodFill(x,   y+1, search, replace);
	floodFill(x+1, y,   search, replace);
	floodFill(x+1, y+1, search, replace);

}

int main(){
bool isBlack;
int test = 1;

	while(true){
		scanf("%d", &N);
		if(N == 0)
		   break;
		   
		memset(board, '\0', sizeof(board));
		memset(visited, 0, sizeof(visited));
		
		for(int i=0; i<N; i++)
		    scanf("%s",board[i]);
		    
		for(int j=0; j<N; j++)
		    if(board[0][j] == 'b' && !visited[0][j]){
		       floodFill(0, j, 'b', 'B');
            }
        for(int i=0; i<N; i++)
            if(board[i][0] == 'w' && !visited[i][0]){
               floodFill(i, 0, 'w', 'W');
            }
	    isBlack = false;
	    for(int j=0; j<N; j++)
	        if(board[N-1][j] == 'B'){
	           isBlack = true;
	           break;
	        }
	    if(isBlack)
	       printf("%d B\n", test++);
	    else
	       printf("%d W\n", test++);
	
	}
	return 0;
}

