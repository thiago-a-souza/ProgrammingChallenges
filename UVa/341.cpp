#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAX 1000
#define INF 9999999
using namespace std;

typedef struct{
int v, w;
} TAdj;

TAdj adj[MAX][MAX];
int grau[MAX], d[MAX], p[MAX];
int N;

void showPath(int v){
	if(p[v] > 0)
	   showPath(p[v]);
	printf(" %d",v);
}

void dijkstra(int inicial){
priority_queue< pair<int, int> > heap;
int s, t, peso;

	for(int i=1; i<=N; i++)
	    d[i] = INF; 
	memset(p, -1, sizeof(p));

	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
	     s = heap.top().second;
	     heap.pop();
	     for(int i=0; i<grau[s]; i++){
	         t = adj[s][i].v;
	         peso = adj[s][i].w;
	         if(d[s] + peso < d[t]){
	            d[t] = d[s] + peso;
	            p[t] = s;
	            heap.push(make_pair(-d[t], t));
	         }
	     }
	     
	}
}

main(){
int sz;
int v, w;
int start, end;
int line = 1;
	while(true){
		scanf("%d",&N);
		if(N == 0)
		   break;
		memset(grau, 0, sizeof(grau));
		for(int u=1; u<=N; u++){
		   scanf("%d",&sz);
		   for(int i=0; i<sz; i++){
		        scanf("%d %d",&v,&w);
		        adj[u][grau[u]].v = v;
		        adj[u][grau[u]].w = w;
		        grau[u]++;
	       }
	    }
	    scanf("%d %d",&start,&end);
	    dijkstra(start);
	    printf("Case %d: Path =",line++);
	    showPath(end);
	    printf("; %d second delay\n",d[end]);
	}
}

