#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>

#define MAX 10000
#define MAXBUTTONS 11
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int adj[MAX][MAX], grau[MAX];
bool mat[MAX][MAX];
int d[MAX], visited[MAX];
int button[MAXBUTTONS];
int L, U, R;

void buildGraph(int s){
int t;

	for(int i=0; i<R; i++){
	    t = (s + button[i])%10000;
	    if(mat[s][t] == 0){
	       mat[s][t] = 1;
	       adj[s][grau[s]++] = t;
	       buildGraph(t);
	    }
	}
}

void bfs(int inicio){
int s, t;
queue<int> Q;

	memset(visited, 0, sizeof(visited));
	d[inicio] = 0;
	visited[inicio] = 1;
	
	Q.push(inicio);
	while(!Q.empty()){
	      s = Q.front();
	      Q.pop();
	      for(int i=0; i<grau[s]; i++){
	         t = adj[s][i];
	         if(visited[t] == 0 ){
	            visited[t] = 1;
	            d[t] = d[s] + 1;
	            Q.push(t);
	         }
	      }
	}
}

int main(){
int line = 1;

	while(true){
	     scanf("%d %d %d", &L, &U, &R);
	     if(L == 0 && U == 0 && R == 0)
	        break;
	     for(int i=0; i<R; i++) 
	        scanf("%d", &button[i]);

	     memset(grau, 0, sizeof(grau));	     
	     memset(mat, 0, sizeof(mat));
	     buildGraph(L);
	     bfs(L);
	     
	     if(!visited[U])
	        printf("Case %d: Permanently Locked\n", line++);
	     else 
	        printf("Case %d: %d\n", line++, d[U]);
	}
	return 0;
}

