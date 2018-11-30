/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Calculates the mininum distance from every vertex to all vertexes using  */
/* Floyd–Warshall algorithm. Remark: this algorithm doesn't work with negative cycles.   */
/*****************************************************************************************/

#include <iostream>

#define MAX_V 100 // max number of vertexes
#define MAX_E 100 // max number of edges

const int INF = 0x3F3F3F3F;

using namespace std;

int adj[MAX_V][MAX_V]; // graph
int p[MAX_V][MAX_V];   // parent

void initialize(){
	for(int i=0; i<MAX_V; i++){
	   for(int j=0; j<MAX_V; j++){
		    adj[i][j] = INF;
	   	 p[i][j] = -1;
	   }
	   adj[i][i] = 0;
	}
}

void floyd(){
	for(int k=0; k<MAX_V; k++)
	   for(int i; i<MAX_V; i++)
	      for(int j; j<MAX_V; j++)
	         if(adj[i][k] + adj[k][j] < adj[i][j]){
	            adj[i][j] = adj[i][k] + adj[k][j];
	            p[i][j]= p[k][j];
	         }
}

int main(){
int m; // number of edges
int u, v, w;

	initialize();

	scanf("%d", &m);

	for(int i=0; i<m; i++){
		scanf("%d %d %d", &u, &v, &w);
		adj[u][v] = w;
	}

	floyd();
	

	return 0;
}


