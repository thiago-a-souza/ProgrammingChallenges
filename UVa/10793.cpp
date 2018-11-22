#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAXL 120
#define INF 1000000


#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))


using namespace std;

int main(){
int adj[MAXL][MAXL];
int tests;
int L, D;
int u, v, w;
int line = 1;
int dists[MAXL], minDist, index;

	scanf("%d",&tests);
	while(tests--){
	    scanf("%d %d", &L, &D);
	    
	    for(int i=1; i<=L; i++){
	       for(int j=1; j<=L; j++)
	           adj[i][j] = INF;
	       adj[i][i] = 0;
	    }
	    
	    for(int i=0; i<D; i++){
	        scanf("%d %d %d", &u, &v, &w);
	        adj[u][v] = MIN(adj[u][v], w);
	        adj[v][u] = MIN(adj[v][u], w);

	    }
	    
	    for(int k=1; k<=L; k++)
	       for(int i=1; i<=L; i++)
	          for(int j=1; j<=L; j++)
	              adj[i][j] = MIN(adj[i][j], adj[i][k] + adj[k][j]);

	              
	    for(int i=6; i<=L; i++){
	       dists[i] = -1;
	       if(adj[i][1] == adj[i][2] && adj[i][2] == adj[i][3] && 
	          adj[i][3] == adj[i][4] && adj[i][4] == adj[i][5]){
	           for(int j=1; j<=L; j++)
	               if(adj[i][j] > dists[i])
	                  dists[i] = adj[i][j];
	       } else {
	          dists[i] = INF;
	       }
	         
	    }
// 	    printf("dists: ");
// 	    for(int i=1; i<=L; i++)
// 	       printf("%d ", dists[i]);
// 	    printf("\n");
	    
	    minDist = INF; index = -1;
	    for(int i=6; i<=L; i++)
	        if(dists[i] < minDist){
	           minDist = dists[i];
	           index = i;
	        }

        if(minDist == INF)
           printf("Map %d: %d\n", line++, -1);
        else
	       printf("Map %d: %d\n", line++, minDist);
	    
	   //  for(int i=1; i<=L; i++){
// 	       for(int j=1; j<=L; j++){
// 	           if(adj[i][j] == INF)
// 	              printf("- ");
// 	           else     
// 	              printf("%d ", adj[i][j]);
// 	       }
// 	       printf("\n");
// 	    }
	       
	}
	return 0;
}

