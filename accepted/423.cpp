/* MPI Maelstrom 14/11/2007 */
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
#include <climits>

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
#define INF 320000 //INT_MAX/2
#define PRINT(x)
const double PI = acos(-1.0); 

using namespace std;

int adj[MAX_V][MAX_V], n;

void floyd(){

	REP(k, n)
	   REP(i, n)
	      REP(j, n)
	         if(adj[i][k] + adj[k][j] < adj[i][j])
	            adj[i][j] = adj[i][k] + adj[k][j];
	         
}

main(){
int nivel, tmp, max;
char buff[30];

	while(scanf("%d",&n) == 1){
	    nivel = 1;

	    REP(i,n) REP(j,n) adj[i][j] = 0;
	    
	    FOR(i, 1, n){
	       REP(j, nivel){
	          scanf(" %s",buff);
	          if(buff[0]=='x'){
	            adj[i][j] = INF;
	            adj[j][i] = INF;
	          }
	          else{
	            tmp = atoi(buff);
	            adj[i][j] = tmp;
	            adj[j][i] = tmp;
	          }
	       }
	       nivel++;
	    }
	    floyd();
	    max = 0;
	    REP(i, n)
	        if(adj[0][i] > max)
	           max = adj[0][i];
	    printf("%d\n",max);
	          	    
	}

}


