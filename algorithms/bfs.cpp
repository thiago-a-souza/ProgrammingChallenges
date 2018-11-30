/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Visits all reachable vertexes from an initial vertex using BFS.          */
/* For unweighted graphs it also displays the mininum distance from the starting vertex  */
/* to all vertexes.                                                                      */
/*****************************************************************************************/

#include <iostream>
#include <queue>

#define MAX_V 100 // max number of vertexes
#define MAX_E 100 // max number of edges

using namespace std;

int adj[MAX_V][MAX_E]; // graph
int degree[MAX_V];     // vertex degree
int p[MAX_V];          // parent
int d[MAX_V];          // minimun distance for unweighted graphs
int visited[MAX_V];    // vertexes visited

void bfs(int start){ 
int s, t; 
queue<int> Q; 

	d[start] = 0;
	visited[start] = 1;
	
	Q.push(start); 
	while(!Q.empty()){ 
	      s = Q.front(); 
	      Q.pop(); 
	      for(int i=0; i<degree[s]; i++) {
			  t = adj[s][i];
			  if(!visited[t]){ 
				  visited[t] = 1; 
				  d[t] = d[s] + 1; 
				  p[t] = s;
				  Q.push(t); 
				  } 
		  }
	} 
}

void path(int u){
	if(p[u] == -1){
		printf("%d", u);
		return;
	}

	path(p[u]);
	printf("->%d", u);
}


int main(){
int n = 8; // number of vertexes
int m = 10; // number of edges
int input[10][2] = {{0,1},{0,4},{1,5},{2,3},{2,5},{2,6},{3,6},{3,7},{5,6},{6,7}};

	for(int i=0; i<MAX_V; i++){
		visited[i] = 0;
		degree[i] = 0;
		p[i] = -1;
	}
	
	for(int i=0; i<m; i++){
		int u = input[i][0];
		int v = input[i][1];
		// undirected graph: u->v and v->u
		adj[u][degree[u]++] = v;
		adj[v][degree[v]++] = u;
	}

	int start = 1; // initial vertex
	bfs(start);

	for(int i=0; i<n; i++){
		if(i == start)
			continue;
		printf("min cost from %d to %d: %d\n", start, i, d[i]);
		printf("path from %d to %d: ", start, i);
		path(i);
		printf("\n\n");
	}

	return 0;

}
