/* SuperSale - 12/07/2007 */
#include <stdio.h>

int c[1001][31];
int weight[1001], price[1001];

int max(int a, int b){

	if(a>b)
	   return a;
	return b;

}

void knapsack(int n){
register int i, j;

	for(i=0; i<=n; i++)
	   c[i][0] = 0;
	for(i=0; i<=30; i++)
	   c[0][i] = 0;
	for(i=1; i<=n; i++)
	   for(j=1; j<=30; j++)
	      if(weight[i] > j)
	          c[i][j] = c[i-1][j];
	      else
	          c[i][j] = max(c[i-1][j],c[i-1][j-weight[i]]+price[i]);
	        
}

main(){
register int i, j, k;
int tests, n, g, gi, sum;



	scanf("%d",&tests);
	for(i=0; i<tests; i++){
	   scanf("%d",&n);
	   for(j=1; j<=n; j++)  
	      scanf("%d %d",&price[j],&weight[j]);
	   knapsack(n);
	   scanf("%d",&g);
	   sum = 0;
	   for(j=0; j<g; j++){
	      scanf("%d",&gi);
	      sum += c[n][gi];
	   }
	   printf("%d\n",sum);
	}

}


