#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<queue>

#define MAX 1000

using namespace std;

int adj[MAX][MAX];
int grau[MAX];
int visited[MAX];
int d[MAX];

void bfs(int inicio){
int s, t;
queue<int> Q;

		memset(visited, 0, sizeof(visited));
	    d[inicio] = 0;
	    visited[inicio] = 1;
	    Q.push(inicio);
	    
	    while(!Q.empty()){
	         s = Q.front();
	         Q.pop();
	         for(int i=0; i<grau[s]; i++){
	             t = adj[s][i];
	             if(visited[t] == 0){
	                visited[t] = 1;
	                d[t] = d[s] + 1;
	                Q.push(t);
	             }
	         }
	         
	    }
}


main(){
int nc, nodes, a, b, x, y, count;
int output = 1;
map<int, int> nodeConv;



			while(true){
			      scanf("%d",&nc);
			      nodes = 1;
			      nodeConv.clear();
			      memset(grau, 0, sizeof(grau));
			      
			      if(nc == 0)
			         break;
			      for(int i=0; i<nc; i++){
			         scanf("%d %d",&a,&b);
			         if(nodeConv[a] > 0){
			            x = nodeConv[a];
			         } else {
			            x = nodes;
			            nodeConv[a] = nodes;
			            nodes++;
			         }
			         
			         if(nodeConv[b] > 0){
			            y = nodeConv[b];
			         } else {
			            y = nodes;
			            nodeConv[b] = nodes;
			            nodes++;
			         }
			         adj[x][grau[x]++] = y;
			         adj[y][grau[y]++] = x;   
			      }
			      
			      
			      while(true){
			           scanf("%d %d",&a,&b);
			           if(a == 0 && b == 0)
			              break;
			           
			           x = nodeConv[a];
			           
			           bfs(x);
			           
			           count = 0;
			           for(int i=1; i<nodes; i++)
			               if((visited[i] == 1 && d[i] > b) || visited[i] == 0)
			                  count++;
			           printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", output, count, a, b);
			           output++;
			      }
			      			
			}

}


