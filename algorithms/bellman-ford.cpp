/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Calculates the mininum distance from an initial vertex to all vertexes   */
/* using Bellman-Ford algorithm                                                          */
/*****************************************************************************************/

#include <iostream>

#define MAX_V 100 // max number of vertexes
#define MAX_E 100 // max number of edges

const int INF = 0x3F3F3F3F;

using namespace std; 

typedef struct{
int v; // vertex
int w; // weight
} t_adj;

t_adj adj[MAX_V][MAX_E]; // graph
int n;                   // number of vertexes
int m;                   // number of edges
int degree[MAX_V];       // vertex degree
int d[MAX_V];            // min distance
int p[MAX_V];            // parent

bool bellmanFord(int start){

	for(int i=0; i<n; i++){
		p[i] = -1;
		d[i] = INF;
	}

	d[start] = 0;
	for(int i=0; i<n; i++)   // all vertexes
	   for(int j=0; j<n; j++)            /*    all    */
	      for(int k=0; k<degree[j]; k++) /*	  edges   */
	      	if(d[j] + adj[j][k].w < d[adj[j][k].v]){
	      	  d[adj[j][k].v] = d[j] + adj[j][k].w;
	      	  p[adj[j][k].v] = j;
	      	}

	// return false if a negative cycle is found (there's no solution)		  
	for(int i=0; i<n; i++)
	   for(int j=0; j<degree[j]; j++)
	      if(d[adj[i][j].v] > d[i] + adj[i][j].w)
	        return false;
	return true;
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
int s, t, w;	
int start = 0; // initial vertex

// three integers u, v, w representing the edge u->v with cost w
int input[MAX_V][3] = {{0, 1, 10}, {0, 2, 5}, {1, 2, 2},  {1, 3, 1}, {2, 1, 3},
                       {2, 3, 9}, {2, 4, 2}, {3, 4, 4}, {4, 3, 6}, {4, 0, 7}};


	for(int i=0; i<MAX_V; i++)
		degree[i] = 0;

	n = 5; m = 10;
	for(int i=0; i<m; i++){
		int u = input[i][0];
		int v = input[i][1];
		int w = input[i][2];
		adj[u][degree[u]].v = v;
		adj[u][degree[u]].w = w;
		degree[u]++;
	}

	bellmanFord(start);

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


