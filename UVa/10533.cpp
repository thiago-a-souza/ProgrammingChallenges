#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 78500
#define MAXP 1000001

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
int primes[MAX], sz = 1, aux, sum;
int n, t1, t2;
bool isDigitPrime[MAXP], b;
int sumDigitPrimes[MAXP];
set<int> setPrimes;

	primes[0] = 2;
	setPrimes.insert(2);
	for(int i = 3; i<MAXP; i+=2)
	    if(isPrime(i)) { 
           primes[sz] = i;
           setPrimes.insert(i);
           sz++;
    }

    memset(isDigitPrime, false, sizeof(isDigitPrime));

    for(int i=0; i<sz; i++){
       aux = primes[i];
       sum = 0;
       while(aux > 0){
             sum += aux%10;
             aux = aux/10;
       }
       if(setPrimes.count(sum) > 0)
          isDigitPrime[primes[i]] = true;
    }


    for(int i=1 ; i<MAXP; i++)
       if(isDigitPrime[i])
          sumDigitPrimes[i] = sumDigitPrimes[i-1]+1;
       else
          sumDigitPrimes[i] = sumDigitPrimes[i-1];
    
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d %d",&t1,&t2);
        printf("%d\n",sumDigitPrimes[t2]-sumDigitPrimes[t1]+(sumDigitPrimes[t1]-sumDigitPrimes[t1-1]));
    }

}

