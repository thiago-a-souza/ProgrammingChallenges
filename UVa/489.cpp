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
#include<queue>

#define MAX 2000
using namespace std;


main(){
int round, errors;
char word[MAX], guess[MAX];
int len1, len2;
int incorrect;
bool b;
	while(true){
	     scanf("%d",&round);
	     if(round < 0)
	        break;
	        
	     scanf("%s",word);
	     scanf("%s",guess);
	     errors = 0;
	     len1 = 0; len2 = 0;
	     len1 = strlen(word);
	     len2 = strlen(guess);

	     for(int i=0; i<(len2-1); i++)
	        for(int j=i+1; j<len2; j++)
	            if(guess[i] == guess[j]){
	               guess[j] = ' ';
	            }
	     for(int i=0; i<len2; i++)
	        if(guess[i] == ' '){
	           for(int j=i; j<len2; j++)
	              guess[j] = guess[j+1];
	           len2--;
	           i--;
	        }
	            
	            
	     
	     incorrect = len1;
	     
	     for(int i=0; i<len2; i++){
	         b = false;
	         for(int j=0; j<len1; j++){
	            if(guess[i] == word[j]){
	               incorrect--;
	               b = true;
	               if(incorrect == 0){ 
	                  i = MAX; j = MAX;
	               }
	            }
	         }
	         if(b == false)
	           errors++;
	         if(errors > 7)
	            break;
	     }

	     if(errors >= 7)
	       printf("Round %d\nYou lose.\n",round);
	     else if(incorrect <= 0)
	             printf("Round %d\nYou win.\n",round);
	     else printf("Round %d\nYou chickened out.\n",round);
	     
	     
	}
}

