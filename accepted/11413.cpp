#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000000

using namespace std;

long long N, M;
long long a[MAX], ans[MAX];

bool isASolution(long long p, long long k){
int cnt;

	cnt = 0;
	for(int i=N-1; i>=0; i--){
	   if(a[i] > p)
	      return false;
	      
	   if(cnt + a[i] > p){
	      cnt = 0;
	      if(--k <= 0)
	         return false;
	   }
	   ans[i] = k;
	   cnt += a[i];
	}
	
	return true;
	
	
}

main(){
long long left, mid, right;
long long cnt, maxval;
bool b;

	while(scanf("%lld %lld",&N,&M) != EOF){
	     
		 for(int ii=0; ii<N; ii++)
		    scanf("%lld",&a[ii]);
		
		    
		 left = 0; right = 9223372036854775807L;
		                   
		 while(right - left > 1){ 
		 	mid = (left + right)/2;
		 	if(isASolution(mid, M))
		 	   right = mid;
		 	else
		 	   left = mid;
		 }
        
         
		 cout << right << endl;
		    

		
	}
}