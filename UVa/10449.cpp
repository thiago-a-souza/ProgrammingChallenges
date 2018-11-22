#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 500
#define INF 1000000

using namespace std;

typedef struct {
int v, w;
} TAdj;

TAdj adj[MAX][MAX];
int grau[MAX], d[MAX];

void bellmanFord(int inicial, int n){

	for(int i=0; i<n; i++)
	    d[i] = INF;
	d[inicial] = 0;
	for(int i=0; i<n; i++)
	   for(int j=0; j<n; j++)
	      for(int k=0; k<grau[j]; k++)
	          if(d[j] + adj[j][k].w < d[adj[j][k].v] && d[j] != INF)
	             d[adj[j][k].v] = d[j] + adj[j][k].w;
	          
	for(int i=0; i<n; i++)
	   for(int j=0; j<grau[i]; j++)
	       if(d[adj[i][j].v] > d[i] + adj[i][j].w && d[i] != INF)
	          d[adj[i][j].v] = -INF;
	       
}

int main(){
int busyness[MAX];
int n, u, v;
int edges;
int queries;
int line = 1;

	while(scanf("%d", &n) == 1){
	     memset(grau, 0, sizeof(grau));
	     for(int i=0; i<n; i++)
	         scanf("%d", &busyness[i]);
	     scanf("%d",&edges);
	     
	     for(int i=0; i<edges; i++){
	         scanf("%d %d", &u, &v);
	         u--; v--;
	         adj[u][grau[u]].v = v;
	         adj[u][grau[u]].w = (busyness[v] - busyness[u])*(busyness[v] - busyness[u])*(busyness[v] - busyness[u]);
	         grau[u]++;
	     }
	     
	     scanf("%d", &queries);
	     printf("Set #%d\n", line++);
	     bellmanFord(0, n);
	     for(int i=0; i<queries; i++){
	           scanf("%d", &u);
	           u--;
	           if(u < 0 || u >= n || d[u] == INF ||  d[u] < 3)
	              printf("?\n");
	           else
	              printf("%d\n", d[u]);
	     }
	     
	}
	return 0;
}

