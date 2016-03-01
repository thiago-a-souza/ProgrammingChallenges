/* Category: Dynamic Programming - DP */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000
using namespace std;

int memo[MAX][MAX];

int sums(int n, int k){

	if(n == 0 || k == 1)
	   return 1;
	if(memo[n][k] > 0)
	   return memo[n][k];
	for(int i=0; i<=n; i++)
	   memo[n][k] = (memo[n][k] + sums(n-i, k-1))%1000000;
	return memo[n][k];
}

main(){
int n, k;

	while(true){
		scanf("%d %d",&n,&k);
		if(!n && !k)
		   break;
		memset(memo, 0, sizeof(memo));
		cout << sums(n,k) << endl;
	}
}

