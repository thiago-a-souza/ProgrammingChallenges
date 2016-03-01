#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 2000

using namespace std;

int isPrime(int n){
  if(n == 2) 
     return 1;
  if(n <= 1 || n%2 == 0)
     return 0;
  for(int i=3; i*i <= n; i += 2)
     if(n%i == 0) 
        return 0;
  return 1;
}

main(){
int primes[MAX], len = 2;
int N, C;
int count;


	primes[0] = 1;
	primes[1] = 2;
	for(int i=3; i<2000; i++)
	   if(isPrime(i))
	      primes[len++] = i;
	
	while(scanf("%d %d",&N,&C) != EOF){
	     count = 0;
	    
	     while(primes[count] <= N)
	           count++;
	     printf("%d %d:",N,C);

	     if(count%2 == 0){
	        if(count/2 - C < 0){
	           for(int i=0; i<count; i++)
	               printf(" %d",primes[i]);
	        } else {
	        for(int i=(count/2) - C; i<(count/2)+C; i++)
	            printf(" %d",primes[i]);
	        }
	     } else {
	       if((count/2)-(((C*2)-1)/2) < 0){
   	          for(int i=0; i<count; i++)
	              printf(" %d",primes[i]);

	         
	       } else {
	        for(int i=(count/2)-(((C*2)-1)/2); i<=(count/2)+(((C*2)-1)/2); i++)
	             printf(" %d",primes[i]);
	       }
	     }
	     printf("\n\n");
	    
	}
	      

}