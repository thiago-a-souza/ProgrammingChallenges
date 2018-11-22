#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

#define MAX 210

using namespace std;

int adj[MAX][MAX], grau[MAX], d[MAX];
int length[MAX];
char word[MAX][11];

void bfs(int inicio){
int s, t;
int visited[MAX];
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
	         if(visited[t] == 0){
	            visited[t] = 1;
	            d[t] = d[s] + 1;
	            Q.push(t);
	         }
	     }
	}

}


bool isNeighbour(int x, int y){
int diffs = 0;

	for(int i=0; i<length[x]; i++){
	   if(word[x][i] != word[y][i]){
	      diffs++;
	      if(diffs > 1)
	         break;
	   }
	}
	if(diffs <= 1)
	   return true;
	return false;
	   
}

main(){
char str[50], a[11], b[11];
int tests, len, sz;
map<string, int> mp;
bool first = true;

		scanf("%d\n\n",&tests);
		while(tests--){
		      sz = 0;
		      memset(grau, 0, sizeof(grau));
		      if(first)
		         first = false;
		      else 
		         printf("\n");
		        
		      while(true){
		           cin.getline(word[sz],11);
		           length[sz] = strlen(word[sz]);
		           if(length[sz] == 1 && word[sz][0] == '*')
		              break;
		           mp[word[sz]] = sz;
		           sz++;
		      }
		      
		      for(int i=0; i<(sz-1); i++)
		         for(int j=i+1; j<sz; j++)
		             if(length[i] == length[j] && isNeighbour(i,j)){
		                adj[i][grau[i]++] = j;
		                adj[j][grau[j]++] = i;
		             }
		      while(true){
		           cin.getline(str, 50);
		           len = strlen(str);
		           if(len == 0)
		              break;
		           memset(a, '\0', sizeof(a));
		           memset(b, '\0', sizeof(b));
		           for(int i=0; i<len; i++){
		               if(str[i] == ' '){
		                  for(int j=0; j<i; j++)
		                      a[j] = str[j];
		                  for(int j=i+1, k=0; j<len; j++, k++)
		                      b[k] = str[j];
		                  break;
		               }
		           }
		           bfs(mp[a]);
		           cout << a << " " << b << " " << d[mp[b]] << endl;
		      }
		}
	
}

