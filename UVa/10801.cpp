#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define debug(x) x
#define MAX 3000
#define INF 9999999
#define GRF 200

typedef struct {
int v, w;
} TAdj;

TAdj adj[MAX][100];

int N, K, T[10];
int grau[MAX], d[MAX];
int v[5][200], v_sz[5];

using namespace std;

void readInput(){
char str[MAX];
int len, index;

	for(int i=0; i<N; i++)
	    scanf("%d", &T[i]);
	cin.getline(str,MAX);
	      

    
	memset(v_sz, 0, sizeof(v_sz));
	      
	for(int i=0; i<N; i++){
	    cin.getline(str, MAX);
	    len = strlen(str);
	    index = 0;
	    while(index < len){
	          v[i][v_sz[i]++] = atoi(&str[index]);
		      while(index < len && str[index] >= '0' && str[index] <= '9')
		            index++;
              while(index < len && !(str[index] >= '0' && str[index] <= '9'))
		            index++;
	    }
    }
}

void constructGraph(){
int aux;

    memset(grau, 0, sizeof(grau));
    
	for(int i=0; i<N; i++){
	   aux = GRF*i;
	   for(int j=0; j<(v_sz[i]-1); j++){
	      adj[v[i][j]+aux][grau[v[i][j]+aux]].v = v[i][j+1]+aux;
	      adj[v[i][j]+aux][grau[v[i][j]+aux]].w = (v[i][j+1] - v[i][j])*T[i];
	      grau[v[i][j]+aux]++;
	     
	      adj[v[i][j+1]+aux][grau[v[i][j+1]+aux]].v = v[i][j]+aux;
	      adj[v[i][j+1]+aux][grau[v[i][j+1]+aux]].w = (v[i][j+1] - v[i][j])*T[i];
	      grau[v[i][j+1]+aux]++;
       }
    }
	 
    for(int t=0; t<(N-1); t++)
	   for(int t2=t+1; t2<N; t2++)
	      for(int i=0; i<v_sz[t]; i++)
	         for(int j=0; j<v_sz[t2]; j++){
	            if(v[t][i] == v[t2][j]){
	               adj[v[t][i] + (GRF*t)][grau[v[t][i] + (GRF*t)]].v = v[t][i] + (GRF*t2);
	               adj[v[t][i] + (GRF*t)][grau[v[t][i] + (GRF*t)]].w = 60;
	               grau[v[t][i] + (GRF*t)]++;
	               
	               adj[v[t][i] + (GRF*t2)][grau[v[t][i] + (GRF*t2)]].v = v[t][i] + (GRF*t);
	               adj[v[t][i] + (GRF*t2)][grau[v[t][i] + (GRF*t2)]].w = 60;
	               grau[v[t][i] + (GRF*t2)]++;
	            }
	         }
}

void dijkstra(int inicial){
priority_queue< pair<int, int> > heap;
int s, t, peso;

	for(int i=0; i<MAX; i++)
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


int calculateOutput(){
int aux, output;

    output = INF;
    
	for(int i=0; i<N; i++){
	    aux = GRF*i;
	    if(grau[aux] > 0){
	      dijkstra(aux);
	      for(int j=0; j<N; j++)
	          if(d[(GRF*j)+K] < output)
	             output = d[(GRF*j)+K];
	    }
	    
	}
	return output;
}



main(){
int res;


	while(scanf("%d %d",&N,&K) != EOF){
          readInput();
          constructGraph();
	      res = calculateOutput();
	      if(res >= INF)
	        printf("IMPOSSIBLE\n");
	      else 
	        printf("%d\n",res);
          
	}
}