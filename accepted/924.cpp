#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAX 3000

int adj[MAX][MAX], grau[MAX], d[MAX];
int V;

using namespace std;

void bfs(int inicio){
int s, t;
int visited[MAX];
queue<int> Q;

	memset(visited, 0, sizeof(visited));
	memset(d, 0, sizeof(d));
	d[inicio] = 0;
	visited[inicio] = 1;
	Q.push(inicio);
	while(!Q.empty()){
	     s = Q.front();
	     Q.pop();
	     for(int i=0; i<grau[s]; i++){
	         t = adj[s][i];
	         if(visited[t] == 0){
	            visited[t] = 1;
	            d[t] = d[s] + 1;
	            Q.push(t);
	         }
	     }
	}

}

main(){
int n, u, t;
///
int max_dist, sz, day, tmp;


	while(scanf("%d",&V) != EOF){
	     memset(grau,0,sizeof(grau));
	     for(int i=0; i<V; i++){
	        scanf("%d",&n);
	        for(int j=0; j<n; j++){
	            scanf("%d",&u);
	            adj[i][grau[i]++] = u;
	        }
	     }
	     scanf("%d",&t);
	     for(int i=0; i<t; i++){
	        scanf("%d",&u);
	        if(grau[u] == 0){
	           printf("0\n");
	        } else {
	           bfs(u);
	           max_dist = 0;
	           for(int i=0; i<V; i++)
	              if(d[i] > max_dist)
	                 max_dist = d[i];
               sz = 0; 
	           for(int i=1; i<=max_dist; i++){
	              tmp = 0;
	              for(int j=0; j<V; j++)
	                  if(d[j] == i) 
	                     tmp++;
	              if(tmp > sz){
	                 sz = tmp;
	                 day = i;
	              }
	           }
	           if(sz == 0)
	              printf("0\n");
	           else 
	              printf("%d %d\n",sz, day);
	        }
	        
	        
	     } 
	}


}

