#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>


#define MAX 32001            
            
using namespace std;

unsigned int S[MAX+1];


int getDigitAtIndex(int v, int offset){
int x[20], pos = 0;

	while(v > 0){
		  x[pos++] = v%10;
		  v = v/10; 
	}
	return x[pos-offset-1];
}

int calc(int N){
int index, elements, digits, nbr; 
	index = 1; 
	digits = 1;
    elements = 9;
	nbr = 1;
	while(index + elements*digits < N){
          index += elements*digits;
          digits++;
          elements = elements*10;
          nbr = nbr*10;
    }	 
          
    while(index + digits <= N){
          index += digits;
          nbr++;
    }	  
          
    return getDigitAtIndex(nbr, N - index);
}

int main(){
int i, t, n;
unsigned int factor, digits, last_length, total_length;


	factor = 10;
	digits = 1;
	last_length = 0; total_length = 0;
	for(int i=1; i<MAX; i++){
	    if(i >= factor){
	       digits++;
	       factor = factor * 10;
	    }
	    last_length = last_length + digits;
	    total_length = total_length + last_length;
	    S[i] = total_length;
	}	

	scanf("%d",&t);
		 int line = 1;
	while(t--){

		  scanf("%d",&n);
          for(i=1; i<MAX; i++)
              if(S[i] >= n){
                 printf("%d\n",calc(n-S[i-1]));
                 break;
             }
          

	}
	return 0;
}


