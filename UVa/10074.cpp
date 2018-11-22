/* Take the Land - 05/02/2008 */
/* Category: Dynamic Programming */
/* Solution: create n tables (sum[i][j][k]), accumulate values for each column k from i'th line (line == id Table) to j'th line. Then use max sum algorithm in line */

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

int mat[100][100], m, n;
int sum[100][100][100];

int maxSum(){
int biggest, tmp;

	f(i, m)
	  f(j,n)
	    sum[i][i][j] = 0;

	biggest = 0;
	  
	f(i, m)
	 ff(j, i, m){
	   tmp = 0;
	   f(k, n){
	     sum[i][j+1][k] = sum[i][j][k] + mat[j][k];
	     if(sum[i][j+1][k] + tmp > 0){
	       tmp += sum[i][j+1][k];
	       if(tmp > biggest)
	          biggest = tmp;
	     }
	     else tmp = 0;
	   }
	 }
	 return biggest;

}

int main(){

	while(true){
		scanf("%d %d",&m, &n);
		if(!m && !n)
		  return 0;
		f(i, m)
		  f(j, n){
		    scanf("%d",&mat[i][j]);
		    if(mat[i][j] == 1)
		      mat[i][j] = -200;
		    else if(mat[i][j] == 0)
		            mat[i][j] = 1;
		  }
		 printf("%d\n",maxSum());
	
	}


}


