/* Dungeon Master - 31/01/2008 */
/* Category: graph bfs 3d */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack>  

#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define mp(a,b) make_pair((a),(b))
#define all(c) (c).begin(),(c).end()
#define ff(i,v,n) for(int i=v; i<n; i++)
#define f(i,n) ff(i,0,n)
#define pb push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define debug(x)
#define MAXS 31
#define INF ((1)<<(30))

using namespace std;

typedef struct{
int l, r, c;
}TPos;


int adj[MAXS][MAXS][MAXS];
int d[MAXS][MAXS][MAXS]; 
int L, R, C;
TPos start, end;

void bfs(){ 
bool visited[MAXS][MAXS][MAXS];
queue<TPos> Q; 
TPos s, tmp;

	f(i, L)
	  f(j, R)
	    f(k, C)
	      visited[i][j][k] = false;
	      
	d[end.l][end.r][end.c] = INF;      
	d[start.l][start.r][start.c] = 0 ;
	visited[start.l][start.r][start.c] = true;

	Q.push(start); 
	while(!Q.empty()){ 
	      s = Q.front();
	      Q.pop(); 
	      if(s.c+1 < C && adj[s.l][s.r][s.c+1] == 1 && !visited[s.l][s.r][s.c+1]){
	          visited[s.l][s.r][s.c+1] = true;
	          d[s.l][s.r][s.c+1] = d[s.l][s.r][s.c] + 1;
	          tmp = s; tmp.c = s.c+1;
	          Q.push(tmp);
	      }
	      if(s.c-1 >= 0 && adj[s.l][s.r][s.c-1] == 1 && !visited[s.l][s.r][s.c-1]){
	          visited[s.l][s.r][s.c-1] = true;
	          d[s.l][s.r][s.c-1] = d[s.l][s.r][s.c] + 1;
	          tmp = s; tmp.c = s.c-1;
	          Q.push(tmp);	      
	      }
	      if(s.r+1 < R && adj[s.l][s.r+1][s.c] == 1 && !visited[s.l][s.r+1][s.c]){
	          visited[s.l][s.r+1][s.c] = true;
	          d[s.l][s.r+1][s.c] = d[s.l][s.r][s.c] + 1;
	          tmp = s; tmp.r = s.r+1;
	          Q.push(tmp);
	      }	   
	      if(s.r-1 >= 0 && adj[s.l][s.r-1][s.c] == 1 && !visited[s.l][s.r-1][s.c]){
	          visited[s.l][s.r-1][s.c] = true;
	          d[s.l][s.r-1][s.c] = d[s.l][s.r][s.c] + 1;
	          tmp = s; tmp.r = s.r-1;
	          Q.push(tmp);
	      }
	      if(s.l+1 < L && adj[s.l+1][s.r][s.c] == 1 && !visited[s.l+1][s.r][s.c]){
	          visited[s.l+1][s.r][s.c] = true;
	          d[s.l+1][s.r][s.c] = d[s.l][s.r][s.c] + 1;
	          tmp = s; tmp.l = s.l+1;
	          Q.push(tmp);
	      }
	      if(s.l-1 >= 0 && adj[s.l-1][s.r][s.c] == 1 && !visited[s.l-1][s.r][s.c]){
	          visited[s.l-1][s.r][s.c] = true;
	          d[s.l-1][s.r][s.c] = d[s.l][s.r][s.c] + 1;
	          tmp = s; tmp.l = s.l-1;
	          Q.push(tmp);
	      }	      		         		         
	} 
}



main(){
char str[MAXS];

	while(true){
		scanf("%d %d %d",&L, &R, &C);
		
		if(!L || !R || !C)
		  return 0;
		  
		f(i, L)
		  f(j, R){
		    scanf("%s",str);
		    f(k, C){
			  if(str[k] == '.')
			     adj[i][j][k] = 1;
			  else if(str[k] == '#')
			          adj[i][j][k] = 0;
			  else if(str[k] == 'S'){
			          adj[i][j][k] = 1;
			          start.l = i;
			          start.r = j;
			          start.c = k;
			  	   }
			  else if(str[k] == 'E'){
			          adj[i][j][k] = 1;
			          end.l = i;
			          end.r = j;
			          end.c = k;
			  	   }
		    }
		 }
		bfs();
		if(d[end.l][end.r][end.c] == INF)
		   printf("Trapped!\n");
		else
		   printf("Escaped in %d minute(s).\n",d[end.l][end.r][end.c]);	
	}

}
