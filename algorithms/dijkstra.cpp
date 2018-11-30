/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Calculates the mininum distance from an initial vertex to all vertexes   */
/* using Dijkstra's algorithm                                                            */
/*****************************************************************************************/

#include <iostream>
#include <queue>

#define MAX_V 100 // max number of vertexes
#define MAX_E 100 // max number of edges

const int INF = 0x3F3F3F3F;

using namespace std; 

typedef struct{
int v; // vertex
int w; // weight
} t_adj;

t_adj adj[MAX_V][MAX_E]; // graph

int degree[MAX_V]; // vertex degree
int d[MAX_V];      // min distance
int p[MAX_V];      // parent

void dijkstra(int start){
priority_queue< pair<int,int> > heap; // weight, vertex
int s, t, weight;

	for(int i=0; i<MAX_V; i++){
		d[i] = INF;
		p[i] = -1;
	}

	heap.push(make_pair(d[start] = 0, start));
	while(!heap.empty()){
	     s = heap.top().second; 
		 heap.pop();
	     for(int i=0; i<degree[s]; i++){
             t = adj[s][i].v;
			 weight = adj[s][i].w;
			 if(d[s] + weight < d[t]){
				 d[t] = d[s] + weight;
				 p[t] = s;
				 heap.push(make_pair(-d[t], t));
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
int n = 5;  // number of vertexes
int m = 10; // numer of edges
int start = 0; // initial vertex

// three integers u, v, w representing the edge u->v with cost w
int input[MAX_V][3] = {{0, 1, 10}, {0, 2, 5}, {1, 2, 2},  {1, 3, 1}, {2, 1, 3},
                       {2, 3, 9}, {2, 4, 2}, {3, 4, 4}, {4, 3, 6}, {4, 0, 7}};

	for(int i=0; i<m; i++){
		int u = input[i][0];
		int v = input[i][1];
		int w = input[i][2];
		adj[u][degree[u]].v = v;
		adj[u][degree[u]].w = w;
		degree[u]++;
	}

	dijkstra(start);

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




