/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION:                                                                          */
/*****************************************************************************************/

#include <iostream>
#include <queue>

#define MAX_V 100 // max number of vertexes
#define MAX_E 100 // max number of edges

using namespace std;

int adj[MAX_V][MAX_E]; // graph
int degree[MAX_V];     // out degree
int indegree[MAX_V];   // in degree
int used[MAX_V];       // vertex used
queue<int> L;          // topological sort

void topological_sort(){
queue<int> z;
int v, w;

	for(int i=0; i<MAX_V; i++)
		indegree[i] = 0;

	for(int i=0; i<MAX_V; i++){
	   if(degree[i]){
	   	  for(int j=0; j<degree[i]; j++)
	   	     indegree[adj[i][j]]++;
	   }
	}

	for(int i=0; i<MAX_V; i++)
	   if(used[i] && !indegree[i])
	       z.push(i);

	while(!z.empty()){
		v = z.front(); z.pop();
		L.push(v);
		for(int i=0; i<degree[v]; i++){
		   w = adj[v][i];
		   indegree[w]--;
		   if(!indegree[w])
		     z.push(w);
		}
	}
}

int main(){
int m; // number of edges	
int s, t;

	for(int i=0; i<MAX_V; i++){
		degree[i] = 0;
		used[i] = 0;
	}

	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &s, &t);
		adj[s][degree[s]++] = t;
		used[s] = used[t] = 1;
	}

	topological_sort();
	while(!L.empty()){
		cout << L.front() << endl;
		L.pop();	
	}

	return 0;
}



