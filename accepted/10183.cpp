/* How many Fibs? - 05/05/2007 */
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define MAX 110

char result[501][MAX];
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

        for(i=1; i<=n-2; i++){
           soma(result[i],result[i+1],i+2);	        
        }
}

void clear(){
register int i, j;

	for(i=0; i<501; i++){
	   for(j=0; j<MAX-1; j++)
	       result[i][j]='0';
	   result[i][MAX-1]='\0';
	}
}

void fixOrder(char *a){
register int i, j;
char tmp[MAX];

	for(i=0; i<MAX-1; i++)
	   tmp[i]='0';
	tmp[MAX-1]='\0';
	for(i=MAX-2, j=strlen(a)-1; i>=0 && j>=0 ; i--, j--)
	   tmp[i]=a[j];
	strcpy(a,tmp);
}

int main(){
register int i;
char a[MAX], b[MAX];
int count, tama, tamb;


	clear();
	result[1][MAX-2]='1';
	result[2][MAX-2]='2';
	fibonacci(500);
	scanf("%s %s",a,b);
	while(strlen(a)!=1 || strlen(b)!=1 || a[0]!='0' || b[0]!='0'){
	      fixOrder(a);
	      fixOrder(b);
	      i=1; count=0;
	      while(strcmp(a,result[i])>0)
	           i++;
	      while(strcmp(b,result[i])>=0){
	      	   count++;
	      	   i++;   
	      }	   
	      cout << count << endl;
	      scanf("%s %s",a,b);
	}

return 0;
}

