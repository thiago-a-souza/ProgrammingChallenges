#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <set>

#define MAXV 100002
#define MAXE 500

using namespace std;

int adj[MAXV][MAXE], grau[MAXV];
int invAdj[MAXV][MAXE], invGrau[MAXV];
int comp[MAXV][MAXE], compGrau[MAXV];
int visited[MAXV];
int indegree[MAXV];
int N, M;
int id;
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


void buildComponentsGraph(){
    memset(indegree, 0, sizeof(indegree));
	for(int i=1; i<=N; i++)
	   for(int j=0; j<grau[i]; j++)
	      if(visited[i] != visited[adj[i][j]] && edges.count(make_pair(visited[i],visited[adj[i][j]])) == 0)
	          indegree[visited[adj[i][j]]]++;
}

main(){
int tests;
int u, v;
int ans;


	scanf("%d",&tests);
	while(tests--){
	     scanf("%d %d",&N,&M);
	     memset(grau, 0, sizeof(grau));
	     memset(invGrau, 0, sizeof(invGrau));
	     memset(compGrau, 0,sizeof(compGrau));
	     edges.clear();
	     for(int i=0; i<M; i++){
	        scanf("%d %d",&u,&v);
	        adj[u][grau[u]++] = v;
	        invAdj[v][invGrau[v]++] = u;
	     }
	     
	     kosaraju(1,N+1);
	     buildComponentsGraph();
	     ans = 0;
	     for(int i=1; i<id; i++)
	        if(indegree[i] == 0)
	            ans++;
	     cout << ans << endl;
	}
	
}

