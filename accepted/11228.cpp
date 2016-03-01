#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define MAX 1005
using namespace std;

typedef struct {
int u, v;
double w;
} TEdge;


TEdge edge[MAX*MAX], mst[MAX*MAX];

int p[MAX*MAX];
int edges;
int N, R;
int posMst;
int states;
double road, railroad;

int cmp(const void *a, const void *b){ 
TEdge *x, *y;

    x = (TEdge*)a;
    y = (TEdge*)b;
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

	for(int i=0; i<N; i++)
	    p[i] = i;
	qsort(edge, edges, sizeof(TEdge), cmp);
	for(int i=0; i<edges; i++){
	    u = edge[i].u; v = edge[i].v;
	    u_set = findSet(u);
	    v_set = findSet(v);
	    if(u_set != v_set){
	       p[v_set] = p[u_set];
	       mst[posMst++] = edge[i];
	       if(edge[i].w > R){
	          railroad += edge[i].w;
	          states++;
	       } else {
	          road += edge[i].w;
	       }
	    }
	}
}


main(){
int T;
int x, y;
pair< int, int> points[MAX];
int line = 1;


	scanf("%d",&T);
	
	while(T--){
		scanf("%d %d",&N,&R);
		for(int i=0; i<N; i++){
		    scanf("%d %d",&x,&y);
		    points[i] = make_pair(x,y);
		}
		edges = 0;
		for(int i=0; i<(N-1); i++)
		   for(int j=i+1; j<N; j++){
		      edge[edges].u = i;
		      edge[edges].v = j;
		      edge[edges].w = sqrt(
		        ((points[i].first - points[j].first)*(points[i].first - points[j].first)) + 
		        ((points[i].second - points[j].second)*(points[i].second - points[j].second))
		      );
		      edges++;
		   }
		posMst = 0;
		road = 0.0; railroad = 0.0;
		states = 1;
		kruskal();
		printf("Case #%d: %d %.0lf %.0lf\n",line++, states, round(road), round(railroad));
		       
	}
}

