#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<queue>

#define MAX_V 1000

using namespace std;

int indegree[MAX_V];
int used[MAX_V];
int grau[MAX_V];
int adj[MAX_V][MAX_V];
queue<int> L;

void topological_sort(){
queue<int> z;
int v, w;

		memset(indegree, 0, sizeof(indegree));
		for(int i=0; i<MAX_V; i++)
		   if(grau[i])
		     for(int j=0; j<grau[i]; j++)
		        indegree[adj[i][j]]++;
		for(int i=0; i<MAX_V; i++)
		   if(used[i] && !indegree[i])
		      z.push(i);
		while(!z.empty()){
		     v = z.front();
		     z.pop();
		     L.push(v);
		     for(int i=0; i<grau[v]; i++){
		         w = adj[v][i];
		         indegree[w]--;
		         if(!indegree[w])
		            z.push(w);
		     }
		}
}

main(){
int n, m;
int a, b;
bool first;
		while(true){
		     scanf("%d %d",&n,&m);
		     if(n == 0 && m == 0)
		        break;
		     
		     memset(grau,0,sizeof(grau));
		     memset(used,0,sizeof(used));

			 for(int i=1; i<=n; i++)
			     used[i] = 1;
			     
		     for(int i=0; i<m; i++){
		        scanf("%d %d",&a,&b);
		        adj[a][grau[a]++] = b;
		     }
		     topological_sort();
		     first = true;
		     while(!L.empty()){
		         if(first){
		           printf("%d", L.front());
		           first = false;
		         } else {
		           printf(" %d", L.front());
		         }
		         L.pop();
		     }
		     printf("\n");
		}
}

