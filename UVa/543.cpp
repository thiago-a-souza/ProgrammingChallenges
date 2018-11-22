/* Goldbach's Conjecture - 06/11/2007 */ 
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define MAX 1000001

main(){
int numbers[MAX], primes[78499];
int cont=0, n;

	memset(numbers, 0, sizeof(numbers));
	numbers[0] = numbers[1] = 1;
	for(int i=2; i<MAX; i++){
		if(numbers[i] == 0){
		  primes[cont++] = i;
	      int j=2;
	      while(i*j < MAX){
	           numbers[i*j] = 1;
	           j++;
	      }
	    }
	}

	while(true){
		scanf("%d",&n);

		if(n == 0)
		  return 0;
		  
		for(int i=0; i<cont; i++){
		   if(primes[i] > n/2){
		   	 printf("Goldbach's conjecture is wrong.\n");
		   	 break;
		   }
		   if(( n-primes[i] >=0 ) && numbers[n - primes[i]] == 0){
		     printf("%d = %d + %d\n",n, primes[i], n-primes[i]);
		     break;
		   }
		}
	}
}
