#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>

#define MAXV 100000
#define MAXE 500

using namespace std;

int adj[MAXV][MAXE];
int grau[MAXV], visited[MAXV], p[MAXV];
bool used[MAXV];

void dfs(int s){
int t;

	visited[s] = 1;
	for(int i=0; i<grau[s]; i++){
	    t = adj[s][i];
	    if(!visited[t]){
	       dfs(t);
	    }
	}
}

int main(){
int u, v, root, id;
map<int, int> dic;
bool valid;
int line = 1;
	while(true){
	      scanf("%d %d", &u, &v);
	      
	      if(u == -1 && v == -1) 
	         break;
	      
	      if(u == 0 && v == 0){
	          printf("Case %d is a tree.\n", line++);
	          continue;
	      }
	      memset(grau, 0, sizeof(grau));
	      memset(p, -1, sizeof(p));
	      memset(used, 0, sizeof(used));
	      memset(visited, 0, sizeof(visited));
	      valid = true;
	      dic.clear();
	      id = 0;
	      
	      dic[u] = id++;
	      if(dic.count(v) <= 0)
	         dic[v] = id++;
	      
	      u = dic[u];
	      v = dic[v];   
	         
	      adj[u][grau[u]++] = v;
	      p[v] = u;
	      used[u] = used[v] = true;
	      
	      

	         
	      while(true){
	            scanf("%d %d", &u, &v);
	            if(u == 0 && v == 0)
	               break;
	               
	            if(dic.count(u) <= 0)
	               dic[u] = id++;
	            if(dic.count(v) <= 0)
	               dic[v] = id++;
	            
	            u = dic[u];
	            v = dic[v];
	            
	            adj[u][grau[u]++] = v;
	            used[u] = used[v] = true;
	            if(p[v] >= 0)
	               valid = false;
	            p[v] = u;
	      }
	      
	      if(!valid)
	         printf("Case %d is not a tree.\n", line++);
	      else {
	         root = -1;
	         for(int i=0; i<MAXV && valid; i++)
	            if(used[i] && p[i] == -1){
	               if(root >= 0){
	                  valid = false;
	                  break;
	               } else {
	                  root = i;
	               }
	            }
	         if(!valid)
	            printf("Case %d is not a tree.\n", line++);
	         else {
	            dfs(root);
	            for(int i=0; i<MAXV && valid; i++)
	               if(used[i] && !visited[i]){
	                  valid = false;
	                  break;
	               }
	            if(!valid)
	              printf("Case %d is not a tree.\n", line++);
	            else
	              printf("Case %d is a tree.\n", line++);
	         }
	      }
	}
	return 0;
}

