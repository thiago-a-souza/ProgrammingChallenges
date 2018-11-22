#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX 2000

using namespace std;

int n, m;
int adj[MAX][MAX], grau[MAX];
int visited[MAX], p[MAX];
int nroVert, low[MAX], num[MAX];

int bridge[MAX][MAX];

void findBridges(int v){
int t;

	visited[v] = 1;
	num[v] = low[v] = nroVert++;
	for(int i=0; i<grau[v]; i++){
		t = adj[v][i];
		if(p[v] != t && !bridge[v][t] && !bridge[t][v])
		   bridge[v][t] = 1;
		if(!visited[t]){
		    p[t] = v;
		    findBridges(t);
		    if(low[t] > num[v]){
		       bridge[v][t] = 1;
		       bridge[t][v] = 1;
		    }
		       
		    low[v] = MIN(low[v], low[t]);
		} else if(p[v] != adj[v][i])
		          low[v] = MIN(low[v], num[t]);
	}

}



int main(){
int u, v;
int nbr = 1;

	while(true){
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0)
		   break;
		memset(grau, 0, sizeof(grau));
	    memset(visited, 0, sizeof(visited));
	    memset(bridge, 0, sizeof(bridge));
		memset(p, -1, sizeof(p));
		nroVert = 1;

		for(int i=0; i<m; i++){
		   scanf("%d %d",&u, &v);
		   adj[u][grau[u]++] = v;
		   adj[v][grau[v]++] = u;
		}
		for(int i=1; i<=n; i++)
		   if(!visited[i])
		      findBridges(i);
		printf("%d\n\n", nbr);
		nbr++;
		for(int i=1; i<=n; i++)
		    for(int j=1; j<=n; j++)
		       if(bridge[i][j])
		          printf("%d %d\n",i,j);
		printf("#\n");     
	
		   
	}

	

}

