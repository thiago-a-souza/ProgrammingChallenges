/* Wormholes - 27/08/2007 */
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
#define MAX_V 2001
#define MAX_A 2001
#define INF 10000000 
            
#define PRINT(x)
const double PI = acos(-1.0); 

using namespace std;

typedef struct{
int v; // vértice
int w; // peso
} TAdj;

TAdj adj[MAX_V][MAX_V];

int grau[MAX_V];
int d[MAX_V];


bool bellmanFord(int inicial, int n){

//	memset(p, -1, sizeof(p));
	REP(i, n)
	   d[i] = INF;
	d[inicial] = 0;
	REP(i, n)// todos vertices
	   REP(j, n)     /*        todas                */
	      REP(k, grau[j])/*	      arestas			  */
	      	if(d[j] + adj[j][k].w < d[adj[j][k].v]){
	      	  d[adj[j][k].v] = d[j] + adj[j][k].w;
//	      	  p[adj[j][k].v] = j;
	      	}
	REP(i, n)
	   REP(j, grau[j])
	      if(d[adj[i][j].v] > d[i] + adj[i][j].w)
	        return false;
	return true;
}


main(){
int t, n, m;
int x, y, w;

	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		memset(grau, 0, sizeof(grau));
		REP(i, m){
		   scanf("%d %d %d",&x,&y,&w);
//		   adj[x][y] = w;
		   adj[x][grau[x]].v = y;
		   adj[x][grau[x]++].w = w;
		}
		if(bellmanFord(0,n))
		   cout << "not possible\n";
		else
		   cout << "possible\n";

	}


}
