#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>

#define MAX 200
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define INF 2000000


int adj[MAX][MAX];
int N, E, T, M;

using namespace std;

int main(){
int tests;
int u, v, w;
int ans;

	scanf("%d", &tests);
	while(tests--){
	     scanf("%d",&N);
	     scanf("%d",&E);
	     scanf("%d",&T);
	     scanf("%d",&M);
	     N++;
	     memset(adj, 63, sizeof(adj));
	     
	     for(int i=0; i<M; i++){
	         scanf("%d %d %d", &u, &v, &w);
	         adj[u][v] = w;
	     }
	     
	     for(int k=0; k<N; k++)
	        for(int i=0; i<N; i++)
	           for(int j=0; j<N; j++)
	              if(adj[i][k] + adj[k][j] < adj[i][j])
	                 adj[i][j] = adj[i][k] + adj[k][j];
	     
	     ans = 0;
	     for(int i=0; i<N; i++)
	         if( adj[i][E] <= T || i == E)
	            ans++;
	     printf("%d\n", ans);
	     if(tests)
	        printf("\n");
	}
	return 0;
}

