#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define MAX 200000

using namespace std;

typedef struct{
int u, v;
double w;
} TAdj;

TAdj adj[MAX];
int nro_arestas, posMst;
int p[MAX];
double ans;

int cmp(const void *a, const void *b){ 
TAdj *x, *y;

    x = (TAdj*)a;
    y = (TAdj*)b;
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

void kruskal(int vertexes, int max_edges){
int u, v, u_set, v_set;

	posMst = 0;
	for(int i=0; i<vertexes; i++)
	    p[i] = i;
	qsort(adj, nro_arestas, sizeof(TAdj), cmp);
	for(int i=0; i<nro_arestas; i++){
	    u = adj[i].u; v = adj[i].v;
	    u_set = findSet(u);
	    v_set = findSet(v);
	    if(u_set != v_set){
	       p[v_set] = p[u_set];
	       posMst++;
	       if(posMst >= max_edges){
	          ans = adj[i].w;
	          break;
	       }
	    }
	}
}

main(){
int tests, S, P;
int mat[501][2];
	scanf("%d",&tests);
	while(tests--){
		 scanf("%d %d",&S,&P);
		 for(int i=0; i<P; i++)
		    scanf("%d %d",&mat[i][0],&mat[i][1]);

		 nro_arestas = 0;
		 for(int i=0; i<(P-1); i++)
		    for(int j=i+1; j<P; j++){
		        adj[nro_arestas].u = i;
		        adj[nro_arestas].v = j;
		        adj[nro_arestas].w = sqrt(
		           ((mat[i][0]-mat[j][0])*(mat[i][0]-mat[j][0])) +
		           ((mat[i][1]-mat[j][1])*(mat[i][1]-mat[j][1]))  
		        );
		        nro_arestas++;
		    }
		 kruskal(P,P-S);
		 printf("%.2lf\n",ans);
	}
}

