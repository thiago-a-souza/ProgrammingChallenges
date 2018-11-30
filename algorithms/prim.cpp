/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Minimum spanning tree using Prim's algorithm                             */
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
int degree[MAX_V];       // vertex degree
int d[MAX_V];            // min distance
int p[MAX_V];            // parent
int visited[MAX_V];      // vertexes visited
int total_weight;        // total MST weight

void prim(int start){
priority_queue< pair<int, int> > heap;
int s, t, w;

	for(int i=0; i<MAX_V; i++){
	   d[i] = INF;
	   p[i] = -1;
	   visited[i] = 0;
	}

	heap.push(make_pair(d[start] = 0, start));
	total_weight = 0;
	while(!heap.empty()){
		s = heap.top().second; 
		heap.pop();
		if(!visited[s])
	       total_weight += d[s];
		visited[s] = 1;
		for(int i=0; i<degree[s]; i++){
		   t = adj[s][i].v; 
		   w = adj[s][i].w;
		   if(d[t] > w && !visited[t]){
			  d[t] = w;
			  p[t] = s;
			  heap.push(make_pair(-d[t], t));
	       }
		}
	}
}

int main(){
int m;     // number of edges	
int start; // initial vertex
int s, t, w;

	for(int i=0; i<MAX_V; i++)
		degree[i] = 0;

	scanf("%d", &start);
	scanf("%d", &m);
	for(int i=0; i<m; i++){
	    scanf("%d %d %d",&s, &t, &w);
		adj[s][degree[s]].v = t;
		adj[s][degree[s]].w = w;
		degree[s]++;
		
		adj[t][degree[t]].v = s;
		adj[t][degree[t]].w = w;
		degree[t]++;
	}
	
	prim(start);

	printf("MST total weight = %d\n", total_weight);

	return 0;

}


