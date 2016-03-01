#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

#define MAX 999
#define INF 9999999

using namespace std;

typedef struct {
int v, w;
} TAdj;

TAdj adj[MAX*MAX][4];
int mat[MAX][MAX];
int grau[MAX*MAX], d[MAX*MAX];
int rows, cols;

void dijkstra(int inicial){
priority_queue< pair<int, int> > heap;
int s, t, peso;

	for(int i=0; i<(rows*cols); i++)
	    d[i] = INF; 

	heap.push(make_pair(d[inicial] = mat[0][0], inicial));
	while(!heap.empty()){
	     s = heap.top().second;
	     heap.pop();
	     for(int i=0; i<grau[s]; i++){
	         t = adj[s][i].v;
	         peso = adj[s][i].w;
	         if(d[s] + peso < d[t]){
	            d[t] = d[s] + peso;
	            heap.push(make_pair(-d[t], t));
	         }
	     }
	     
	}
}

void constructGraph(){
int index;
 
 	for(int i=0; i<rows; i++)
 	   for(int j=0; j<cols; j++){
 	       index = (i*cols) + j;
 	       if(i - 1 >= 0){
 	           adj[index][grau[index]].v = ((i-1)*cols) + j;
 	           adj[index][grau[index]].w =  mat[i-1][j];
 	           grau[index]++;
 	       }
 	       if(j - 1 >= 0){
 	          adj[index][grau[index]].v = (i*cols) + j - 1;
 	          adj[index][grau[index]].w =  mat[i][j-1];
 	          grau[index]++;
 	       }
 	       if(j + 1 < cols){
 	          adj[index][grau[index]].v = (i*cols) + j + 1;
 	          adj[index][grau[index]].w =  mat[i][j+1];
 	          grau[index]++;
 	       }
 	       if(i + 1 < rows){
 	          adj[index][grau[index]].v = ((i+1)*cols) + j;
 	          adj[index][grau[index]].w =  mat[i+1][j];
 	          grau[index]++;
 	       }
 	   
 	   }
}






main(){
int tests;



	scanf("%d",&tests);
	while(tests--){
	      scanf("%d\n%d\n",&rows,&cols);
	      for(int i=0; i<rows; i++)
	         for(int j=0; j<cols; j++)
	             scanf("%d",&mat[i][j]);

	     
	            
	      memset(grau, 0, sizeof(grau));
	      
	      constructGraph();
/*	      for(int i=0; i<(rows*cols); i++)
	         printf("%d ",d[i]);
	      printf("\n");*/
	      dijkstra(0);
	      printf("%d\n",d[(rows*cols)-1]);
	    /*  printf("d= ");
	      for(int i=0; i<(rows*cols); i++)
	         printf("%d ",d[i]);
	      printf("\n");*/

	      /*for(int i=0; i<rows*cols; i++){
	         printf("%d: ",i);
	         for(int j=0; j<grau[i]; j++)
	            printf("%d(%d) ",adj[i][j].v,adj[i][j].w);
	         printf("\n");
	      }*/
	}

}

