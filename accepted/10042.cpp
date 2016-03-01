#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 100001

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
long long primes[MAX], sz = 1, val, tmp, index;
int n;
long long primesDigitsSum[MAX], sumPrimes, sumDigits;
bool b;

    primes[0] = 2;
    primesDigitsSum[0] = 2;
    
	for(int i = 3; sz<MAX; i+=2)
	   if(isPrime(i)) { 
          primes[sz] = i;
          tmp = i;
          while(tmp > 0){
               primesDigitsSum[sz]  += tmp%10;
               tmp = tmp/10;
          }
          sz++;
	   }



    scanf("%d",&n);
   
    while(n--){
   
         scanf("%llu",&val);
         while(true){
              b = false;
              val++;


              for(int i=0; i<sz; i++){
                  if(val == primes[i]){
                     b = true;
                     break;
                  } 
              }
              
              if(b){
                 continue;
              }

              tmp = val;
              index = 0;
              sumPrimes = 0;
              while(tmp > 1 && index < sz){
                   while(tmp%primes[index] == 0){
                         sumPrimes += primesDigitsSum[index];
                         tmp = tmp/primes[index];
                   }
                   index++;
              }
              if(tmp > 1 && tmp != val){
                 while(tmp > 0){
                      sumPrimes += tmp%10;
                      tmp = tmp/10;
                 }
              }
              
              tmp = val;
              sumDigits = 0;
              while(tmp > 0){
                    sumDigits += tmp%10;
                    tmp = tmp/10;
              }
              
              if(sumPrimes == sumDigits){
                 printf("%llu\n",val);
                 break;
              }
         }
    }
}