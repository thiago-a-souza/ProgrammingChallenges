#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXV 300
#define MAXE 11000

using namespace std;

int adj[MAXV][MAXE], grau[MAXV], visited[MAXV];
int particao[MAXV];
int V, E;
int label;
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
int tests;
int s, t;
int a, b, ans;

	scanf("%d",&tests);
	while(tests--){
	     scanf("%d %d",&V,&E);
	     memset(grau, 0, sizeof(grau));
	     for(int i=0; i<E; i++){
	        scanf("%d %d",&s,&t);
	        adj[s][grau[s]++] = t;
	        adj[t][grau[t]++] = s;
	     }
	     bipartite();
	     if(!is_bipartite)
	        printf("-1\n");
	     else {
	        ans = 0;
	        for(int i=0; i<V; i++)
	           if(grau[i] == 0)
	              ans++;
	        for(int i=1; i<label; i++){
	           a = 0; b = 0;
	           for(int j=0; j<V; j++){
	               if(visited[j] == i){
	                  if(particao[j] == 0)
	                     a++;
	                  else 
	                     b++;
	               }
	           }
	           if(a < b)
	              ans += a;
	           else
	              ans += b;
	        }
	        printf("%d\n",ans);
	     }
	}

}

