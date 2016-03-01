#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAX 50005

using namespace std;

int adj[MAX], d[MAX], stack[MAX];
int cycle, last, top;
bool stacked[MAX];

void dfs(int u){
	d[u] = ++cycle;
	stack[top++] = u;
	stacked[u] = true;
	if(d[adj[u]] == 0)
	   dfs(adj[u]);
	else
	   last = adj[u];
}

main(){
int tests, N;
int u, v;
int maxsz, index;
int line = 1;

	scanf("%d",&tests);
	while(tests--){
	    scanf("%d",&N);
	    for(int i=0; i<N; i++){
		   scanf("%d %d",&u,&v);
		   adj[u] = v;
	    }
		memset(d, 0, sizeof(d));
		
		for(int i=1; i<=N; i++){
			if(d[i] > 0)
			   continue;
			cycle = 0; last = 0; top = 0;
			dfs(i);
			cycle = d[last];
			
			if(stacked[last]){
			   cycle = d[stack[top - 1]] - d[last] + 1;
			   while(true){
			   		d[stack[--top]] = cycle;
			   		stacked[stack[top]] = false;
			   		if(stack[top] == last)
			   		   break;
			   }
			}
			for(int j=1; top >= 1; j++){
				d[stack[--top]] = j + cycle;
				stacked[stack[top]] = false;
			}
			
		}
		maxsz = -1;
		for(int i=1; i<=N; i++)
		   printf("%d ",d[i]);
		printf("\n");
		for(int i=1; i<=N; i++)
		   if(d[i] > maxsz){
		      maxsz = d[i];
		      index = i;
		   }
		printf("Case %d: %d\n",line++,index);
		
		
		
		
	}

}

