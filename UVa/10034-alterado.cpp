/* Freckles - 20/08/2007 */
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
#define MAX_A 6000
#define INF 3200000.0
#define PRINT(x)
const double PI = acos(-1.0); 

using namespace std;

typedef struct{
double x, y;
} TPoint;

typedef struct{
int u, v; // u -> v
double w;
} TAdj;

TAdj adj[MAX_A];
int p[MAX_V], nro_arestas;
int  posMst;
double total;

int cmp(const void *a , const void *b){
TAdj *x, *y;

	x = (TAdj*)a; y = (TAdj*)b;
	if(x->w < y->w)
	  return -1;
	if(x->w > y->w)
	  return 1;
	return 0;
}

int findSet(int x){
	if(x != p[x])
	  p[x] = findSet(p[x]);
	return p[x];
}


void kruskal(){
int u, v, u_set, v_set;

	REP(i, MAX_V) // todos vertices
	   p[i] = i;
	qsort(adj, nro_arestas, sizeof(TAdj), cmp);
	posMst = 0;
	REP(i, nro_arestas){
		u = adj[i].u; v = adj[i].v;
		u_set = findSet(u);
		v_set = findSet(v);
		if(u_set != v_set){
		  p[v_set] = p[u_set];
		  mst[posMst++] = adj[i];
		  total += adj[i].w;
		}
	}
}

main(){
int t, n;
TPoint p[101];
TGraph g;
double dist;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		   scanf("%lf %lf",&p[i].x, &p[i].y);
		nro_arestas = 0;
		for(int i=0; i<n-1; i++)
		   for(int j=i+1; j<n; j++){
		      dist = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y));
		      adj[nro_arestas].u = i;
		      adj[nro_arestas].v = j;
		      adj[nro_arestas++].w = dist;
		   }
PRINT(	for(int i=0; i<3; i++)
		   for(int j=0; j<adj[i].size(); j++)
		      cout << i << " " << adj[i][j].v << " " << adj[i][j].w << endl; )
		kruskal();
		printf("%.2lf\n",total);
		for(int i=0; i<=n; i++)
		   adj[i].clear();
		if(t-1>=0)
		  printf("\n");
		
	}


}


