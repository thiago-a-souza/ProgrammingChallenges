/* Irreducible Basic Fractions */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100
#define SMAX 31623
#define LIM 
int primes[SMAX];


int is_primer(int n){
int i, raiz;
float raizF;


	raizF=sqrt(n);
	raiz=raizF;
	for(i=3;i<=raiz;i++)
	   if(n%i==0)
	      return 0;
	return 1;
}

main(){
int factors[MAX], raiz, count=0;
int numb, n, i;
float raizF;

	scanf("%d",&numb);
	primes[count++]=2;
	for(i=3;count<SMAX;i=i+2){
	   if(is_primer(i)==1){
	     primes[count++]=i;
	   }
	}

	while(numb!=0){
		count=0;
		n=numb;
		raizF=sqrt(numb);
		raiz=raizF;
		i=0;

		while(i<SMAX && n!=1){
		      if(n%primes[i]==0){
			factors[count++]=primes[i];
			while(n%primes[i]==0)
			      n=n/primes[i];
		      }
		      i++;
		}
		if(n!=1)
		   factors[count++]=n;
		
		for(i=0;i<count;i++){
		    numb=numb-((int)numb/factors[i]);
		}
		printf("%d\n",numb);
		scanf("%d",&numb);
	}
}

