#include<cstdio>
#include<iostream>
#include<cstring>


#define MAX 26
using namespace std;

int main(){
int up[MAX], low[MAX];
int pos;
char ch;


	while(scanf("%c",&ch) != EOF){
	   
	    for(int i=0; i<MAX; i++)
	        up[i] = low[i] = 0;
	
	    while(true){
	      int pos = (int)ch;
	      
	      if(pos >= 65 && pos <= 90){
	        up[pos-65]++;
	      }
	      else if(pos >= 97 && pos <= 122){
	              low[pos-97]++;
	      }
	      scanf("%c",&ch);
	      if(ch == '\n')
	         break;
	    }

	    int max_freq = 0;
	    for(int i=0; i<MAX; i++)
	        if(up[i] > max_freq)
	           max_freq = up[i];
	    
	    for(int i=0; i<MAX; i++)
	        if(low[i] > max_freq)
	           max_freq = low[i];
	    
	    for(int i=0; i<MAX; i++)
	       if(up[i] == max_freq)
	          printf("%c",(char)(i+65));
	    
	    for(int i=0; i<MAX; i++)
	       if(low[i] == max_freq)
	          printf("%c",(char)(i+97));
	    printf(" %d\n",max_freq);
	    

	}

}


