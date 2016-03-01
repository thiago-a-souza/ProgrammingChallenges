/* All Squares - 15/11/2007 */
/* Categoria: Ad Hoc */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack> 
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

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

int sum;
int px, py;

void backtrack(int k, int x, int y){

	if(k > 0){
	  if(px <= x+k && py <= y+k && px >= x-k && py >= y-k)
	     sum++;
	  backtrack(k/2, x-k, y-k);
	  backtrack(k/2, x+k, y-k);
	  backtrack(k/2, x-k, y+k);
	  backtrack(k/2, x+k, y+k);
	}


}

main(){
int k;

	while(true){
	     scanf("%d %d %d",&k, &px, &py);

	     if(!k && !px && !py)
	        return 0;

	     sum = 0;
	     backtrack(k, 1024, 1024);
	     printf("%3d\n",sum);
	}

}



