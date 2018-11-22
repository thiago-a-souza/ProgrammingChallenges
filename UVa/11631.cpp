#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

#define MAX 200000
using namespace std;

typedef struct {
int u, v, w;
} TAdj;

TAdj adj[MAX], mst[MAX];
int m, n, sz;
int p[MAX], posMst, total;

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
	for(int i=0; i<=m; i++)
	   p[i] = i;
	qsort(adj, n, sizeof(TAdj), cmp);
	total = 0;
	for(int i=0; i<n; i++){
	   u = adj[i].u; v = adj[i].v;
	   u_set = findSet(u);
	   v_set = findSet(v);
	   if(u_set != v_set){
	      p[v_set] = p[u_set];
	   //   mst[posMst++] = adj[i];
	      total += adj[i].w;
	   }
	}
	

}

main(){
int u, v, w;
int sum;

	while(true){
	   scanf("%d %d",&m,&n);
	   if(m == 0 && n == 0)
	      break;
	   sz = 0;
	   sum = 0;
	   for(int i=0; i<n; i++){
	      scanf("%d %d %d",&u,&v,&w);
	      adj[sz].u = u;
	      adj[sz].v = v;
	      adj[sz].w = w;
	      sz++;
	      sum += w;
	   }
	   kruskal();
	   printf("%d\n",sum-total);
	      
	}
}

