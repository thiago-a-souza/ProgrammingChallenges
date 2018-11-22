#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 500

using namespace std;

int adj[MAX][MAX], grau[MAX], p[MAX];
bool used[MAX], visited[MAX];
bool cycle;

void dfs(int s){
int t;

	visited[s] = true;
	for(int i=0; i<grau[s]; i++){
		t = adj[s][i];
		if(!visited[t]){
		   dfs(t);
		   p[t] = s;
		} else if(visited[t] && p[s] >= 0 && p[s] != t){
		          cycle = true;
		        }
		
	}

}

main(){
int n;
char str[MAX];
int len;
int u, v;
int trees, acorns;

	scanf("%d\n",&n);
	while(n--){
	    memset(grau, 0, sizeof(grau));
	    memset(used, 0, sizeof(used));
	    memset(visited, false, sizeof(visited));
	    memset(p, -1, sizeof(p));
	    
	    while(true){
		     cin.getline(str, MAX);
		     len = strlen(str);
		     
		     if(str[0] == '*')
		        break;
		        
		     u = -1;
		     for(int i=0; i<len; i++){
		        if(str[i] >= 'A' && str[i] <= 'Z'){
		           if(u < 0)
		             u = ((int)(str[i])) - 65;
		           else {
		             v = ((int)(str[i])) - 65;
		             break;
		           }
		        }
		     }
		     adj[u][grau[u]++] = v;
		     adj[v][grau[v]++] = u;
		}
		
		cin.getline(str,MAX);
		len = strlen(str);

		for(int i=0; i<len; i++)
		    if(str[i] >= 'A' && str[i] <= 'Z')
		       used[((int)(str[i])) - 65] = true;
		       
		acorns = 0; trees = 0;
		for(int i=0; i<MAX; i++){
		    if(!used[i])
		       continue;
		    if(grau[i] <= 0)
		         acorns++;
		    else if(!visited[i]){
		              cycle = false;
		              dfs(i);
		              if(!cycle)
		                 trees++;
		              
		    }
		   
		}
		
		printf("There are %d tree(s) and %d acorn(s).\n",trees, acorns);
	
	}
}

