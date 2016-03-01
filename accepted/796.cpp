/* Critical Links - 22/08/2007 */

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

#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define MP(a,b) make_pair((a),(b))
#define ALL(c) (c).begin(),(c).end()
#define FOR(i,v,n) for(int i=v; i<n; i++)
#define FORD(i,v,n) for(int i=(n-1); i>=v; i--)
#define REP(i,n) FOR(i,0,n)
#define REPD(i,n) FORD(i,0,n)
#define PB push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define MAX_V 101
#define MAX_A 101
#define INF 10e9
#define PRINT(x)
const double PI = acos(-1.0); 

using namespace std;

int visited[MAX_V], visitMain[MAX_V], low[MAX_V], num[MAX_V];
int p[MAX_V];

int nroVert, contRaiz;
vector< pair<int,int> > bridge;
int adj[MAX_V][MAX_A], grau[MAX_V];

void clearBufferArticulation(){

	memset(visited, 0, sizeof(visited));
	memset(p, -1, sizeof(p));
	nroVert = 1;
	
}


void findArticulation(int v){
int t;
    visited[v] = visitMain[v] = 1;
    num[v] = low[v] = nroVert++;
    REP(i, grau[v]){
       t = adj[v][i];
       if(!visited[t]){
         p[t] = v;
         findArticulation(t);
         if(low[t] > num[v])
           if(v < t)
              bridge.PB(MP(v, t));
           else
              bridge.PB(MP(t, v));
         low[v] = MIN(low[v],low[t]);
       }
       else if(p[v] != adj[v][i])
               low[v] = MIN(low[v],num[t]);
    
    }
}

void show(){

	REP(i, MAX_V){
	   if(grau[i] > 0) cout << i << "-> ";
	   REP(j, grau[i])
	   	 cout << adj[i][j] << " ";
	   if(grau[i]>0)
	   cout << endl;
	}
}

void readFuckingInput(int n){
int u, v, nar;
int nn;
	nn = n;
	while(nn--){
	     scanf("%d (%d)",&u,&nar); 
	     REP(i, nar){
	        scanf("%d",&v);
	        adj[u][grau[u]++] = v;
		}	     
	}
}

main(){
int n;

	while(cin >> n){
		memset(grau, 0, sizeof(grau));
		memset(visitMain, 0, sizeof(visitMain));
		bridge.clear();
		readFuckingInput(n); PRINT(cout << n << endl; show();)
		REP(i, n)
		   if(grau[i] > 0 && !visitMain[i]){
		     clearBufferArticulation();
		     findArticulation(i);
		     }
		printf("%d critical links\n", bridge.size());
		sort(bridge.begin(), bridge.end());
		REP(i, bridge.size())
		   printf("%d - %d\n",bridge[i].first,bridge[i].second);
		printf("\n");
		bridge.clear();
		
	}

}

