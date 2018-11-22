/*
Algoritmo de Floyd para encontrar a menor distância entre todos os pares de vértices.
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map> 
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack>  

#define MAX 30
#define INF 10000000

using namespace std;

int adj[MAX][MAX];

void initialize(){
	for(int i=0; i<MAX; i++){
	   for(int j=0; j<MAX; j++)
	      adj[i][j] = INF;
	   adj[i][i] = 0;
	}	     
}

void floyd(){

	for(int k=1; k<21; k++)
	   for(int i=1; i<21; i++)
	      for(int j=1; j<21; j++)
	         if(adj[i][k] + adj[k][j] < adj[i][j])
	            adj[i][j] = adj[i][k] + adj[k][j];

}

main(){
int n, tmp;
int x, y;
int line = 1;

		while(scanf("%d",&n) != EOF){
		     initialize();
		     for(int i=0; i<n; i++){
		        scanf("%d",&tmp);
		        adj[1][tmp] = 1;
		        adj[tmp][1] = 1;
		     }
		     
		     for(int i=2;  i<20; i++){
		         scanf("%d",&n);
		         for(int j=0; j<n; j++){
		             scanf("%d",&tmp);
		             adj[i][tmp] = 1;
		             adj[tmp][i] = 1;
		         }
		     }
		     
		     floyd();

		     printf("Test Set #%d\n",line);
		        
		     line++;
		     
		     scanf("%d",&n);
		     for(int i=0; i<n; i++){
		        scanf("%d %d",&x,&y);
		        printf("%2d to %2d: %d\n",x,y,adj[x][y]);
		     }
 	         printf("\n");
		     
		}
}

