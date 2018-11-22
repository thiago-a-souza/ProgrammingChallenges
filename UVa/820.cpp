#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>


#define MAXV 200
#define MAXE 200
#define INF 2000000
#define MIN(a,b) ((a) < (b) ? (a) : (b))



#define residue(src, dst) ( c[ (src) ][ (dst) ] - flow( (src), (dst) ) )
#define flow(src, dst) ( f[ (src) ][ (dst) ] - f[ (dst) ][ (src) ])

using namespace std;

typedef struct {
int v, w;
} TAdj;

TAdj adj[MAXV][MAXE];
int grau[MAXV], p[MAXV];
int f[MAXV][MAXV]; // fluxo
int c[MAXV][MAXV]; // capacidade = peso das arestas


int maxFlow(int s, int t){
int F, minCapacity;
int u, v;

	F = 0;
	memset(f, 0, sizeof(f));
	memset(c, 0, sizeof(c));
	
	for(int i=0; i<MAXV; i++)
	   for(int j=0; j<grau[i]; j++)
	       c[i][adj[i][j].v] += adj[i][j].w;
	
	while(true){
          queue<int> Q;
	      memset(p, -1, sizeof(p));
	      Q.push(s);
	      p[s] = -2;
	      
	      // bfs
	      while(!Q.empty() && p[t] == -1){
	            u = Q.front();
	            Q.pop();
	            for(int i=0; i<grau[u]; i++){
	                v = adj[u][i].v;
	                if(p[v] == -1 && residue(u, v) > 0){
	                   p[v] = u;
	                   Q.push(v);
	                }    
	            }
	      }
	      
          // não encontrou caminho até t	      
	      if(p[t] == -1)
	         return F;
	      // encontra menor capacidade no caminho	         
	      minCapacity = INF;
	      for(v = t, u = p[v]; u >= 0; v = u, u = p[v]){
	          minCapacity = MIN(minCapacity, residue(u, v));
	      }
	      // incrementa capacidade no caminho   
	      for(v = t, u = p[v]; u >= 0; v = u, u = p[v])
	          f[u][v] += minCapacity;    
	      F += minCapacity;  
	}
	return F;
}


int main(){
int nodes, edges, s, t;
int u, v, w;
int line = 1;

	while(true){
	      scanf("%d",&nodes);
	      if(nodes == 0)
	         break;
	      scanf("%d %d %d", &s, &t, &edges);
	      memset(grau, 0, sizeof(grau));
	      
	      for(int i=0; i<edges; i++){
	          scanf("%d %d %d", &u, &v, &w);
	          adj[u][grau[u]].v = v;
	          adj[u][grau[u]].w = w;
	          grau[u]++;
	          
	          adj[v][grau[v]].v = u;
	          adj[v][grau[v]].w = w;
	          grau[v]++;
	      }
	      printf("Network %d\n", line++);
	      printf("The bandwidth is %d.\n\n", maxFlow(s, t));
	}
	return 0;
}

