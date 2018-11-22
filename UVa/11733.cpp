#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 100000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef struct{
int u, v, w;
} TAdj;

TAdj adj[MAX];
int nro_arestas, total;
int p[MAX], A, airports;

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
      for(int i=0; i<MAX; i++)
         p[i] = i;
         
      total = 0;
      
      qsort(adj, nro_arestas, sizeof(TAdj), cmp);
      for(int i=0; i<nro_arestas; i++){
            u = adj[i].u; v = adj[i].v;
            u_set = findSet(u);
            v_set = findSet(v);
            if(u_set != v_set && adj[i].w < A){
              p[v_set] = p[u_set];
              total += adj[i].w;
              airports--;
			} 
	  }
}


int main(){
int T, N, M;
int x, y, c;
int line = 1;

	scanf("%d",&T);
	while(T--){
		  scanf("%d %d %d",&N, &M, &A);
		  nro_arestas = 0;
		  for(int i=0; i<M; i++){
		      scanf("%d %d %d",&x, &y, &c);
		      adj[nro_arestas].u = x;
		      adj[nro_arestas].v = y;
		      adj[nro_arestas].w = c;
		      nro_arestas++;
		  }
		  airports = N;
		  kruskal();
		  printf("Case #%d: %d %d\n", line++, total + (airports*A)  , airports);
	}
	return 0;
}

