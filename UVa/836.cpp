/* Largest Submatrix - 04/02/2008 */
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

int mat[30][30], n;
int sum[30][30][30];

int maxSum(){
int biggest, tmp;

	f(i, n)
	  f(j,n)
	    sum[i][i][j] = 0;

	biggest = 0;
	  
	f(i, n)
	 ff(j, i, n){
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

main(){
char str[30];
int t;
		scanf("%d",&t);
		cin.getline(str,30);
		while(t--){
			  cin.getline(str,30);
			  cin.getline(str,30);
			  n = strlen(str);
			  f(i, n)
			   if(str[i] == '0')
			     mat[0][i] = -30;
			   else
			     mat[0][i] = 1;
			  ff(i, 1, n){
			    cin.getline(str,30);
			    f(j, n){
			      if(str[j] == '0')
			        mat[i][j] = -30;
			      else
			        mat[i][j] = 1;			        
			    }
			  }
			  printf("%d\n",maxSum());
			  if(t - 1 >= 0)
			    cout << endl;
		}
}



