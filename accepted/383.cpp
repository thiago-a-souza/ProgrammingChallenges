/* Shipping Routes */
/* Category: graphs bfs */
/* Algorithm: only bfs needed */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack>  

#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define mp(a,b) make_pair((a),(b))
#define all(c) (c).begin(),(c).end()
#define ff(i,v,n) for(int i=v; i<n; i++)
#define f(i,n) ff(i,0,n)
#define pb push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define debug(x)
#define MAX_V 100
#define MAX_A 100

using namespace std;

int adj[MAX_V][MAX_A], grau[MAX_V];
int d[MAX_V], visited[MAX_V];

void bfs(int inicio){ 
int s, t; 
queue<int> Q; 

	memset(visited, 0, sizeof(visited));
	d[inicio] = 0;
	visited[inicio] = 1;
	
	Q.push(inicio); 
	while(!Q.empty()){ 
	      s = Q.front(); 
	      Q.pop(); 
	      f(i, grau[s]) {
		    t = adj[s][i];
		    if(!visited[t]){ 
		      visited[t] = 1; 
		      d[t] = d[s] + 1; 
		      Q.push(t); 
		    } 
	      }
	} 
}

int main(){
int T, M, N, P, count;
int u, v, val, ite=1;
char ch1[10], ch2[10];
map<string,int> names;

	scanf("%d",&T);
	while(T--){

		 scanf("%d %d %d",&M,&N,&P);

		 names.clear(), count = 0;
		 memset(grau, 0 , sizeof(grau));

		 f(i, M){
		   scanf("%s",ch1);
		   names[ch1] = count++;
		 }
		 f(i, N){
		   scanf("%s %s",ch1,ch2);
		   u = names[ch1];
		   v = names[ch2];
		   adj[u][grau[u]++] = v;
		   adj[v][grau[v]++] = u;
		 }
		 if(ite==1)printf("SHIPPING ROUTES OUTPUT\n\n");
		 printf("DATA SET  %d\n\n",ite), ite++;
		 f(i, P){
		   scanf("%d %s %s",&val,ch1,ch2);
		   u = names[ch1], v = names[ch2];
		   bfs(u);
		   if(visited[v])
		      printf("$%d\n",d[v]*100*val);
		   else
		      printf("NO SHIPMENT POSSIBLE\n");
		 }
		 printf("\n");
	}
	printf("END OF OUTPUT\n");
	

}


