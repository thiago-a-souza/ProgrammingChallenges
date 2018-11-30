/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION:                                                                          */
/*****************************************************************************************/

#include <iostream>
#include <queue>

#define MAX_V 100 // max number of vertexes
#define MAX_E 100 // max number of edges

using namespace std;


int adj[MAX_V][MAX_V];

void floydMinMax(){
int maxval;

	for(int k=0; k<MAX_V; k++)
	   for(int i=0, i<MAX_V; i++)
	      for(int j=0; j<MAX_V; j++){
	      	   if(adj[i][k] > adj[k][j])
	      	      maxval = adj[i][k];
	      	   else
	      	      maxval = adj[k][j];
	      	   if(adj[i][j] > maxval){
	      	      adj[i][j] = maxval;
	      	      adj[j][i] = maxval;
	      	   }
	      }
}

int main(){

	return 0;
}

