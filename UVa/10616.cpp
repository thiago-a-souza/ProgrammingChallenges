/* Category: Dynamic Programming (DP) - 0-1 Knapsack */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>


int a[256], n;

using namespace std;


long long solve(int d, int m) {
long long z[256][16][32];
int b[256];

	if (m > n)
		return 0;

	memset(z, 0, sizeof(z));

	for(int i = 0; i <= n; i++)
		z[i][0][0] = 1;

	for(int i = 1; i <= n; i++)
		b[i] = d - (a[i - 1] % d);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int r = 0; r < d; r++)
				z[i][j][r] = z[i - 1][j][r] +
				             z[i - 1][j - 1][(r + b[i]) % d];

	return z[n][m][0];
}

int main(){
int test = 1, q, m, d;



	while(true){
	    scanf("%d %d", &n, &q);
	    if(!n && !q)
	       break;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		printf("SET %d:\n", test++);
		for(int i=1; i<=q; i++){
			scanf("%d %d", &d, &m);
			printf("QUERY %d: %lld\n", i, solve(d, m));
		}
		
	}
}