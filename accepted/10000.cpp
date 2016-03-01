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
#include<queue>

#define MAX 200
using namespace std;

int adj[MAX][MAX];
int grau[MAX];
int d[MAX];


void dijkstra(int inicial){
queue<int> Q;
int s, t;

	memset(d, 0, sizeof(d));
	Q.push(inicial);	   
	while(!Q.empty()){
		s = Q.front(); 
		Q.pop();
		for(int i=0; i<grau[s]; i++){
		   t = adj[s][i];
		   if(d[s] + 1 > d[t]){
		      d[t] = d[s] + 1;
		      Q.push(t);
		   }
		}
	}


}

main(){
int N, S;
int p, q;
int vmax, index;
int T = 1;
		while(true){
			scanf("%d",&N);
			if(N == 0)
			   break;
			scanf("%d",&S);
			memset(grau, 0, sizeof(grau));
			while(true){
				scanf("%d %d",&p,&q);
				if(p == 0 && q == 0)
				   break;
				adj[p][grau[p]++] = q;
			}

			dijkstra(S);
			vmax = -1; 
			for(int i=1; i<=N; i++){
			   if(d[i] > vmax){
			     vmax = d[i];
			     index = i;
			   }
			}
			printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",T,S,vmax,index);
			T++;
		}
}

