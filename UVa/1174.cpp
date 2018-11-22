#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>


#define MAXE 50000
#define MAXV 2000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef struct{
int u, v, w;
} TAdj;

TAdj adj[MAXE];
int p[MAXV], N, M, total;

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
      for(int i=0; i<MAXV; i++) 
         p[i] = i;
      qsort(adj, M, sizeof(TAdj), cmp);
      total = 0;
      for(int i=0; i<M; i++){
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
int tests, cost, index;
char city1[10], city2[10];
int u, v;
map<string, int> names;

	scanf("%d",&tests);
	while(tests--){
        names.clear();
        index = 0;
		scanf("%d", &N);
		scanf("%d", &M);
		for(int i=0; i<M; i++){
		    memset(city1, '\0', sizeof(city1));
		    memset(city2, '\0', sizeof(city2));		    
		    scanf("%s %s %d", city1, city2, &cost);
		    if(names.count(city1) > 0)
		       u = names[city1];
		    else {
		       names[city1] = index;
		       u = index++;
		    }
		       
		    if(names.count(city2) > 0)
		       v = names[city2];
		    else {
		       names[city2] = index;
		       v = index++;
		    }
		    adj[i].u = u;
		    adj[i].v = v;
		    adj[i].w = cost;
		}
		
		kruskal();
		printf("%d\n", total);
		if(tests)
	       printf("\n");
		
	}

	return 0;
}

