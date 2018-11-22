#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#define MAX 1000

using namespace std;

int N;
bool awake[MAX];
bool visited[MAX];
int adj[MAX][MAX], grau[MAX], d[MAX];



void findConnections(int u){
int sz = 0, max_dist = 0;

	visited[u] = true;
	for(int j=0; j<grau[u]; j++)
	   if(awake[adj[u][j]]){
	     sz++;
	     if(d[adj[u][j]] > max_dist)
	        max_dist = d[adj[u][j]];
	     if(sz >= 3)
	        break;
	   }
	if(sz >= 3){
	   awake[u] = true;
	   d[u] = max_dist + 1;
	   for(int j=0; j<grau[u]; j++)
	      if(!awake[adj[u][j]] && !visited[adj[u][j]])
	         findConnections(adj[u][j]);
	         
	}

}


main(){
int M;
char str[MAX];
map<char, int> mp;
int label;
int u, v;
bool b;
int maxdays;

	while(scanf("%d",&N) != EOF){
		scanf("%d",&M);
		scanf("%s",str);
		label = 1; 
		mp.clear();
		memset(grau, 0, sizeof(grau));
		memset(awake, 0, sizeof(awake));
		memset(d, -1, sizeof(d));
		
		mp[str[0]] = label++; 
		mp[str[1]] = label++;
		mp[str[2]] = label++;
		awake[1] = true; awake[2] = true; awake[3] = true;
		d[1] = 0; d[2] = 0; d[3] = 0;
		
		for(int i=0; i<M; i++){
			scanf("%s",str);
		    if(mp[str[0]] == 0)
		       mp[str[0]] = label++;
		    if(mp[str[1]] == 0)
		       mp[str[1]] = label++;
		    u = mp[str[0]];
		    v = mp[str[1]];
		    
		    adj[u][grau[u]++] = v;
		    adj[v][grau[v]++] = u;
		    memset(visited, 0, sizeof(visited));
		    if(!awake[u]) 
		       findConnections(u);
		    if(!awake[v])
		       findConnections(v);
		}
		b = true;
		maxdays = 0;
		for(int i=1; i<=N; i++) {
		   if(awake[i] == false){
		      b = false;
		      break;
		   }
		   if(d[i] > maxdays)
		      maxdays = d[i];
		}
		
		if(!b)
		   printf("THIS BRAIN NEVER WAKES UP\n");
		else
		   printf("WAKE UP IN, %d, YEARS\n",maxdays);
		
		
		
		       
		
	}
}