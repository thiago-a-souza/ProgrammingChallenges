#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>

#define MAX 78500
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
int primes[MAX], sz = 1;
int n, cont;

   
   primes[0] = 2;
   
   for(int i=3; i<=1000000; i++){
       if(isPrime(i) == 1)
          primes[sz++] = i;
   }
   
   while(true){
        scanf("%d",&n);
        if( n == 0)
           break;
        cont = 0;

         
        for(int i=0; i < sz && primes[i] <= n ; i++)
            if(n % primes[i] == 0)
               cont++;
        printf("%d : %d\n",n,cont);
   }

}

