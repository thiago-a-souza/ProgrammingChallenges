#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <cmath>

#define MAX 200

using namespace std;

int adj[MAX][MAX];
int grau[MAX], p[MAX];
int visited[MAX];
int nroVert, contRaiz;
set<int> artPoint;
int low[MAX], num[MAX];

void initialize(){
		memset(visited, 0, sizeof(visited));
		memset(grau, 0, sizeof(grau));
		memset(p, -1, sizeof(p));
		contRaiz = 0;
		nroVert = 1;
		artPoint.clear();
}

void findArticulation(int v){
int t;

	visited[v] = 1;
	num[v] = low[v] = nroVert++;

	for(int i=0; i<grau[v]; i++){
	   t = adj[v][i];
	   if(!visited[t]){
	      p[t] = v;
	      if(num[v] == 1)
	        contRaiz++;
	      findArticulation(t);
	      if(low[t] >= num[v] && num[v] != 1)
	         artPoint.insert(v);
	      else if(num[v] == 1 && contRaiz > 1)
	              artPoint.insert(v);
	      low[v] = min(low[v], low[t]);
	   } else if(p[v] != adj[v][i])
	            low[v] = min(low[v], num[t]);
	
	}
}

main(){
char str[1000];
int len, last;
int n, u, v;

	while(true){
	      cin.getline(str,1000);
	      n = atoi(str);

	      if(n == 0)
	        break;

	      initialize();  

	      while(true){
	           cin.getline(str, 1000);
	           len = strlen(str);
	           if(len == 1){
	             u = atoi(str);
	             if(u == 0)
	                break;
	           }
	           last = 0;
	           u = -1;
	           for(int i=0; i<len; i++){
	              if(str[i] == ' ' || str[i] == '	' || i == len-1){
	                 if(u < 0)
	                    u = atoi(&str[last]);
	                 else {
	                    v = atoi(&str[last]);
	                    adj[u][grau[u]++] = v;
	                    adj[v][grau[v]++] = u;
	                 } 
	                 last = i+1;
	                 while(str[last] == ' ' || str[last] == '	')
	                      last++;
	                 i = last-1;
	              } 
	           }
	      }
          for(int i=1; i<=n; i++)
            if(grau[i] > 0 && !visited[i])
               findArticulation(i);
          cout << artPoint.size() << endl;
	               

	}

}

