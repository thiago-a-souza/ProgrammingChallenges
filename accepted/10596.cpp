#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 10001
using namespace std;

int adj[MAX][MAX], grau[MAX], grauIn[MAX], visited[MAX];
int N, R;


void dfsVisit(int s){
int t;
    visited[s] = 1;
    for(int j=0; j<grau[s]; j++){
       t = adj[s][j];
       if(!visited[t]) 
         dfsVisit(t);
    }
}


bool isEulerian(){

    for(int i=0; i<N; i++)
       if((grau[i] + grauIn[i])%2 != 0)
            return false;

    memset(visited, 0, sizeof(visited));         
         
    for(int i=0; i<N; i++) 
      if(grau[i] > 0){
         dfsVisit(i);
         break;
      }
    
    for(int i=0; i<N; i++)
      if(grau[i] > 0 && visited[i] == 0)
         return false;

    return true;
} 

main(){
int u, v;

	while(scanf("%d %d",&N, &R) != EOF){
	     memset(grau, 0, sizeof(grau));
	     memset(grauIn, 0, sizeof(grauIn));
	     for(int i=0; i<R; i++){
	    	scanf("%d %d",&u,&v);
	    	adj[u][grau[u]++] = v;
	    	grauIn[v]++;
	    	
	     }	        
	     if(R > 0 && isEulerian())
	        printf("Possible\n");
	     else
	        printf("Not Possible\n");
	     
	}
}


