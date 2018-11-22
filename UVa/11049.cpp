#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>
#include<queue>


#define MAX 10
#define MAXLINES 3
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define EAST  1
#define WEST  2
#define NORTH 3
#define SOUTH 4

using namespace std;


int ax, ay, bx, by;
set< pair<int, int> > line[MAXLINES];

int visited[MAX][MAX], d[MAX][MAX], p[MAX][MAX];

bool hasWall(int x, int y, int direction){   
    
    if(direction == NORTH){
	   for(int i=0; i<MAXLINES; i++){
	      if(line[i].count(make_pair(x-1,y-1)) > 0 && line[i].count(make_pair(x,y-1)) > 0 )
	         return true;
       }
	   return false;
    }

    if(direction == SOUTH){
	   for(int i=0; i<MAXLINES; i++){
	      if(line[i].count(make_pair(x-1,y)) > 0 && line[i].count(make_pair(x,y)) > 0 )
	         return true;
       }
	   return false;
    }

    if(direction == WEST){
	   for(int i=0; i<MAXLINES; i++){
	      if(line[i].count(make_pair(x-1,y-1)) > 0 && line[i].count(make_pair(x-1,y)) > 0 )
	         return true;
       }
	   return false;
    }

    if(direction == EAST){
	   for(int i=0; i<MAXLINES; i++){
	      if(line[i].count(make_pair(x,y-1)) > 0 && line[i].count(make_pair(x,y)) > 0 )
	         return true;
       }
	   return false;
    }
    return false;
}

void showPath(int x, int y){
	if(p[y][x] == 0)
	   return;
	
	if(p[y][x] == NORTH){
	   showPath(x, y-1);
	   printf("S");
	} else if(p[y][x] == SOUTH){
              showPath(x, y+1);
              printf("N");
	} else if(p[y][x] == WEST){
              showPath(x-1, y);
              printf("E");	
	} else if(p[y][x] == EAST){
              showPath(x+1, y);	
              printf("W");
	}
}

void bfs(){
queue< pair<int, int> > Q;
int x, y;

	memset(visited, 0, sizeof(visited));
	memset(p, 0, sizeof(visited));
	Q.push(make_pair(ax, ay));
	visited[ay][ax] = 1;
	d[ay][ax] = 0;
	while(!Q.empty()){
	      x = Q.front().first;
	      y = Q.front().second;
	      Q.pop();

	      if(y - 1 > 0 && visited[y-1][x] == 0 && hasWall(x, y, NORTH) == false){
	         visited[y-1][x] = 1;
	         d[y-1][x] = d[y][x] + 1;
	         p[y-1][x] = SOUTH;
	         Q.push(make_pair(x, y-1));
	      }
	      
	      if(y + 1 <= 6 && visited[y+1][x] == 0 && hasWall(x, y, SOUTH) == false){
	         visited[y+1][x] = 1;
	         d[y+1][x] = d[y][x] + 1;
	         p[y+1][x] = NORTH;
	         Q.push(make_pair(x, y+1));
	      }
	      
	      if(x - 1 > 0 && visited[y][x-1] == 0 && hasWall(x, y, WEST) == false){
	         visited[y][x-1] = 1;
	         d[y][x-1] = d[y][x] + 1;
	         p[y][x-1] = EAST;
	         Q.push(make_pair(x-1, y));
	      }
	      
	      if(x + 1 <= 6 && visited[y][x+1] == 0 && hasWall(x, y, EAST) == false){
	         visited[y][x+1] = 1;
	         d[y][x+1] = d[y][x] + 1;
	         p[y][x+1] = WEST;
	         Q.push(make_pair(x+1, y));
	      }
	}	

}

int main(){
int x1, y1, x2, y2;

	while(true){
	     scanf("%d %d",&ax,&ay);
	     if(ax == 0 && ay == 0)
	        break;
	     scanf("%d %d",&bx,&by);
	     	     
	     for(int l=0; l<MAXLINES; l++){
	        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
	        line[l].clear();
	        if(x1 == x2){
	           for(int j=y1; j<=y2; j++){
	              line[l].insert(make_pair(x1, j));
	           }
	        } else if(y1 == y2){
	                 for(int i=x1; i<=x2; i++){
	                    line[l].insert(make_pair(i, y1));
	                 }
	        }
	     }
	     bfs();
	     showPath(bx,by);
	     printf("\n");
	}
	return 0;
}


