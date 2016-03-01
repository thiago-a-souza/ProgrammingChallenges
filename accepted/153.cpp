#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 32

int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

using namespace std;

int isPrime(int v){

	for(int i=0; i<10; i++)
	    if(v == prime[i])
	       return 1;
	return 0;
}

int factorial(int val, int v[]){
int ans;
int fat[MAX];
int count, aux; 

    
    memset(fat, 0, sizeof(fat));
	for(int i=1; i<=val; i++)
	   fat[i] = i;
	

	
	int index = MAX-1;
	while(index > 0){
	      if(v[index] <= 0){
	         index--;
	         continue;
	      }
	      bool flag = false;
	      for(int i=2; i<=val; i++){
	         if(fat[i] > 1 && fat[i]%index == 0){
	            fat[i] = fat[i]/index;
	            v[index]--;
	            v[index-1]++;
	            flag = true;
	            break;
	         }
	      }
	      
	      if(!flag){
	         int nbr = index;
	         while(nbr > 1){
	              for(int i=0; i<10; i++){
	                  while(nbr > 1 && nbr%prime[i] == 0){
	                     for(int j=2; j<=val; j++){
	                         if(fat[j] > 1 && fat[j]%prime[i] == 0){
	                            fat[j] = fat[j]/prime[i];
	                            nbr = nbr/prime[i];
	                            break;
	                         }
	                     }
	                  }
	               }
	         }
	         v[index]--;
	         v[index-1]++;
	      }
	}
	ans = 1;             
	for(int i=2; i<=val; i++)
	   ans = ans*fat[i];
	return ans;
}



long long recursion(char *str, int len){
int occur[MAX], freq[MAX];
long long sum = 0;


    if(len <= 1)
       return 0;

    memset(occur, 0, sizeof(occur));
    
	for(int i=0; i<len; i++)
	    occur[((int)str[i]) - 97]++;
	    
    for(int i=0; i<MAX; i++){
        if( i+97 < ((int)str[0]) && occur[i] > 0){
           memset(freq, 0, sizeof(freq));
           for(int j=0; j<MAX; j++){
               if(occur[j] > 0){
                     if(i == j){
                        freq[occur[j]-1]++;
                     } else {
                        freq[occur[j]]++;
                     }
               }
           }
           int x = factorial(len-1, freq);
           sum += x;
        }	
    }
    return sum + recursion(&str[1], len-1);
}


int main(){
char str[MAX];

 while(true){
          memset(str, '\0', sizeof(str));
	      scanf("%s",str);
	      if(strcmp(str,"#") == 0 )
	         break;
	      printf("%10llu\n", 1 + recursion(str, strlen(str)));
	}
}

