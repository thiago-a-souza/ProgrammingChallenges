#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000

using namespace std;

long long M;
long long pages[MAX];
long long ans[MAX];



bool isASolution(long long p, int k, bool print){
int cnt;

	cnt = 0;
	for(int i=M-1; i>=0; i--){
	   if(pages[i] > p)
	      return false;
	      
	   if(cnt + pages[i] > p || i+1 < k){
	      cnt = 0;
	      if(--k <= 0)
	         return false;
	   }
	   ans[i] = k;
	   cnt += pages[i];
	}
	if(print){
        for(int i = 0; i<M; i++) {
           if(i != 0) {
             if(ans[i-1] != ans[i])
				printf(" / ");
             else
				printf(" ");
           }
		   printf("%lld", pages[i]);
        }
		printf("\n");
    }
	return true;
}



main(){
long long left, right,  mid;
long long N, K;

	scanf("%lld",&N);
	while(N--){
		scanf("%lld %lld",&M,&K);

		for(int i=0; i<M; i++)
		   scanf("%lld",&pages[i]);
		
		
		left = 0; right = 6000000000LL;
		while(right - left > 1){
		    mid = (left + right)/2;
		    if(isASolution(mid, K, false))
		       right = mid;
		    else
		       left = mid;
		}
		isASolution(right, K, true);
		
		
		
		
		
		
	}
	
	
}
