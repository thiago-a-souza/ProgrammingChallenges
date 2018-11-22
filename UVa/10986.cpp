#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <queue>

#define MAXV 20000
#define MAXE 5000
#define INF 999999
using namespace std;

typedef struct {
int v, w;
} TAdj;

TAdj adj[MAXV][MAXE];
int grau[MAXV], d[MAXV];

void dijkstra(int inicial){
priority_queue< pair<int, int> > heap;
int s, t, peso;

	for(int i=0; i<MAXV; i++)
	    d[i] = INF; 

	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
	     s = heap.top().second;
	     heap.pop();
	     for(int i=0; i<grau[s]; i++){
	         t = adj[s][i].v;
	         peso = adj[s][i].w;
	         if(d[s] + peso < d[t]){
	            d[t] = d[s] + peso;
	            heap.push(make_pair(-d[t], t));
	         }
	     }
	     
	}
}


main(){
int tests;
int n, m, s, t;
int u, v, w;
int line = 1;
	scanf("%d",&tests);
	while(tests--){
	     scanf("%d %d %d %d",&n,&m,&s,&t);
	     memset(grau, 0, sizeof(grau));
	     
	     for(int i=0; i<m; i++){
	        scanf("%d %d %d",&u,&v,&w);
	        adj[u][grau[u]].v = v;
	        adj[u][grau[u]].w = w;
	        grau[u]++;
	        adj[v][grau[v]].v = u;
	        adj[v][grau[v]].w = w;
	        grau[v]++;
	     }
	     dijkstra(s);
	     if(d[t] == INF)
	        printf("Case #%d: unreachable\n",line);
	     else
	        printf("Case #%d: %d\n",line,d[t]);
	     line++;
	     
	}
}

