#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define MAX 200000
#define INF 999999999
using namespace std;

typedef struct{
int u, v, w;
} TAdj;

TAdj adj[MAX], mst[MAX];
int vertexes, edges, posMst;
int p[MAX];
int last_index;

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

int kruskal(bool storeMst){
int u, v, u_set, v_set;
int ans;

	for(int i=0; i<vertexes; i++)
	    p[i] = i;
	qsort(adj, edges, sizeof(TAdj), cmp);
	ans = 0;
	for(int i=0; i<edges; i++){
	    u = adj[i].u; v = adj[i].v;
	    u_set = findSet(u);
	    v_set = findSet(v);
	    if(u_set != v_set){
	       p[v_set] = p[u_set];
	       ans += adj[i].w;
	       if(storeMst)
	          mst[posMst++] = adj[i];
	    }
	}
	return ans;
}

main(){
int tests;
int u, v, w;
int ans1, ans2, tmp, aux;
	scanf("%d",&tests);
	while(tests--){
		scanf("%d %d",&vertexes,&edges);
		for(int i=0; i<edges; i++){
		   scanf("%d %d %d",&u,&v,&w);
		   adj[i].u = u-1;
		   adj[i].v = v-1;
		   adj[i].w = w;
		}
		posMst = 0;
		ans1 = kruskal(true);
		ans2 = INF;
		for(int i=0; i<posMst; i++){
		   for(int j=0; j<edges; j++)
		       if(adj[j].u == mst[i].u && adj[j].v == mst[i].v && adj[j].w == mst[i].w){
		          aux = adj[j].w;
		          adj[j].w = INF;
		          break;
		       }
		   tmp = kruskal(false);
		   if(tmp < ans2)
		      ans2 = tmp;
		   for(int j=0; j<edges; j++)
		      if(adj[j].w == INF){
		         adj[j].w = aux;
		         break;
		      }
		}
		printf("%d %d\n",ans1,ans2);
	}
	
}

