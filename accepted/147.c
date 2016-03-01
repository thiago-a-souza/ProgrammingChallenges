/* Dollars - 22/05/07 */
#include <stdio.h>

#define MAX 100000

main(){
register int i, j;
int moedas[]={ 2000,1000,400,200,100,40,20,10,4,2,1 };
unsigned long long int result[MAX];
double fvalue;
int ivalue;
	
	for(i=0; i<MAX; i++)
	   result[i]=0;
	result[0]=1;

	for(i=0; i<11; i++)
	   for(j=moedas[i]; j<MAX; j++)
	       result[j]+=result[j-moedas[i]];

	scanf("%lf",&fvalue);
	ivalue = (int)(fvalue*100+0.5);
	ivalue /=5;
	while(ivalue>0){
	      printf("%6.2lf %16llu\n", fvalue, result[ivalue]);
	      scanf("%lf",&fvalue);
	      ivalue = (int)(fvalue*100+0.5);
	      ivalue /=5;
	}
}

