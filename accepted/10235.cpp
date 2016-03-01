#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<cstdlib>

#define MAX 1000000
using namespace std;

int isPrime(int n){
  if(n == 2) 
     return 1;
  if(n <= 1 || !n%2)
     return 0;
  for(int i=3; i*i <= n; i += 2)
     if(n%i == 0) 
        return 0;
  return 1;
}

main(){
set<int> primes;
int  mul;
int count = 0, len, n1, n2;
char nbr[20];
        primes.insert(2);
        for(int i=3; i<MAX; i+=2){
            if(isPrime(i)){
             //   printf("%d\n",i);
                primes.insert(i);
            }
        }
        while(scanf("%s",nbr) != EOF ){
             len = strlen(nbr);
             mul = 1;
             n1 = 0; n2 = 0;
             for(int i=0, j=len-1; i<len; i++, j--){
                n1 += (((int)(nbr[j]))-48)*mul;
                n2 += (((int)(nbr[i]))-48)*mul;
                mul = mul*10;
             }

               if(primes.count(n1) > 0 && primes.count(n2) > 0 && n1 != n2)
                 printf("%s is emirp.\n",nbr);
               else if(primes.count(n1) > 0) 
                     printf("%s is prime.\n",nbr);
               else printf("%s is not prime.\n",nbr);
             
                 
        }

}

