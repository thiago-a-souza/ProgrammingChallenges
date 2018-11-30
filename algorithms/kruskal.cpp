/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Minimum spanning tree using Kruskal's algorithm                          */
/*****************************************************************************************/

#include <iostream>

#define MAX_V 100 // max number of vertexes
#define MAX_E 100 // max number of edges

const int INF = 0x3F3F3F3F;

using namespace std;

typedef struct{
int u, v; // u -> v
int w;
} t_adj;

t_adj adj[MAX_E]; // graph
t_adj mst[MAX_E]; // mst after running Kruskal
int p[MAX_V];     // parent
int m;            // number of edges
int total_weight; // total MST weight
int edges_mst;    // number of edges from the MST

int cmp(const void *a , const void *b){
t_adj *x, *y;

	x = (t_adj*)a; y = (t_adj*)b;
	if(x->w < y->w)
	  return -1;
	if(x->w > y->w)
	  return 1;
	return 0;
}

int findSet(int x){
	if(x != p[x])
	  p[x] = findSet(p[x]);
	return p[x];
}

void kruskal(){
int u, v, u_set, v_set;

	for(int i=0; i<MAX_V; i++) 
	   p[i] = i;
	qsort(adj, m, sizeof(t_adj), cmp);
	edges_mst = 0;
	for(int i=0; i<m; i++){
		u = adj[i].u; v = adj[i].v;
		u_set = findSet(u);
		v_set = findSet(v);
		if(u_set != v_set){
		  p[v_set] = p[u_set];
		  mst[edges_mst++] = adj[i];
		  total_weight += adj[i].w;
		}
	}
}

int main(){
int u, v, w;

	scanf("%d", &m);
	for(int i=0; i<m; i++){
	    scanf("%d %d %d",&u, &v, &w);
		adj[i].u = u;
		adj[i].v = v;
		adj[i].w = w;
	}
	
	kruskal();

	printf("MST total weight = %d\n", total_weight);

	for(int i=0; i<edges_mst; i++)
	   printf("%d %d %d\n", mst[i].u, mst[i].v, mst[i].w);

	return 0;
}
