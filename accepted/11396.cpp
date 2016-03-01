#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 500


int adj[MAX][MAX], grau[MAX], visited[MAX];
int particao[MAX];
int V, E;
int label;

using namespace std;

bool is_bipartite;

void dfsVisit(int s, int p){
int t;

	visited[s] = label;
	particao[s] = p;
	for(int i=0; i<grau[s]; i++){
	   t = adj[s][i];
	   if(visited[t] == 0){
	      dfsVisit(t, !p);
	   } else if(particao[t] == p)
	             is_bipartite = false;
	}
}

void bipartite(){
    is_bipartite = true;
    label = 1;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<V; i++){
        if(!is_bipartite)
           break;
        if(grau[i] > 0 && visited[i] == 0){
           dfsVisit(i, 0);
           label++;
        }
    }
}

main(){
int s, t;

	while(true){
	     scanf("%d",&V);
	     if(!V)
	        break;
	     memset(grau, 0, sizeof(grau));
	     while(true){
	          scanf("%d %d",&s,&t);
	          if(s == 0 && t == 0)
	             break;
	          adj[s][grau[s]++] = t;
	          adj[t][grau[t]++] = s;
	     }
	     bipartite();
	     if(is_bipartite)
	        printf("YES\n");
	     else
	        printf("NO\n");
	}
}

