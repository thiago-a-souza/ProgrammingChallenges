#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

#define MAXV 3000
#define MAXE 3000

using namespace std;

int adj[MAXV][MAXE], grau[MAXV];
int invAdj[MAXV][MAXE], invGrau[MAXV];
int visited[MAXV];
int id;
int N, M;
stack<int> S;

void dfsVisit(int v){

	visited[v] = 1;
	for(int i=0; i<grau[v]; i++)
	    if(!visited[adj[v][i]])
	       dfsVisit(adj[v][i]);
	S.push(v);
}

void dfsVisit2(int x){

	visited[x] = id;
	for(int i=0; i<invGrau[x]; i++)
	    if(!visited[invAdj[x][i]])
	       dfsVisit2(invAdj[x][i]);

}


void kosaraju(int start, int end){
int u;

	memset(visited, 0, sizeof(visited));
	for(int i=start; i<end; i++)
	    if(!visited[i]){
           dfsVisit(i);
        }  
	memset(visited, 0, sizeof(visited));
	id = 1;
	while(!S.empty()){
	      u = S.top(); S.pop();
	      if(!visited[u]){
	         dfsVisit2(u);
	         id++;
	      } 
	}	     
}


main(){
int u, v, dir;
int ans;
	while(true){
		scanf("%d %d",&N,&M);
		memset(grau, 0, sizeof(grau));
		memset(invGrau, 0, sizeof(invGrau));
		if(N == 0 && M == 0)
		   break;
		for(int i=0; i<M; i++){
			scanf("%d %d %d",&u,&v,&dir);
			if(dir == 1){
			   adj[u][grau[u]++] = v;
			   invAdj[v][invGrau[v]++]  = u;
			} else if(dir == 2){
			          adj[u][grau[u]++] = v;
			          adj[v][grau[v]++] = u;
			          invAdj[u][invGrau[u]++] = v;
			          invAdj[v][invGrau[v]++] = u;
			}
		}
		kosaraju(1,N+1);
		if(id <= 2)
		   printf("1\n");
		else 
		   printf("0\n");
		
		   
	}
}

