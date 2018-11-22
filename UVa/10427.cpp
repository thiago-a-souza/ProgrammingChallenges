#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 10000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int getDigitAtIndex(int v, int offset){
int x[20], pos = 0;

	while(v > 0){
		  x[pos++] = v%10;
		  v = v/10; 
	}
	
	return x[pos-offset-1];
}

int main(){
int N;
int index, elements, digits, nbr;

// printf("%d\n", getDigitAtIndex(123,0));

	while(scanf("%d",&N) != EOF){
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
          printf("%d\n", getDigitAtIndex(nbr, N - index));
	 	  
	}
	return 0;
}

