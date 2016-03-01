#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAXV 10000
#define MAXE 100

using namespace std;

int adj[MAXV][MAXE], grau[MAXV];
bool visited[MAXV];
int N, M, L;

void dfs(int s){
int t;

      visited[s] = true;
      for(int i=0; i<grau[s]; i++){
         t = adj[s][i];
         if(!visited[t])
            dfs(t);     
      } 
}

int main(){
int tests;
int x, y;
int ans;
	scanf("%d",&tests);
	while(tests--){
	      scanf("%d %d %d", &N, &M, &L);
	      memset(grau, 0, sizeof(grau));
	      memset(visited, 0, sizeof(visited));
	      for(int i=0; i<M; i++){
	          scanf("%d %d",&x, &y);
	          adj[x][grau[x]++] = y;
	      }
	      for(int i=0; i<L; i++){
	         scanf("%d",&x);
	         if(!visited[x]){
	            dfs(x);
	         }
	      }
	      ans = 0;
	      for(int i=1; i<=N; i++)
	          if(visited[i])
	             ans++;
	      printf("%d\n", ans);
	      
	}
	return 0;
}

