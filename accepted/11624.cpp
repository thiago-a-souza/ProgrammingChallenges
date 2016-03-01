#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>
#include<queue>

#define INF 1000000
#define MAX 1001
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

char maze[MAX][MAX];
int visited[MAX][MAX];
int dJoe[MAX][MAX], dFire[MAX][MAX];
bool valid[MAX][MAX];
int R, C;

int bfs(){
queue< pair<int, int> > Q;
pair<int, int> p;
int x, y;
int minDist;

	memset(visited, 0, sizeof(visited));
	for(int i=0; i<R; i++)
	   for(int j=0; j<C; j++){
	       dFire[i][j] = INF;
	       if(maze[i][j] == 'F'){
	          dFire[i][j] = 0;
	          Q.push(make_pair(i,j));
	          visited[i][j] = 1;
	       }
	   }
	

	while(!Q.empty()){
	      x = Q.front().first;
	      y = Q.front().second;
	      Q.pop();
	      
	      if(x-1 >= 0 && visited[x-1][y] == 0 && (maze[x-1][y] == '.' || maze[x-1][y] == 'J')){
	         visited[x-1][y] = 1;
	         dFire[x-1][y] = MIN(dFire[x-1][y], dFire[x][y] + 1);
	         Q.push(make_pair(x-1, y));
	      }
	         
	      if(x+1 <  R && visited[x+1][y] == 0 && (maze[x+1][y] == '.' || maze[x+1][y] == 'J')){
	         visited[x+1][y] = 1;
	         dFire[x+1][y] = MIN(dFire[x+1][y], dFire[x][y] + 1);
	         Q.push(make_pair(x+1, y));
	      }
	         
	      if(y-1 >= 0 && visited[x][y-1] == 0 && (maze[x][y-1] == '.' || maze[x][y-1] == 'J')){
	         visited[x][y-1] = 1;
	         dFire[x][y-1] = MIN(dFire[x][y-1], dFire[x][y] + 1);
	         Q.push(make_pair(x, y-1));
	      }
	         
	         
	      if(y+1 <  C && visited[x][y+1] == 0 && (maze[x][y+1] == '.' || maze[x][y+1] == 'J')){
	         visited[x][y+1] = 1;
	         dFire[x][y+1] = MIN(dFire[x][y+1], dFire[x][y] + 1);
	         Q.push(make_pair(x, y+1));
	      }
	}
	
	memset(visited, 0, sizeof(visited));
	memset(valid, 0, sizeof(valid));
	for(int i=0; i<R; i++)
	   for(int j=0; j<C; j++){
	      dJoe[i][j] = INF;
	      if(maze[i][j] == 'J'){
	          dJoe[i][j] = 0;
	          Q.push(make_pair(i,j));
	          visited[i][j] = 1;
	          valid[i][j] = true;
	      }
	   }
	   
	while(!Q.empty()){
	      x = Q.front().first;
	      y = Q.front().second;
	      Q.pop();
	      
	      if(x-1 >= 0 && visited[x-1][y] == 0 && (maze[x-1][y] == '.' || maze[x-1][y] == 'J')){
	         visited[x-1][y] = 1;
	         dJoe[x-1][y] = MIN(dJoe[x-1][y], dJoe[x][y] + 1);
	         if(dJoe[x-1][y] < dFire[x-1][y]){
	            Q.push(make_pair(x-1, y));
	            valid[x-1][y] = true;
	         }
	      }
	         
	      if(x+1 <  R && visited[x+1][y] == 0 && (maze[x+1][y] == '.' || maze[x+1][y] == 'J')){
	         visited[x+1][y] = 1;
	         dJoe[x+1][y] = MIN(dJoe[x+1][y], dJoe[x][y] + 1);
	         if(dJoe[x+1][y] < dFire[x+1][y]){
	            Q.push(make_pair(x+1, y));
	            valid[x+1][y] = true;
	         }
	      }
	         
	      if(y-1 >= 0 && visited[x][y-1] == 0 && (maze[x][y-1] == '.' || maze[x][y-1] == 'J')){
	         visited[x][y-1] = 1;
	         dJoe[x][y-1] = MIN(dJoe[x][y-1], dJoe[x][y] + 1);
   	         if(dJoe[x][y-1] < dFire[x][y-1]){
	            Q.push(make_pair(x, y-1));
	            valid[x][y-1] = true;
	         }
	      }
	         
	         
	      if(y+1 <  C && visited[x][y+1] == 0 && (maze[x][y+1] == '.' || maze[x][y+1] == 'J')){
	         visited[x][y+1] = 1;
	         dJoe[x][y+1] = MIN(dJoe[x][y+1], dJoe[x][y] + 1);
	         if(dJoe[x][y+1] < dFire[x][y+1]){
	            Q.push(make_pair(x, y+1));
	            valid[x][y+1] = true;
	         }
	      }
	}	   
	
	minDist = INF;
	for(int i=0; i<R; i++){
	    if(dJoe[i][0]   < minDist && valid[i][0])
	       minDist = dJoe[i][0];
	    if(dJoe[i][C-1] < minDist && valid[i][C-1])   
	       minDist = dJoe[i][C-1];
	}
	
	for(int j=0; j<C; j++){
	   if(dJoe[0][j]   < minDist && valid[0][j])
	      minDist = dJoe[0][j];
	   if(dJoe[R-1][j] < minDist && valid[R-1][j])
	      minDist = dJoe[R-1][j];
	}	
	return minDist;
}

int main(){
int tests;
int ans;

	scanf("%d",&tests);
	while(tests--){
	     scanf("%d %d",&R, &C);
	     memset(maze, '\0', sizeof(maze));
	     
	     for(int i=0; i<R; i++)
	        scanf("%s", maze[i]);
	        
	     ans = bfs();
	     if(ans == INF)
	        printf("IMPOSSIBLE\n");
	     else
	        printf("%d\n", ans+1);
	   
	}

	return 0;
}

