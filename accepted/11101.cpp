#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>

#define MAX 2000000
#define LIM 2010
#define INF 1000000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef struct {
int x, y;
} TPoint;

TPoint mallA[MAX], mallB[MAX];
TPoint minPoint, maxPoint;
int p1, p2;

int visited[LIM][LIM], d[LIM][LIM];

using namespace std;

void bfs(){
queue< pair<int, int> > Q;
int x, y;

	
	memset(visited, 0, sizeof(visited));
	for(int i=0; i<LIM; i++)
	   for(int j=0; j<LIM; j++)
	       d[i][j] = INF;
	       	
	for(int i=0; i<p1; i++){
        x = mallA[i].x;
        y = mallA[i].y;
        
        visited[x][y] = 1;
        d[x][y] = 0;
        Q.push(make_pair(x, y)); 
	}
	
	while(!Q.empty()){
	      x = Q.front().first;
	      y = Q.front().second;
	      Q.pop();
	      
	      if(x - 1 >= 0 && x - 1 >= minPoint.x && visited[x-1][y] == 0){
	         visited[x-1][y] = 1;
	         d[x-1][y] = MIN(d[x-1][y], d[x][y] + 1);
	         Q.push(make_pair(x-1, y));
	      }
	      if(x + 1 < LIM && x + 1 <= maxPoint.x && visited[x+1][y] == 0){
	         visited[x+1][y] = 1;
	         d[x+1][y] = MIN(d[x+1][y], d[x][y] + 1);
	         Q.push(make_pair(x+1, y));
	      }	      	

	      if(y - 1 >= 0 && y - 1 >= minPoint.y && visited[x][y-1] == 0){
	         visited[x][y-1] = 1;
	         d[x][y-1] = MIN(d[x][y-1], d[x][y] + 1);
	         Q.push(make_pair(x, y-1));
	      }
	      if(y + 1 < LIM && y + 1 <= maxPoint.y && visited[x][y+1] == 0){
	         visited[x][y+1] = 1;
	         d[x][y+1] = MIN(d[x][y+1], d[x][y] + 1);
	         Q.push(make_pair(x, y+1));
	      }	      	
	}
	
}




int main(){
int minDist;
	while(true){
	      scanf("%d",&p1);
	      if(p1 == 0)
	         break;
	      
	      minPoint.x = LIM;
	      minPoint.y = LIM;
	      maxPoint.x = 0;
	      maxPoint.y = 0;
	      
	      for(int i=0; i<p1; i++){
	         scanf("%d", &mallA[i].x);
	         scanf("%d", &mallA[i].y);
	         
	         if(mallA[i].x < minPoint.x)
	            minPoint.x = mallA[i].x;
	         if(mallA[i].y < minPoint.y)
	            minPoint.y = mallA[i].y;
	            
	         if(mallA[i].x > maxPoint.x)
	            maxPoint.x = mallA[i].x;
	         if(mallA[i].y > maxPoint.y)
	            maxPoint.y = mallA[i].y;
	      }
	      
	      scanf("%d",&p2);
	      for(int i=0; i<p2; i++){
	         scanf("%d", &mallB[i].x);
	         scanf("%d", &mallB[i].y);
	         if(mallB[i].x < minPoint.x)
	            minPoint.x = mallB[i].x;
	         if(mallB[i].y < minPoint.y)
	            minPoint.y = mallB[i].y;
	            
	         if(mallB[i].x > maxPoint.x)
	            maxPoint.x = mallB[i].x;
	         if(mallB[i].y > maxPoint.y)
	            maxPoint.y = mallB[i].y;
	      }
	      bfs();
	      minDist = INF;
	      for(int i=0; i<p2; i++)
	          if(d[mallB[i].x][mallB[i].y] < minDist)
	             minDist = d[mallB[i].x][mallB[i].y];
	      printf("%d\n", minDist);	      
	      
	}
	return 0;
}

