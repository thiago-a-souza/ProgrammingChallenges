#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>

#define MAX 27000

int adj[MAX][1000], grau[MAX], p[MAX];
int visited[MAX];
char dic[MAX][20];
int len[MAX];

using namespace std;

void bfs(int inicio){
int s, t;
queue<int> Q;

	memset(visited, 0, sizeof(visited));
	memset(p, -1, sizeof(p));
	visited[inicio] = 1;
	Q.push(inicio);
	while(!Q.empty()){
	     s = Q.front();
	     Q.pop();
	     for(int i=0; i<grau[s]; i++){
	        t = adj[s][i];
	        if(visited[t] == 0){
	           visited[t] = 1;
	           p[t] = s;
	           Q.push(t);
	        }
	     }
	      
	}

}

bool isDoublet(int a, int b){
int diffs = 0;

	for(int i=0; i<len[a]; i++)
	   if(dic[a][i] != dic[b][i]){
	      diffs++;
	      if(diffs > 1)
	         return false;
	   }
	return true;
}

void showPath(int a){
   if(p[a] == -1)
     printf("%s\n",dic[a-1]);
   else {
      showPath(p[a]);
      printf("%s\n",dic[a-1]);
   }
}


main(){
int u, v;
int words_nbr = 0;
char s1[20], s2[20];
bool first = true;
map<string, int> dic_map;


    memset(dic,'\0',sizeof(dic));
	while(true){
	     
	     cin.getline(dic[words_nbr], MAX);
	     len[words_nbr] = strlen(dic[words_nbr]);
	     if(len[words_nbr]  == 0)
	        break;
	     dic_map[dic[words_nbr]] = words_nbr + 1;
	     words_nbr++;
	}
	
	memset(grau, 0, sizeof(grau));
	for(int i=0; i<words_nbr; i++){
	    for(int j=i+1; j<words_nbr; j++){
	        if(len[i] == len[j] && isDoublet(i,j) ){
	           u = dic_map[dic[i]]; 
	           v = dic_map[dic[j]];
	           adj[u][grau[u]++] = v; 
	           adj[v][grau[v]++] = u;
	        }
	    }
	}
	
	while(scanf("%s %s",s1, s2) != EOF){
	      u = dic_map[s1]; 
	      v = dic_map[s2];
	     if(first)
	        first = false;
	     else
	        printf("\n");
	        
	     if(u == 0 || v == 0)
	        printf("No solution.\n");
	     else {
	        bfs(u);
	        if(visited[v]){
	          showPath(v);
	        }
	        else
	          printf("No solution.\n");
	     }
	     
	}
}

