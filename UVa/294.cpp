#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<climits>

#define MAX 32000

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
int primes[3500], len = 1, n, count, index;
long long L, U, ans, max_ans, aux, val;


        primes[0] = 2;
		for(int i=3; i<=MAX; i+=2)
		    if(isPrime(i))
		       primes[len++] = i;
		       
		scanf("%d",&n);
		
		while(n--){
		     scanf("%llu %llu",&L,&U);
		     
		     max_ans = 1;
		     val = 1;

		     for(long long i = L; i<=U; i++){
		         aux = i;
                 index = 0;
                 ans = 1;
		         while(aux > 1 && index < len){
		               count = 0;
		               while(aux%primes[index] == 0){
		                    aux = aux/primes[index];
		                    count++;
		               }
		               ans = ans*(count+1);
		               index++;
		         }
		         if(aux > 1)
		            ans = ans*2;
		            
		         if(ans > max_ans){
		            max_ans = ans;
		            val = i;
		        }
		     }
		     
		     printf("Between %llu and %llu, %llu has a maximum of %llu divisors.\n",L,U,val,max_ans);
		     
		     
		}


}



