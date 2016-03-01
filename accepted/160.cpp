#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

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
int primes[50], len = 1, index;
int n, freq[100], aux;

        primes[0] = 2;
		for(int i=3; i<100; i++)
		   if(isPrime(i))
		      primes[len++] = i;

		while(true){
			  scanf("%d",&n);
			  if(n == 0)
			     break;
			  memset(freq, 0, sizeof(freq));
			  for(int i=2; i<=n; i++){
			     aux = i;
			     index = 0;

			     while(aux > 1 && index < len){

			          while(aux%primes[index] == 0){
			                aux = aux/primes[index];
			                freq[primes[index]]++;
			          }
			          index++;
			     }
			  }
			  printf("%3d! =",n);
			  aux = 0;
			  for(int i=2; i<100; i++){
			     if(freq[i] > 0){
			       if(aux == 15){
			         printf("\n      ");
			         aux = 0;
			       } else {
			         aux++;
			       }
			       printf("%3d",freq[i]);
			     }
			  }
			  printf("\n");
		}

}

