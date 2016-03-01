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

#define MAXSQRT 1000000
#define MAX 1000000000000L

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

int main(){
int t, index, ans;
int primes[78500], len, cont;
long long almostPrimes[80081];
long long sum;
long long a, b;

        primes[0] = 2;
		len = 1;
		for(int i=3; i<MAXSQRT; i+=2)
		   if(isPrime(i))
		      primes[len++] = i;

        cont = 0;
		for(int i=0; i<len; i++){
           sum = primes[i];
		   while(true){
		        sum = sum*primes[i];
		        if(sum > MAX)
		           break;
   		        almostPrimes[cont++] = sum;
		   }
		}

		sort(almostPrimes, almostPrimes+cont);
		
		    
		scanf("%d",&t);
		while(t--){
		     scanf("%llu %llu",&a,&b);
		     index = 0;
		     while(almostPrimes[index] < a && index < cont)
		           index++;
		     ans = 0;
		     while(almostPrimes[index] <= b && index < cont){
		           index++;   ans++;
		     }
		     printf("%d\n",ans);
		}
}

