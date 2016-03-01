#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 110
#define INF 999999


int adj[MAX][MAX];

using namespace std;

main(){
int u, v;
int nodes[MAX];
int size, dist;
int line = 1;
	while(true){
	      scanf("%d %d",&u,&v);
	      if(u == 0 && v == 0)
	         break;
	      for(int i=0; i<MAX; i++){
	         for(int j=0; j<MAX; j++)
	            adj[i][j] = INF;
	         adj[i][i] = 0;
	      }
	      memset(nodes, 0, sizeof(nodes));
	      adj[u][v] = 1;
	      nodes[u] = 1; nodes[v] = 1;
	      while(true){
	           scanf("%d %d",&u,&v);
	           if(u == 0 && v == 0)
	              break;
	           adj[u][v] = 1;
	           nodes[u] = 1; nodes[v] = 1;
	      }

	      for(int k=0; k<MAX; k++)
	         for(int i=0; i<MAX; i++)
	            for(int j=0; j<MAX; j++)
	                if(adj[i][k] + adj[k][j] < adj[i][j]){
	                  adj[i][j] = adj[i][k] + adj[k][j];
	                }	                
	      size = 0; dist = 0;
	      for(int i=0; i<MAX; i++){
	         if(nodes[i] == 0)
	            continue;  
	         for(int j=0; j<MAX; j++){
	            if(adj[i][j] > 0 && adj[i][j] != INF){
	               size++;
	               dist += adj[i][j];
	            }
	         }
	             
	      }
	      printf("Case %d: average length between pages = %.3lf clicks\n", line,((double)dist/size) );
	      line++;
	}
}
