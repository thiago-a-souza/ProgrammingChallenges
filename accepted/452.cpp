#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAXL 1000
#define MAXV 30
#define INF 9999999

using namespace std;


int adj[MAXV][MAXV], grau[MAXV], d[MAXV];
int weights[MAXV];
int indegree[MAXV];
queue<int> L;

void readLine(char *str, int len){
int u, v;

	for(int i=0; i<len; i++)
	   if(str[i] >= 'A' && str[i] <= 'Z'){
	      v = ((int)str[i]) - 65;
	      break;
	   }
	for(int i=1; i<len; i++)
	   if(str[i] >= '0' && str[i] <= '9'){
	      weights[v] = atoi(&str[i]);
	      break;
	   } 
	for(int i=len-1; i>0; i--){
	   if(str[i] >= 'A' && str[i] <= 'Z'){
	      u = ((int)str[i]) - 65;
	      adj[u][grau[u]++] = v;
	   } else {
	      break;
	   }
	}
}

void topological_sort(){
queue<int> z;
int v, w;

	memset(indegree, 0, sizeof(indegree));
	for(int i=0; i<MAXV; i++)
	   if(grau[i])
	     for(int j=0; j<grau[i]; j++)
	        indegree[adj[i][j]]++;
	for(int i=0; i<MAXV; i++)
	   if( grau[i] && !indegree[i])
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

void dijkstra(int inicial){
priority_queue< pair<int, int> > heap;
int s, t, peso;



	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
	     s = heap.top().second;
	     heap.pop();
	     for(int i=0; i<grau[s]; i++){
	         t = adj[s][i];
	         peso = -weights[s];
	         if(d[s] + peso < d[t]){
	            d[t] = d[s] + peso;
	            heap.push(make_pair(-d[t], t));
	         }
	     }
	     
	}
}

main(){
int tests;
char str[MAXL];
int len, maxlen;
int v;
bool first = true;

	scanf("%d\n",&tests);
	while(tests--){
      	 memset(grau, 0, sizeof(grau));
      	 memset(weights, 0, sizeof(weights));
      	 for(int i=0; i<MAXV; i++)
	         d[i] = INF; 
	     if(first)
	        first = false;
	     else
	        printf("\n");
	     while(true){
		      cin.getline(str, MAXL);
		      len = strlen(str);
		      if(len == 0)
		         break;		    
		      readLine(str, len);  
		 }
		 
		 topological_sort();
		 
		
	    
		 while(!L.empty()){
		 	v = L.front();	L.pop();
		 	if(d[v] < INF)
		 	   continue;
		 	dijkstra(v);
		 }
		 maxlen = 0;
		 for(int i=0; i<MAXV; i++)
		    if(d[i] < INF){
		      d[i] = (-d[i]) + weights[i];
		      if(d[i] > maxlen)
		        maxlen = d[i]; 
		    }
		 printf("%d\n",maxlen);		 
	}
}

