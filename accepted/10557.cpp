#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 10005
#define INF 9999999

using namespace std;

typedef struct {
int u, v;
} Edge;

Edge edge[MAX];


int W[MAX], d[MAX];
int sz;


void bellmanFord(int inicial, int n){

	for(int i=1; i<=n; i++)
	    d[i] = INF;
	
	d[inicial] = -100;
	
	for(int i=0; i<19900; i++){
	   for(int j=0; j<sz; j++){
	       if(d[edge[j].u] >= 0)
	          continue;
	       if(d[edge[j].u] + W[edge[j].v] < d[edge[j].v])
	          d[edge[j].v] = d[edge[j].u] + W[edge[j].v];
	       if(d[n] < INF)
	          return;
	   }
	}
	
	
	
}

main(){
int N;
int energy, doorways, v;

bool ans;
	while(true){
	     scanf("%d",&N);
	     if(N < 0)
	        break;
	     sz = 0;
	     for(int i=1; i<=N; i++){
	        scanf("%d",&energy);
	        scanf("%d",&doorways);
	        W[i] = -energy;
	        for(int j=0; j<doorways; j++){
	           scanf("%d",&v);
	           edge[sz].u = i;
	           edge[sz].v = v;
	           sz++;
	        }
	     }
	     bellmanFord(1,N);
	     if(d[N] < INF)
	        printf("winnable\n");
	     else
	        printf("hopeless\n");
	     
	}
}
