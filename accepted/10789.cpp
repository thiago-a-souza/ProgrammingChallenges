#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 2010

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
int n, len, primes[303], count = 0, it = 1;
int freqN[10], freqA[26], freqa[26];
char str[MAX];

		//primes[count++] = 2;

	  /*  for(int i=3; i<MAX; i++)
	       if(isPrime(i))
	          primes[count++] = i; */
	    

		scanf("%d",&n);
		while(n--){
		     scanf("%s",str);
		     
		     len = strlen(str);
		     
		     memset(freqN,0,sizeof(freqN));
		     memset(freqA,0,sizeof(freqA));
		     memset(freqa,0,sizeof(freqa));
		     
		     for(int i=0; i<len; i++){
		        if(str[i] >= '0' && str[i] <= '9')
		           freqN[((int)str[i]-48)]++;
		        else if(str[i] >= 'A' && str[i] <= 'Z')
		                freqA[((int)str[i]-65)]++;
		        else if(str[i] >= 'a' && str[i] <= 'z')
		                freqa[((int)str[i]-97)]++;
		     }
		     
		     printf("Case %d: ",it);
		     it++;
		     count = 0;
		     
		     for(int i=0; i<10; i++)
		        if(freqN[i] > 0 && isPrime(freqN[i]) ){
		           printf("%c",((char)i+48));
		           count++;
		        }
  		     for(int i=0; i<26; i++)
		        if(freqA[i] > 0 && isPrime(freqA[i]) ){
		           printf("%c",((char)i+65));
		           count++;
		        }
  		     for(int i=0; i<26; i++)
		        if(freqa[i] > 0 && isPrime(freqa[i]) ){
		           printf("%c",((char)i+97));
		           count++;
		        }
		     if(count == 0)
		        printf("empty");
		     printf("\n");

		     
		}
}

