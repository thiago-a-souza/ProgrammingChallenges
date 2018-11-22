#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX_A 100000
#define MAX_V 100000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef struct{
int u, v, w;
} TAdj;

TAdj adj[MAX_A];
int nro_arestas, posMst;
int p[MAX_V];


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

void kruskal(){
int u, v, u_set, v_set;
      posMst = 0;
      for(int i=0; i<MAX_V; i++) // todos vértices
         p[i] = i;
      qsort(adj, nro_arestas, sizeof(TAdj), cmp);
      for(int i=0; i<nro_arestas; i++){
            u = adj[i].u; v = adj[i].v;
            u_set = findSet(u);
            v_set = findSet(v);
            if(u_set != v_set){
              p[v_set] = p[u_set];
              posMst++;
            } 
      }
}

int main(){
int s, t;

	while(scanf("%d",&s) != EOF ){
	      nro_arestas = 0;
	      while(true){
	            if(s == -1)
	               break;
	            scanf("%d", &t);
	            adj[nro_arestas].u = s;
	            adj[nro_arestas].v = t;
	            adj[nro_arestas].w = 1;
	            nro_arestas++;
	            scanf("%d",&s);
	      }
	      kruskal();
	      printf("%d\n", nro_arestas - posMst);
	    
	
	}
	return 0;
}


