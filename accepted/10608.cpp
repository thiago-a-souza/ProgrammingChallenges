#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAXV 30001
#define MAXE 15000

using namespace std;

int adj[MAXV][MAXE];
int grau[MAXV];
int visited[MAXV];
int cont;

void dfs(int s){
int t;

	visited[s] = 1;
	cont++;
	for(int i=0; i<grau[s]; i++){
	   t = adj[s][i];
	   if(visited[t] == 0)
	      dfs(t);
	   
	}
}


main(){
int T, N, M;
int x, y, max_cont;
bool contain;
		scanf("%d",&T);
		while(T--){
		     memset(grau, 0, sizeof(grau));
		     memset(visited, 0, sizeof(visited));
             scanf("%d %d",&N, &M);
             for(int i=0; i<M; i++){
                 scanf("%d %d",&x,&y);
                 contain = false;
                 for(int i=0; i<grau[x]; i++){
                    if(adj[x][i] == y){
                      contain = true;
                      break;
                    }
                 }
                 if(!contain){
                   adj[x][grau[x]++] = y;
                   adj[y][grau[y]++] = x;
                 }
             }
                          
             max_cont = 0;
             for(int i=1; i<=N; i++){
                cont = 0;
                if(grau[i] > 0 && visited[i] == 0)
                   dfs(i);
                if(cont > max_cont)
                   max_cont = cont;
             }
             
             printf("%d\n",max_cont);
		}
}

