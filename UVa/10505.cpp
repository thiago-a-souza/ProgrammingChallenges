#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 1000


using namespace std;

int part[MAX];
int n, adj[MAX][MAX], grau[MAX], visited[MAX];
bool bipartite[MAX];

void dfsVisit(int id, int s, int p){
int t;

	visited[s] = id;
	part[s] = p;
	for(int i =0; i<grau[s]; i++){
	    t = adj[s][i];
	    if(visited[t] == 0)
	       dfsVisit(id, t, -p);
	    else if(part[t] == p){
	            bipartite[id] = false;
	    }
	            
	             
	}
}

int main(){
int tests; 
int v, vertexes;
int sum, pos, neg;
int id;
	scanf("%d",&tests);
	while(tests--){
		scanf("%d",&n);
		memset(grau, 0, sizeof(grau));
		memset(visited, 0, sizeof(visited));
		memset(part, 0, sizeof(part));
		for(int i=0; i<MAX; i++)
		   bipartite[i] = true;
		
		for(int u=1; u<=n; u++){
		   scanf("%d", &vertexes);
		   for(int j=0; j<vertexes; j++){
		       scanf("%d", &v);
		       adj[u][grau[u]++] = v;
		       adj[v][grau[v]++] = u;
		   }
		}
        id = 1;
		for(int i=1; i<=n; i++){
		   if(!visited[i] && grau[i] > 0){
		      dfsVisit(id, i, -1);		
		      id++;
		   }   
		}

		sum = 0;
		for(int i=1; i<=n; i++)
		   if(!visited[i])
		      sum++;   
		      
		for(int r = 1; r < id; r++){
		    neg = 0; pos = 0;
		    if(!bipartite[r])
		       continue;
     	 	for(int i=1; i<=n; i++){
		       if(visited[i] != r)
		         continue;
		       if(part[i] == -1)
		         neg++;
		       else if(part[i] == 1)
		               pos++;
		    }
		    if(neg > pos)
		       sum += neg;
		    else 
		       sum += pos;
		}
        printf("%d\n", sum);
		   
		   
	}
}

