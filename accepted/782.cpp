#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 500

using namespace std;

char maze[MAX][MAX];
int totalRows, len;
bool canPaint[MAX][MAX], visited[MAX][MAX];

int dx[4] = {-1, 1,  0, 0};
int dy[4] = { 0, 0, -1, 1};

void preFloodFill(int r, int c){

	if(r < 0 || c < 0 || r >= totalRows || c >= len || visited[r][c])
	   return;

	if(maze[r][c] == 'X' || maze[r][c] == '_' || maze[r][c] == '*')
	   return;

	visited[r][c] = true;
	canPaint[r][c] = true;
	
	for(int i = 0; i < 4; i++)
	    preFloodFill(r + dx[i], c + dy[i]);
}

bool hasNeighbour(int r, int c){

	for(int i=0; i<4; i++){
	   if(r + dx[i] < 0 || r + dx[i] >= totalRows || c + dy[i] < 0 ||  c + dy[i] >= len)
	      continue;
	   if(maze[r + dx[i]][c + dy[i]] == 'X')
	      return true;
	}
	return false;
}

void floodFill(int r, int c){
	if(r < 0 || c < 0 || r >= totalRows || c >= len || visited[r][c])
	   return;
		
	if(hasNeighbour(r, c) && canPaint[r][c])
	   maze[r][c] = '#';
	   
    visited[r][c] = true;
	for(int i=0; i<4; i++)
	    floodFill(r + dx[i], c + dy[i]);

}

void showSolution(){
int sz, last;
bool flag;


	last = -1;
    for(int j=0; j<len; j++)
       if(maze[0][j] == 'X' || maze[0][j] == '#'){
          last = j;
       }
    for(int j=0; j<last; j++)
        maze[0][j] = ' ';
    if(last >= 0)
       printf("%s\n", maze[0]);
          
    
    for(int i=1; i<totalRows; i++){
        last = -1;
        for(int j=0; j<len; j++)
            if(maze[i][j] == 'X' || maze[i][j] == '#' || maze[i][j] == '_')
               last = j;
        for(int j=0; j<last; j++)
           if(maze[i][j] == '\0')
              maze[i][j] = ' ';
        maze[i][last+1] = '\0';
        printf("%s\n", maze[i]);
               
    }      

}

int main(){
int tests, aux;
bool end;
char tmp[MAX];

	scanf("%d", &tests);
 	cin.getline(tmp, MAX);

	while(tests--){
	      totalRows = 1;
	      memset(maze, '\0', sizeof(maze));
	      
	      while(true){
	           cin.getline(maze[totalRows], MAX);
	           
	           aux = strlen(maze[totalRows]);
	           if(aux + 1> len)
	              len = aux + 1;
	              
	           totalRows++;
	           end = false;
	           for(int i=0; i<aux; i++)
	              if(maze[totalRows-1][i] == '_'){
	                 end = true;
	                 break;
	              }
	            if(end)
	               break;
	      }     

          memset(canPaint, 0, sizeof(canPaint));
          memset(visited, 0, sizeof(visited));
	      end = true;   
	      for(int i=0; i<totalRows && end; i++)
	         for(int j=0; j<len && end; j++)
	             if(maze[i][j] == '*'){
	                maze[i][j] = ' ';
	                preFloodFill(i, j);
	                end = false;
	                break;
	             }  

		  memset(visited, 0, sizeof(visited));
		  for(int i=0; i<totalRows; i++)
		     for(int j=0; j<len; j++)
		         if(!visited[i][j]){
		            floodFill(i, j);
		         }
		  showSolution();

		  
	 
	}
	return 0;
}

