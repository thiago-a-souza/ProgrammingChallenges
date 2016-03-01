#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAX 15000

using namespace std;

int adj[MAX][MAX], grau[MAX], d[MAX];
int events;

int indegree[MAX];
queue<int> L;

void topological_sort(){
queue<int> z;
int v, w;

		memset(indegree, 0, sizeof(indegree));
		for(int i=0; i<events; i++)
		   if(grau[i])
		     for(int j=0; j<grau[i]; j++)
		        indegree[adj[i][j]]++;
		for(int i=0; i<events; i++)
		   if(!indegree[i])
		      z.push(i);
		while(!z.empty()){
		     v = z.front();
		     z.pop();
		     L.push(v);
		     for(int i=0; i<grau[v]; i++){
		         w = adj[v][i];
		         indegree[w]--;
		         if(!indegree[w])
		            z.push(w);
		     }
		}
}

void countDAGPaths(){
int u;

	topological_sort();
	memset(d, 0, sizeof(d));
	d[0] = 1;
	while(!L.empty()){
	   u = L.front(); L.pop();
	   for(int i=0; i<grau[u]; i++)
	       d[adj[u][i]] = d[adj[u][i]] + d[u];
	}
	   
}

main(){
int n, ans, v;
bool first = true;
	while(scanf("%d",&events) != EOF){
	     memset(grau, 0, sizeof(grau));
	     memset(d, -1, sizeof(d));
	     ans = 0;
	     
	     for(int i=0; i<events; i++){
	        scanf("%d",&n);
	        for(int j=0; j<n; j++){
	            scanf("%d",&v);
	            adj[i][grau[i]++] = v;
	        }
	     }
	     
	     countDAGPaths();
	     ans = 0;
	     for(int i=0; i<events; i++)
	        if(grau[i] == 0)
	           ans += d[i];
	     
	     if(first) 
	       first = false;
	     else 
	       printf("\n");

	     cout << ans << endl;
	   
	     
	     
	}
}

