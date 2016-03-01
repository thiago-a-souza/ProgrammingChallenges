#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000000

using namespace std;

int ladder[MAX], N;

bool isASolution(long long k){
int tmp;

	if(ladder[0] > k)
	   return false;
    if(ladder[0] == k)
       k--;
	for(int i=1; i<N; i++){
	   tmp = ladder[i] - ladder[i-1];
	   if(tmp > k)
	      return false;
	   if(tmp == k)
	      k--;
	}	
	return true;
}


main(){
int T, line = 1;
long long mid, left, right;

	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0; i<N; i++){
		    scanf("%d",&ladder[i]);
		}
		left = 0; right = 1000000000;
		
		while(right - left > 1){ 
		 	mid = (left + right)/2;
		 	if(isASolution(mid))
		 	   right = mid;
		 	else
		 	   left = mid;
		}
		printf("Case %d: %lld\n",line++,right);
		
	}
}

