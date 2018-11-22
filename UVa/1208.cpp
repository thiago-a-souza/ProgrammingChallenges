#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAXV 30
#define MAXE 900

#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef struct{
int u, v, w;
} TAdj;

TAdj adj[MAXE], mst[MAXE];
int p[MAXV], N, M, posMst;

int cmp(const void *a, const void *b){
TAdj *x, *y;
    x = (TAdj*)a;
    y = (TAdj*)b;
    if(x->w < y->w)
      return -1;
    if(x->w > y->w)
      return 1;
    if(x->u < y->u)
       return -1;
    if(x->u > y->u)
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
      for(int i=0; i<MAXV; i++) 
         p[i] = i;
      qsort(adj, M, sizeof(TAdj), cmp);
      posMst = 0;
      for(int i=0; i<M; i++){
            u = adj[i].u; v = adj[i].v;
            u_set = findSet(u);
            v_set = findSet(v);
            if(u_set != v_set){
              p[v_set] = p[u_set];
              mst[posMst++] = adj[i];
            }
       }
}


int main(){
int tests;
int mat[MAXV][MAXV]; 
int line = 1;
 	scanf("%d", &tests);
 	while(tests--){
 	      scanf("%d", &N);
 	      M = 0;
 	      for(int i=0; i<N; i++)
 	         for(int j=0; j<N; j++)
 	             scanf("%d,", &mat[i][j]);
 	      M = 0;
 	      for(int i=0; i<N; i++)
 	         for(int j=i+1; j<N; j++){
 	             if(mat[i][j] <= 0)
 	                continue;
 	             adj[M].u = i; 
 	             adj[M].v = j;
 	             adj[M].w = mat[j][i];
 	             M++; 
 	         }

 	      kruskal();
 	      printf("Case %d:\n",line++);
 	      for(int i=0; i<posMst; i++){
 	         if(mst[i].u < mst[i].v)
 	            printf("%c-%c %d\n", (char)(mst[i].u + 65), (char)(mst[i].v + 65), mst[i].w);
 	         else
 	            printf("%c-%c %d\n", (char)(mst[i].v + 65), (char)(mst[i].u + 65), mst[i].w);
 	      }
 	              	      
 	}
	return 0;
}

