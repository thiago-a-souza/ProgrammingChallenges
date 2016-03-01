/* Coin Change - 10/05/2007 */
#include <stdio.h>

main(){
register int i, j;
int n, result[7490], moedas[]={1,5,10,25,50};

	
	for(i=0; i<=7490; i++)
	   result[i]=0;
	result[0]=1;

	for(i=0; i<5; i++)
	   for(j=moedas[i]; j<=7489; j++)
	       result[j]+=result[j-moedas[i]];

	while((scanf("%d",&n))==1){
	      printf("%d\n", result[n]);
	}
}

