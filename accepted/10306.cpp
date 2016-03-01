/* Category: Dynamic Programming (DP) - Coin Change */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define MAX 1000
#define INF 99999999

using namespace std;

int min(int x, int y){
	if(x < y)
	   return x;
	return y;
}




main(){
int N, M, S;
int a[MAX], b[MAX];
int minCoins[MAX][MAX];
int sq, ans;

	scanf("%d",&N);
	while(N--){
	    scanf("%d %d",&M, &S);
		for(int i=0; i<M; i++)
		   scanf("%d %d",&a[i],&b[i]);

		for(int i=0; i<=S; i++)
		   for(int j=0; j<=S; j++)
		       minCoins[i][j] = INF;

		minCoins[0][0] = 0;

		for(int i=0; i<M; i++)
		   for(int j=a[i]; j<=S; j++)
		      for(int k=b[i]; k<=S; k++)
		         minCoins[j][k] = min(minCoins[j][k], 1 + minCoins[j-a[i]][k-b[i]]);
		sq = S*S;
		ans = INF;
		for(int i=0; i<=S; i++)
		   for(int j=0; j<=S; j++)
		      if(i*i + j*j == sq)
		         ans = min(ans, minCoins[i][j]);
		if(ans == INF)
		  printf("not possible\n");
		else
		  printf("%d\n",ans);
	
		
	}
}

