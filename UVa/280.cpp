#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 101

using namespace std;

int adj[MAX][MAX], grau[MAX], visited[MAX];
int N, nodes;

void dfs(int s){
int t;

	for(int i=0; i<grau[s]; i++){
	   t = adj[s][i];
	   if(!visited[t]){
	      visited[t] = 1;
	      nodes--;
	      dfs(t);
	   }
	}
}

main(){
int u, v;
int starts;
bool first;
	while(true){
		scanf("%d",&N);
		if(N == 0)
		  break;
		memset(grau, 0, sizeof(grau));
		while(true){
		      scanf("%d", &u);
		      if(u == 0)
		         break;
		      while(true){
		           scanf("%d",&v);
		           if(v == 0)
		              break;
		           adj[u][grau[u]++] = v;
		      }
		}
		scanf("%d",&starts);
		for(int i=0; i<starts; i++){
		   scanf("%d",&u);
		   memset(visited, 0, sizeof(visited));
		   nodes = N;
		   dfs(u);
		   printf("%d",nodes);
		   first = true;
		   for(int i=1; i<=N; i++)
		      if(visited[i] == 0)
		         printf(" %d",i);
		      
		   
		   printf("\n");
		   
		}
		
	}
}

