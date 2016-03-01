#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAXLINE 10000
#define MAX 100
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

char board[MAX][MAX];
bool visited[MAX][MAX];
int rows, cols;

int floodFill(int x, int y){

	if(x < 0 || x >= rows || y < 0 || y >= cols)
	   return 0;
	if(board[x][y] == 'W' && !visited[x][y]){
	   visited[x][y] = true;
	   return 1 + floodFill(x-1, y-1) + floodFill(x-1, y) + floodFill(x-1,y+1) +
	              floodFill(x,y-1) +                        floodFill(x,y+1) +
	              floodFill(x+1,y-1) +  floodFill(x+1,y) +  floodFill(x+1,y+1);
	}
	return 0;
}

int main(){
int tests, len, x, y, aux;
char str[MAXLINE];
bool first = true;

	scanf("%d\n\n", &tests);
	while(tests--){
	      memset(board, '\0', sizeof(board));
	      rows = cols = 0;
	      if(!first) 
	        cout << endl;
	      first = false;

	      while(true){
	           memset(str, '\0', sizeof(str));
	           
	           if(!cin.getline(str, MAXLINE) || (len = strlen(str)) == 0 )
	               break;
	               
	           if(str[0] == 'L' || str[0] == 'W'){
	              cols = len;
	              strcpy(board[rows++], str);  
	           } else {
	              x = atoi(&str[0]);
	              aux = 0;
	              while(aux < len && str[aux] >= '0' && str[aux] <= '9')
	                    aux++;
	              y = atoi(&str[aux]);
	              
	              memset(visited, 0, sizeof(visited));
	              printf("%d\n", floodFill(x-1,y-1));
	           }
	           
	      }		  
	     
	}
	
	return 0;
}

