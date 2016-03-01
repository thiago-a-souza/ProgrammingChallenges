/* Power Crisis */
/* Category: ad hoc simulation */

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
#define VALUE 12
using namespace std;

int n;

bool power(int gap){
int region[100], total;
int shut = 0, count = gap-1;

	memset(region, 0, sizeof(region));
	total = n;

	while(shut != VALUE){
		 f(i, n){
		   if(region[i] == 0)
		      count++;
		   if(count == gap && region[i] == 0){
		      shut = i;
		      region[i] = -1;
		      count = 0;
		      total--;
		      if(shut == VALUE)
		        break;
		   }
		 }

	}
	if(total == 0)
	  return true;
	return false;


}


main(){
int i=1;

	while(true){
		scanf("%d",&n);
		if(n == 0) break;
		while(!power(i))
			 i++;
		cout << i << endl;
		i = 1;
	}


}
