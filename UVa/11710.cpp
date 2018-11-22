#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>

#define MAX_E 80000
#define MAX_V 450

using namespace std;

typedef struct{
int u, v, w;
} TAdj;

TAdj adj[MAX_E];
int p[MAX_V], nro_arestas, total;


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

      for(int i=0; i<MAX_V; i++) // todos vértices
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
int S, C;
char nme1[100], nme2[100];
map<string, int> stations;
int vertexes, cost;
int startNode;
int u_set, v_set;
bool flag;

	while(true){
	     scanf("%d %d",&S, &C);
	     if(S == 0 && C == 0)
	        break;
	     vertexes = 0;
	     stations.clear();
	     for(int i=0; i<S; i++){
	        memset(nme1, '\0', sizeof(nme1));
	        scanf("%s", nme1);
	        stations[nme1] = vertexes++;
	     }
	     for(int i=0; i<C; i++){
	        scanf("%s %s %d", nme1, nme2, &cost);
	        adj[i].u = stations[nme1];
	        adj[i].v = stations[nme2];
	        adj[i].w = cost;
	        
	     }
	     nro_arestas = C;
	     scanf("%s", nme1);
	     startNode = stations[nme1];
	     kruskal();
	     u_set = findSet(startNode);
	     flag = true;
	     for(int i=0; i<vertexes; i++){
	         if(u_set != findSet(i)){
	            flag = false;
	            break;
	         }
	     }
	     if(flag)
	        printf("%d\n", total);
	     else
	        printf("Impossible\n");
	}
	return 0;
}

