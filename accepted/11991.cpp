#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

#define MAXV 100005

using namespace std;

main(){
vector<int> adj[MAXV];
map<int, int> m;
int N, M, V, K;
int id;
int aux;
	while(scanf("%d %d",&N,&M) != EOF){
	      for(int i=0; i<MAXV; i++)
	          adj[i].clear();
	      m.clear();
	      id = 1;

		  for(int i=1; i<=N; i++){
		  	 scanf("%d",&V);
		  	 if(m[V] == 0)
		  	    m[V] = id++;
		  	 aux = m[V];
		  	 adj[aux].push_back(i);
		  }
		  
		  for(int i=0; i<M; i++){
		  	  scanf("%d %d",&K,&V);
		  	  aux = m[V];
		  	  if(adj[aux].size() == 0 || K > adj[aux].size())
		  	     printf("0\n");
		  	  else
		  	     printf("%d\n",adj[aux][K-1]);
		  }
	}
}