/* f91 - 10/09/2007 */
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
unsigned long long int n;

	while(true){
		scanf("%llu",&n);
		if(n == 0)
		  break;
		if(n <= 100)
		  printf("f91(%llu) = 91\n",n);
		else
		  printf("f91(%llu) = %llu\n",n,n-10);
	}

}



