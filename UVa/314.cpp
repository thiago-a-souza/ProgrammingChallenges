#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>

#define MAX 100
#define INF 2000000

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3


using namespace std;

int dist[MAX][MAX][4];
int maze[MAX][MAX];
int rows, cols;
int bx, by, ex, ey;
int direction;

int dx[4] = {-1, 0, 1,  0};
int dy[4] = { 0, 1, 0, -1};

bool isValidMove(int r, int c){
	if(r <= 0 || c <= 0 || r + 1 > rows || c + 1 > cols)
	   return false;
	if(maze[r][c] == 0 && maze[r+1][c] == 0 && maze[r][c+1] == 0 && maze[r+1][c+1] == 0)
	   return true;
	return false;
}

int bfs(){
int visited[MAX][MAX][4];
queue< pair< pair<int, int>, int>  > Q;
int r, c, dir;
int x2, y2;

	memset(visited, 0, sizeof(visited));
	for(int i=0; i<=rows; i++)
	   for(int j=0; j<=cols; j++)
	      for(int k=0; k<4; k++)
	          dist[i][j][k] = INF;
	
	visited[bx][by][direction] = 1;	       
	dist[bx][by][direction] = 0;
	Q.push(make_pair(make_pair(bx, by), direction));
	
	while(!Q.empty()){
          r = Q.front().first.first;
          c = Q.front().first.second;
          dir = Q.front().second; 	 
          Q.pop();
          
          if(r == ex && c == ey)
             return dist[r][c][dir];

          if(!visited[r][c][(dir+1)%4]){
              visited[r][c][(dir+1)%4] = 1;
              dist[r][c][(dir+1)%4] = dist[r][c][dir] + 1;
              Q.push(make_pair(make_pair(r, c),(dir+1)%4));
          }

          if(!visited[r][c][(dir+3)%4]){
              visited[r][c][(dir+3)%4] = 1;
              dist[r][c][(dir+3)%4] = dist[r][c][dir] + 1;
              Q.push(make_pair(make_pair(r, c),(dir+3)%4));
          }

          if(!visited[r][c][(dir+2)%4]){
              visited[r][c][(dir+2)%4] = 1;
              dist[r][c][(dir+2)%4] = dist[r][c][dir] + 2;
              Q.push(make_pair(make_pair(r, c),(dir+2)%4));
          }
          
          for(int len=1; len<=3; len++){
                 x2 = r + dx[dir]*len;
                 y2 = c + dy[dir]*len;
                 if(!isValidMove(x2, y2))
                     break;
                 if(visited[x2][y2][dir])
                    continue;

                 visited[x2][y2][dir] = 1;
                 dist[x2][y2][dir] = dist[r][c][dir] + 1;
                 Q.push(make_pair(make_pair(x2, y2), dir));
          }
	}
	return -1;
}

int main(){
char str[20];

	while(true){
		scanf("%d %d",&rows, &cols);
		if(rows == 0 && cols == 0)
		   break;
		for(int i=1; i<=rows; i++)
		   for(int j=1; j<=cols; j++)
		       scanf("%d",&maze[i][j]);
		scanf("%d %d %d %d %s\n", &bx, &by, &ex, &ey, str);   
				
		if(strcmp(str, "north") == 0)
		   direction = NORTH;
		else if(strcmp(str, "south") == 0)
		        direction = SOUTH;
		else if(strcmp(str, "west") == 0)
		        direction = WEST;
		else if(strcmp(str, "east") == 0)
		        direction = EAST;
		
		if(bx == ex && by == ey){
		   printf("0\n");
		   continue;		
		}
		        
		if(maze[bx][by] == 1 || maze[ex][ey] == 1){
		   printf("-1\n");
		   continue;
		}
		printf("%d\n", bfs());
	}
	return 0;
}

