#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX_A 1000001
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef struct{
int u, v, w;
} TAdj;

TAdj adj[MAX_A];

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


int nro_arestas, total;
int p[MAX_A];

int findSet(int x){
      if(x != p[x])
        p[x] = findSet(p[x]);
      return p[x];
}

void kruskal(){
int u, v, u_set, v_set;
      for(int i=0; i<MAX_A; i++)
         p[i] = i;
         
      total = 0;
      
      qsort(adj, nro_arestas, sizeof(TAdj), cmp);
      for(int i=0; i<nro_arestas; i++){
            u = adj[i].u; v = adj[i].v;
            u_set = findSet(u);
            v_set = findSet(v);
            if(u_set != v_set){
              p[v_set] = p[u_set];
              total += adj[i].w;
			} 
	  }
}

int main(){
int k, m, n, s, t, w;
int oldWeight;
bool first = true;

	while(scanf("%d",&n) != EOF){
	      if(!first)
	         printf("\n");
	      first = false;
	      
	      oldWeight = 0;
	      nro_arestas = 0;
		  for(int i=0; i<n-1; i++){
		     scanf("%d %d %d",&s, &t, &w);
		     oldWeight += w;
		  }
		  
		  scanf("%d",&k);
		  for(int i=0; i<k; i++){
		     scanf("%d %d %d", &s, &t, &w);
		     adj[nro_arestas].u = s;
		     adj[nro_arestas].v = t;
		     adj[nro_arestas].w = w;
		     nro_arestas++;
		  }
		  
		  scanf("%d",&m);
		  for(int i=0; i<m; i++){
		     scanf("%d %d %d", &s, &t, &w);
		     adj[nro_arestas].u = s;
		     adj[nro_arestas].v = t;
		     adj[nro_arestas].w = w;
		     nro_arestas++;		     
		  }
		  
		  kruskal();
		  printf("%d\n%d\n", oldWeight, total);    
	}
	return 0;
}
