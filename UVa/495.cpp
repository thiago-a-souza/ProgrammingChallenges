/* Fibonacci Freeze - 04/05/2007 */
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define MAX 2000

char result[5001][MAX];
int maior;

void soma(char *a, char *b, int n){
register int i;
int sobeum = 0, tmp;

	for(i=MAX-2; i>=0; i--){
	    if((a[i]+b[i] + sobeum)%48<=9){
	       result[n][i] = (a[i] + b[i] + sobeum)%48 + 48;
	       sobeum = 0;
	    }
	    else{
	       result[n][i] = ((a[i] + b[i] + sobeum)%48)%10+48;
	       sobeum = 1;
	    }
	}
}

void fibonacci(int n){
char a[MAX], b[MAX];
int i;

        for(i=maior-1; i<=n-2; i++){
           soma(result[i],result[i+1],i+2);	        
        }
        maior = n;
}

void clear(){
register int i, j;

	for(i=0; i<5001; i++){
	   for(j=0; j<MAX-1; j++)
	       result[i][j]='0';
	   result[i][MAX-1]='\0';
	}
}

int main(){
register int i;
int n;

	maior = 1;
	clear();
	result[1][MAX-2]='1';
	
	while((scanf("%d",&n))!=EOF){
	    if(n>maior)
	       fibonacci(n);
	    i=0;
	    while(result[n][i]=='0')
	         i++;
	    if(n>0)
	      printf("The Fibonacci number for %d is %s\n",n,&result[n][i]);
	    else
	      printf("The Fibonacci number for 0 is 0\n");
	}

return 0;
}

