/*
Caso todos os vértices tenham grau par o resposta é a soma dos pesos. Caso contrário a 
resposta é a soma dos pesos mais a soma dos pesos do caminho mínimo entre os vértices de 
grau ímpar.
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
#include <climits>

#define MAXV 30
#define MAXE 10000
#define INF 99999999
using namespace std;

typedef struct{
int v, w;
} TAdj;

TAdj adj[MAXV][MAXE];
int grau[MAXV];
int d[MAXV];

void dijkstra(int inicial){
priority_queue< pair< int, int> > heap;
int s, t, peso;

	for(int i=0; i<MAXV; i++)
	   d[i] = INF;
	heap.push(make_pair(d[inicial] = 0, inicial));
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

main(){
char str[MAXE];
int x, y, w;
bool b;
		while(cin.getline(str,MAXE)){
		    
		     
		     if(strcmp(str,"deadend") == 0){
		       b = true;
		       w = 0;
		       for(int i=0; i<MAXV; i++)
		          if(grau[i] > 0 && grau[i]%2 != 0){
		             b = false;
		             break;
		          }

		      for(int i=0; i<MAXV; i++)
		         for(int j=0; j<grau[i]; j++)
		             w += adj[i][j].w;
		      w = w/2;

		       
		       
		   /*    for(int i=0; i<MAXV; i++)
		          if(grau[i] > 0){
		              printf("%d => ",i);
		             for(int j=0; j<grau[i]; j++)
		                printf(" %d(%d)",adj[i][j].v, adj[i][j].w);
		             printf("\n");
		          }*/
		       
		       if(b){
		          printf("%d\n",w);
		       } else {
		          x = -1; y = -1;
		          for(int i=0; i<MAXV; i++)
		              if(grau[i]%2 != 0){
		                if(x < 0)
		                   x = i;
		                else
		                   y = i;
		              }
		          dijkstra(x); 
		           printf("%d\n",w+d[y]);
		       }
		     
		     
		       // 
		       memset(grau, 0, sizeof(grau));
		     } else {
		         w = strlen(str);
		         x = tolower(str[0]) - 'a';
		         y = tolower(str[w-1]) - 'a';
		         //printf("%c => %d, %c => %d\n",str[0], x, str[w-1], y);
		         adj[x][grau[x]].v = y;
		         adj[x][grau[x]].w = w;
		         grau[x]++;
		         adj[y][grau[y]].v = x;
		         adj[y][grau[y]].w = w;
		         grau[y]++;
		     }
		}

}