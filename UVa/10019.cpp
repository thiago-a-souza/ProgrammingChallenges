/* Funny Encryption Method - 22/01/2008 */
/* Category: math - base change */
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
#define debug(x) x


using namespace std;

int countBin(int val){
int sum;

	sum = 0;
	while(val>0){
	     if(val%2 != 0)
	        sum++;
	     val /= 2;
	}
	return sum;

}


main(){
char  val[30];
int n, hexa, sum, b1, b2;

	while(scanf("%d",&n) == 1){
	
	     f(t,n){
	         scanf("%s",val);
			 b1 = countBin(atoi(val));
			 hexa = 1;
			 sum = 0;
			 for(int i=strlen(val)-1; i>=0; i--){
			 	sum += hexa*((int)val[i]-48);
			 	hexa = hexa*16;
			 }
			 b2 = countBin(sum);
			 cout << b1 << " " << b2 << endl;
		 }
	
	}
	


}


