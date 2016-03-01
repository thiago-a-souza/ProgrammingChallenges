#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 1000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int main(){
int K, N;
char encrypted[MAX];
int  enc[MAX];
char dec[MAX];

	while(true){
		 memset(encrypted, '\0', sizeof(encrypted));
	     scanf("%d", &K);
	     if(K == 0)
	        break;
	     scanf("%s", encrypted);
	     N = strlen(encrypted);
	     
	     for(int i=0; i<N; i++){
	        if(encrypted[i] >= 'a' && encrypted[i] <= 'z')
	           enc[i] = (int)(encrypted[i]) - 96;
	        else if(encrypted[i] == '_')
	                enc[i] = 0;
	        else if(encrypted[i] == '.')
	                enc[i] = 27;
	         
	     }
	         
	        
	     for(int i=0; i<N; i++)
	         dec[(K*i) % N] = (enc[i] + i)%28;
	     for(int i=0; i<N; i++){
	         if(dec[i] == 0)
	            printf("_");
	         else if(dec[i] == 27)
	                 printf(".");
	         else if(dec[i] >= 1 && dec[i] <= 26) 
	                 printf("%c",(char) (dec[i] + 96));
	     }
	     printf("\n");
	}
	return 0;
}

