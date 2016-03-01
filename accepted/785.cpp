#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define DEBUG(x)
#define MAX 100

using namespace std;

char grid[MAX][MAX];
char contour;
int rows=0, sz[MAX];
bool visited[MAX][MAX];


void floodFill(int x, int y, char mark){

	if(x < 0 || x >= rows || y < 0 || y >= sz[x])
	  return ;
	if(visited[x][y])
	   return;
	
	if(grid[x][y] == ' ' || grid[x][y] == mark){
	   visited[x][y] = true;
	   grid[x][y] = mark;
	   floodFill(x + 1, y,     mark);
	   floodFill(x - 1, y,     mark);
	   floodFill(x,     y + 1, mark);
	   floodFill(x,     y - 1, mark); 
	}
	

}

int main(){
char line[MAX];
bool isGrid;
int len;
int freq[MAX], tmp;

	while(cin.getline(line, MAX)){
	
	     isGrid = false;
	     len = strlen(line);
	     for(int i=0; i<len; i++)
	        if(line[i] != '_'){
	           isGrid = true;
	           break;
	        }
	     if(isGrid){
	        sz[rows] = len;
	        strcpy(grid[rows], line);
	        rows++;     
 	     } else if(rows > 0){
 	              
 	               memset(freq, 0, sizeof(freq));
 	               for(int i=0; i<rows; i++){
 	                   for(int j=0; j<sz[i]; j++){
 	                       if((int)grid[i][j] >= 33)
 	                          freq[((int)grid[i][j]) - 33]++;
 	                   }
 	               }
 	               
 	               tmp = 0;
 	               for(int i=0; i<MAX; i++)
 	                   if(freq[i] > tmp){
 	                      tmp = freq[i];
 	                      contour = (char)(i + 33);
 	                   }
 	               memset(visited, 0, sizeof(visited));
 	               for(int i=0; i<rows; i++)
 	                  for(int j=0; j<sz[i]; j++){
 	                      if(grid[i][j] != ' ' && grid[i][j] != contour){
 	                         floodFill(i, j, grid[i][j]);
 	                      }
 	                  }
 	               for(int i=0; i<rows; i++) 
 	                   printf("%s\n", grid[i]);
 	               rows = 0;
 	               printf("%s\n", line);
 	     } else printf("%s\n", line);
	    
	}
	return 0;
}

