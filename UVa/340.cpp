#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 1001

using namespace std;

main(){
int N, zeroes, strong, weak, game = 1;
int secret[MAX], guess[MAX];
int sec[MAX];


		while(true){
		      scanf("%d",&N);
		      if(N == 0)
		         break;
    
             for(int i=0; i<N; i++)
	             scanf("%d",&secret[i]);
	        
	         printf("Game %d:\n",game);
	         game++;

		      while(true){
		            zeroes = 0;
		            for(int i=0; i<N; i++){
		               scanf("%d",&guess[i]);
		               if(guess[i] == 0)
		                  zeroes++;
		            }
		            if(zeroes == N)
		               break;
		               
		            for(int i=0; i<N; i++)
		                sec[i] = 0;
		            strong = 0;
		            weak = 0;
		            
		            for(int i=0; i<N; i++)
		                if(secret[i] == guess[i]){
		                   strong++;
		                   sec[i] = true;
		                }
		            for(int i=0; i<N; i++)
		                if(guess[i] != secret[i])
 	                       for(int j=0; j<N; j++)
		                      if(guess[i] == secret[j] && sec[j] == 0){
		                         weak++;
		                         sec[j] = 1;
		                         break;
		                      }
		            printf("    (%d,%d)\n",strong,weak);        
		                   
		            
		            

		           
		              
		      }
		}
}

