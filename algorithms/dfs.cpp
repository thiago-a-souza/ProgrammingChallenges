/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Visits all reachable vertexes from a starting vertex using DFS.          */
/*****************************************************************************************/

#include <iostream>

#define MAX_V 100 // max number of vertexes
#define MAX_E 100 // max number of edges

using namespace std;

int adj[MAX_V][MAX_E]; // graph
int degree[MAX_V];     // vertex degree
int p[MAX_V];          // parent
int d[MAX_V];          // minimun distance for unweighted graphs
int visited[MAX_V];    // vertexes visited


void dfs(int s){
int t;
	visited[s] = 1;

	for(int i=0; i<degree[s]; i++){
	   t = adj[s][i];
	   if(!visited[t]){
	     p[t] = s;
	     dfs(t);
	   }
	}
}



int main(){


}
