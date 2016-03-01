/* Ones */
/* Category: math modulo modulus */
/* Trick: modulo magic */
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

using namespace std;

main(){
int ones, n, v;

	while(scanf("%d",&n) == 1){
		ones = 1;
		v = 1;
		while(true){
			if(v < n){
				v = v*10 + 1;
				ones++;
			}
			v = v%n;
			if(v == 0)
			  break;
		}
		cout << ones << endl;

	}
}



