/* Combinations */
/* Category: math combinatorics */
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


int main(){
int i, j;
int n, m, d1, d2, lim_sup, lim_inf;
int numerador[110], denominador[110];
long long ans, den_s;

	while(true){
	    scanf("%d %d",&n, &m);
		if(!n || !m)
		   break;
		d1 = n - m;
		
		lim_sup = MAX(d1,m);
		lim_inf = MIN(d1,m);

		for(i=0, j=n; j>lim_sup; i++,j--){
		  numerador[i] = j;
		}
		
		for(i=0, j=lim_inf; j>1; i++,j--){
		  denominador[i] = j;
		}
		
		den_s = 1;
		for(i=0; i<lim_inf-1; i++){
		   j = 0;
		   while(j<(n-lim_sup) && numerador[j]%denominador[i] != 0){
		         if(den_s > 1 && numerador[j]%den_s ==0){
		            numerador[j] = numerador[j]/den_s;
		            den_s = 1;
		         }
		         else if(den_s > 1 && den_s%numerador[j] == 0){
		                 den_s = den_s/numerador[j];
		                 numerador[j] = 1;
		              }
		         j++;
		   }
		   if(j<(n-lim_sup) && numerador[j]%denominador[i] == 0){
//		   cout << "num " << numerador[j] << " den "<< denominador[i] << endl;
		      numerador[j] = numerador[j]/denominador[i];
		      denominador[i] = 0;
//		      cout << "->num " << numerador[j] << " den "<< denominador[i] << endl;
		   }
		   else den_s *= denominador[i];
		}
		ans = 1;
		for(i=0; i<(n-lim_sup); i++)
		   ans *= numerador[i];
		ans = ans/den_s;
	    printf("%d things taken %d at a time is %llu exactly.\n",n,m,ans);
	
	}

}




