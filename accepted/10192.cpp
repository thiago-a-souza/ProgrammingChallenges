/* Vacation - 11/02/2008 */
/* Category: dynamic programming lcs */

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
#define MAX_V 500

using namespace std;

int table[MAX_V][MAX_V];
char a[MAX_V], b[MAX_V];

int lcs(){
int m, n;

	m = strlen(a);
	n = strlen(b);
	f(i, m)
	  f(j, n)
	      table[i][j]=0;
//	cout << " a => " << a << endl;
//	cout << " b => " << b << endl;
	ff(i, 1, m+1){
	   ff(j, 1, n+1)
	      if(a[i-1] == b[j-1]){
	        table[i][j] = table[i-1][j-1]+1;
	       // cout << a[i-1] << " = " << b[j-1] << " i = " << i << " j = " << j << endl;
	      }
	      else
	        table[i][j] = MAX(table[i][j-1], table[i-1][j]);
	}
	return table[m][n];
}

int main(){
int ite=1;

	while(true){
		cin.getline(a,MAX_V);
		int i=0;
		while(a[i] == ' ')
		      i++;
		
		if(a[i] == '#')
		   return 0;
		cin.getline(b,MAX_V);
		printf("Case #%d: you can visit at most %d cities.\n",ite,lcs());
		ite++;
	}

}




