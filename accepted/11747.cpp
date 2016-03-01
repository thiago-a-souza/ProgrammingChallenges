#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAXV 1000
#define MAXE 25000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef struct{
int u, v, w;
bool connected;
} TAdj;

TAdj adj[MAXE];
int p[MAXV], N, M;

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
      for(int i=0; i<M; i++){
            u = adj[i].u; v = adj[i].v;
            u_set = findSet(u);
            v_set = findSet(v);
            if(u_set != v_set){
              p[v_set] = p[u_set];
              adj[i].connected = true;
            }
       }
}


int main(){
bool flag;
	while(true){
		scanf("%d %d", &N, &M);
		if(!N || !M)
		   break;
		for(int i=0; i<M; i++){
		   scanf("%d %d %d",&adj[i].u, &adj[i].v, &adj[i].w);
		   adj[i].connected = false;
		}
		kruskal();
		flag = false;
		for(int i=0; i<M; i++)
		   if(!adj[i].connected){
		       if(flag)
		          printf(" ");
		       flag = true;
		       printf("%d", adj[i].w);
		   }
		if(!flag)
		   printf("forest");
		printf("\n");
		    
		
		
	}
	return 0;
}

