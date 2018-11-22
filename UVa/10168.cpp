#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>


using namespace std;
#define MAXSIEVE 10000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 3163 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

void sieve(){
int i,j;

   memset(a,255,sizeof(a));
   a[0]=0xFE;
   for(i=1;i<MAXSQRT;i++)
      if (a[i>>3]&(1<<(i&7)))
         for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
            a[j>>3]&=~(1<<(j&7));
}

int checkPrime(int n){
    if(n<=1) return 0;
       if(n==2 || (n%2) && isprime(n)) 
          return 1;
    return 0; 
}


main(){
int  n;
bool b;
	      
	sieve();      
	while(scanf("%d",&n) != EOF){
	     if(n <= 7){
	        printf("Impossible.\n");
	        continue;
	     }
	
         if(n%2 == 0){
            printf("2 2 ");
            n = n - 4;
         }
         if(n%2 == 1){
           printf("2 3 ");
           n = n - 5;
         }
         b = true;
         for(int i=2; i < n ; i++)
            if(checkPrime(i) && checkPrime(n-i)){
               printf("%d %d\n",i,n-i);
               break;
            }
         
            
        
	}


}