/* The Tourist Guide - 13/06/2007 */
#include<stdio.h>
#include<math.h>

#define MAX 101
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

int w[MAX][MAX];

void floydMaxMin(int n){
register int i, j, k;

	for(k=0; k<=n; k++)
	   for(i=0; i<=n; i++)
	      for(j=0; j<=n; j++)
	         w[i][j] = max(w[i][j],min(w[i][k],w[k][j]));
	
}

void initialize(int n){
register int i, j;

	for(i=0; i<=n; i++)
	   for(j=0; j<=n; j++)
	       w[i][j] = 0;

}

main(){
register int i;
int orig, dest, weight, n, r, div, scenario;

	scenario = 1;
	scanf("%d %d",&n,&r);
	while(n!=0 && r!=0){
	     initialize(n);
	     for(i=0; i<r; i++){
	        scanf("%d %d %d",&orig, &dest, &weight);
	        w[orig][dest] = weight;
	        w[dest][orig] = weight;
	     }
	     scanf("%d %d %d",&orig, &dest, &weight);
	     floydMaxMin(n);
	     div = ceil((double)weight/(w[orig][dest]-1));
	     printf("Scenario #%d\n",scenario);
	     scenario++;
	     printf("Minimum Number of Trips = %d\n\n",div);
	     scanf("%d %d",&n,&r);
	}
}

