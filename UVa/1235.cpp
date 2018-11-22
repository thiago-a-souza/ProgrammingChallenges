#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAXV 501
#define MAXE 200000
#define INF 2147483647
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))

using namespace std;

typedef struct{
int u, v, w;
} TAdj;

TAdj adj[MAXE];
int N, p[MAXV], nro_arestas, total;

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
      for(int i=0; i<MAXV; i++) // todos vértices
         p[i] = i;
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


int minDist(int x, int y){
int A[4], B[4];
int aux1, aux2, aux3;
int index = 3;
int ans = 0;


    
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	
	while(x > 0){
	      A[index--] = x%10;
	      x = x/10;
	}
	
	index = 3;
	while(y > 0){
	      B[index--] = y%10;
	      y = y/10;
	}
	
	for(int d=0; d<4; d++){
	    if(A[d] <= B[d]){
	       aux1 = A[d];
	       aux2 = B[d];
	    } else {
	       aux1 = B[d];
	       aux2 = A[d];
	    }
	    
	    for(int i=0; i<10; i++){
	        if((aux2 + i)%10 == aux1){
	           aux3 = i;
	           break;
	        }
	    }
	    ans += MIN(aux2-aux1, aux3);
	}
	return ans;
}

int main(){
int locks[MAXV];
int tests;



	scanf("%d", &tests);
	while(tests--){
	      scanf("%d",&N);
	      for(int i=0; i<N; i++)
	         scanf("%d",&locks[i]);
	      nro_arestas = 0;
	      total = INF;
	      for(int i=0; i<N; i++)
	          total = MIN(total, minDist(0, locks[i]));

          for(int i=0; i<N; i++) 
             for(int j=i+1; j<N; j++){
                 adj[nro_arestas].u = i;
                 adj[nro_arestas].v = j;
                 adj[nro_arestas].w = minDist(locks[i], locks[j]);
                 nro_arestas++;
             }
          kruskal();
          cout << total << endl;
	}
	return 0;
}

