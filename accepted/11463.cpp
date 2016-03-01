#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

#define MAX 111
#define INF 9999
using namespace std;

int adj[MAX][MAX];


main(){
int tests, n, r;
int u, v;
int ans, line = 1;
	scanf("%d",&tests);
	while(tests--){
   	     scanf("%d",&n);
   	     scanf("%d",&r);
	     for(int i=0; i<=n; i++){
	        for(int j=0; j<=n; j++)
	            adj[i][j] = INF;
	        adj[i][i] = 0;
	     }
	     for(int i=0; i<r; i++){
	        scanf("%d %d",&u, &v);
	        adj[u][v] = 1;
	        adj[v][u] = 1;
	     }
	     scanf("%d %d",&u,&v);
	     for(int k=0; k<n; k++)
	         for(int i=0; i<n; i++)
	            for(int j=0; j<n; j++)
	                if(adj[i][k] + adj[k][j] < adj[i][j]){
	                  adj[i][j] = adj[i][k] + adj[k][j];
	                }	 
	     ans = -1;               
	     for(int i=0; i<n; i++)
	         if(adj[u][i] + adj[i][v] > ans)
	            ans = adj[u][i] + adj[i][v];
	     printf("Case %d: %d\n",line,ans);
	     line++;
	     
	     
	     

	}

}

