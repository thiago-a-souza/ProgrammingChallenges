#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

#define MAX 78500
using namespace std;


int isPrime(int n){
      if(n == 2 || n == 3)
         return 1;
      if(n <= 1 || n%2 == 0)
         return 0;
      for(int i=3; i*i <= n; i += 2)
         if(n%i == 0)
            return 0;
      return 1; 

}

main(){
int count = 1;
int primes[MAX];
int n, index;
bool ans;
set<int> s;

	primes[0] = 2;
	s.insert(2);
    for(int i=3; i<=1000000; i+=2)
       if(isPrime(i) == 1){
          primes[count++] = i;
          s.insert(i);
       }
   

	while(true){        
	   scanf("%d",&n);
	   if(n == 0)
	      break;
	   ans = false;
	   printf("%d:\n",n);	   
	   int i = 0;
	   while(i < count && primes[i] < n){
	        if(s.count(n-primes[i]) > 0){
	           if(primes[i] < n - primes[i])
	             printf("%d+%d\n",primes[i], n-primes[i]);
	           else
	             printf("%d+%d\n", n-primes[i],primes[i]);
	           ans = true;
	           break;
	        }
	        i++;
	   }  
 	   if(!ans)
 	      printf("NO WAY!\n");          
	}
}

