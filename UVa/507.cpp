/* Jill Rides Again - 13/09/2007 */
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

main(){
int t, n, a[20005];
int iniciot, inicio, fim, y, m;
int ite = 1;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0; i<n-1; i++)
		   scanf("%d",&a[i]);
	
		iniciot = inicio = fim = 0; y = m = 0;
		for(int i=0; i<n-1; i++){
			y = y + a[i];
			if(y < 0){
			  iniciot = i+1;
			  y = 0;
			  continue;
			}
			if(y > m){
			  m = y;
			  inicio = iniciot;
			  fim = i+1;
			  continue;
			}
			else if(y == m)
			       if(fim - inicio < i+1-iniciot){
			         inicio = iniciot;
				    fim = i+1;
				  }	
		}
		if(m == 0)
		  printf("Route %d has no nice parts\n",ite);
		else
		  printf("The nicest part of route %d is between stops %d and %d\n", ite, inicio+1, fim+1);
		ite++;
	}		
}			


