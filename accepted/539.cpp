#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

#define MAX 30

using namespace std;

int adj[MAX][MAX], grau[MAX];
int p[MAX];
int n, m;
int longest;

void dfs(int s, int length, int visited[MAX][MAX]){
int t;

	if(length > longest)
	   longest = length;
	   
	for(int i=0; i<grau[s]; i++){
	   t = adj[s][i];
	   if(visited[s][t] == 0){
	      p[t] = s;
	      visited[s][t] = 1;
	      visited[t][s] = 1;
	      
	      dfs(t, length+1, visited);
	      
	      p[t] = -1;
	      visited[s][t] = 0;
	      visited[t][s] = 0;
	   }
	}
}

int main(){
int u, v;
int visited[MAX][MAX];

	while(true){
		 scanf("%d %d", &n, &m);
		 if(n == 0 && m == 0)
		    break;	    
		 memset(grau, 0, sizeof(grau));
		 
		 for(int i=0; i<m; i++){
		     scanf("%d %d", &u, &v);
		     adj[u][grau[u]++] = v;
		     adj[v][grau[v]++] = u;  
		 }
		 longest = 0;
		 for(int i=0; i<n; i++){
		     memset(visited, 0, sizeof(visited));
		     memset(p, -1, sizeof(p));
		     dfs(i, 0, visited);
		 }
		 
		 printf("%d\n", longest);

	}

	return 0;
}

