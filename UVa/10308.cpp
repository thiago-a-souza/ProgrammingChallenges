#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 10001
#define MAXV 50001
#define MAXE 500

#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef struct {
int edge, weight;
} TAdj;

TAdj adj[MAXV][MAXE];
int grau[MAXV];
int solution;

int dfs(int u, int parent){
int maxWeight = 0, auxWeight, v, w;

	for(int i=0; i<grau[u]; i++){
	    v = adj[u][i].edge;
	    w = adj[u][i].weight;
	    
	    if(v != parent){
	       auxWeight = w + dfs(v, u);
	      
	       if(auxWeight + maxWeight > solution)
	          solution = auxWeight + maxWeight;
	       
	       if(auxWeight > maxWeight)
	          maxWeight = auxWeight; 
	    }
	}
	return maxWeight;
}

int main(){
char line[MAX];
int len;
int s, t, w;
	while(cin.getline(line, MAX)){
	      memset(grau, 0, sizeof(grau));
	      while(sscanf(line, "%d %d %d", &s, &t, &w) == 3){
	           adj[s][grau[s]].edge = t;
	           adj[s][grau[s]].weight = w;
	           adj[t][grau[t]].edge = s;
	           adj[t][grau[t]].weight = w;
	           grau[s]++; grau[t]++;
	           cin.getline(line, MAX);
	      }
	      
	      solution = 0;
	      dfs(1, -1);
	      cout << solution << endl;
	      
	}
	return 0;
}

