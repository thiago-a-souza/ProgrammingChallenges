#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

main(){
int t, n;
int v[100], diffs;

	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n);
	    for(int i=0; i<n; i++)
	       scanf("%d",&v[i]);
	    qsort(v, n, sizeof(int), cmp);
	    diffs = 0;
	    for(int i=1; i<n; i++)
	       diffs += (v[i] - v[i-1]);
	    printf("%d\n",diffs*2);
	}

}

