#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

int isPrime(int n){
      if(n == 2 || n == 3) 
        return 1;
      if(n%2 == 0)
         return 0;
      for(int i=3; i*i <= n; i += 2)
         if(n%i == 0) 
           return 0;
      return 1;
}

int main(){
char ch[50];
int length, n;
int primes[1010], count = 1;

    primes[0] = 1;
    for(int i=2; i<2000; i++)
       if(isPrime(i) == 1){
          primes[count++] = i;
         // printf("%d\n",i);
       }
    

    

	while( scanf("%s",ch) != EOF ){
	     length = strlen(ch);
	     n = 0;
	     for(int i=0; i<length; i++){
	       //  printf("%c\n",ch[i]);
	         if(ch[i] >= 'a' && ch[i] <= 'z'){
	            n += ((int)ch[i] - (int)'a') + 1;
	         } else {
	            n += ((int)ch[i] - (int)'A') + 27;
	         }
	     }
	     for(int i=0; i<1000; i++){
	        if(primes[i] == n){
	           printf("It is a prime word.\n");
	           break;
	        }
	        else if(primes[i] > n){
	                printf("It is not a prime word.\n");
	                break;
	        }
	     }  
	}

    return 0;
}

