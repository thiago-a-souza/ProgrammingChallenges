#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 1000000

using namespace std;

typedef struct{
int u, v, w;
} TAdj;

TAdj adj[MAX];
int p[MAX], N, M, maxWeight;


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

      for(int i=0; i<N; i++) 
         p[i] = i;
      qsort(adj, M, sizeof(TAdj), cmp);
      maxWeight = 0;
      for(int i=0; i<M; i++){
            u = adj[i].u; v = adj[i].v;
            u_set = findSet(u);
            v_set = findSet(v);
            if(u_set != v_set){
              p[v_set] = p[u_set];
              if(adj[i].w > maxWeight)
                 maxWeight = adj[i].w;
            } 
      }
}

int main(){
int s, t, w;
bool flag;

	while(true){
	     scanf("%d %d",&N, &M);
	     if(N == 0 && M == 0)
	        break;
	     for(int i=0; i<M; i++){
	        scanf("%d %d %d",&s, &t, &w);
	        adj[i].u = s;
	        adj[i].v = t;
	        adj[i].w = w;
	     }
	     kruskal();
	     s = findSet(0);
	     w = adj[0].w;
	     flag = true;
	     for(int i=1; i<N; i++){
	        if(s != findSet(i)){
	           flag = false;
	           break;
	        }

	     }
	     if(flag)
	       printf("%d\n", maxWeight);
	     else
	       printf("IMPOSSIBLE\n");
	}
	return 0;
}

