#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>

#define MAX 1001

int adj[MAX][MAX], grau[MAX], d[MAX], visited[MAX];

using namespace std;

void bfs(int inicio){
int s, t;
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

int main(){
int tests, n, m;
int u, v;
bool first = true;

	scanf("%d", &tests);
	while(tests--){
	    if(!first)
	       printf("\n");
	    first = false;
	    
		scanf("%d %d",&n, &m);
		memset(grau, 0, sizeof(grau));
		for(int i=0; i<m; i++){
		   scanf("%d %d", &u, &v);
		   adj[u][grau[u]++] = v;
		   adj[v][grau[v]++] = u;
		}	
		bfs(0);
		for(int i=1; i<n; i++)
		   printf("%d\n", d[i]);
	}	
	return 0;
}

