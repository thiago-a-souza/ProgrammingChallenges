/* The Bases Are Loaded - 06/05/2007 */
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define MAX 50

unsigned long long int numdec;
char numX[MAX];

void convertDecimal(char *a, int base){
register int i, j, k;
int val;
	   numdec = 0;
	   for(j=strlen(a)-1, k=0; j>=0; j--, k++){
	      if(a[j]<=57)
	         val=a[j]%48;
	      else
	         val=a[j]%65 + 10;
	      numdec += val*((unsigned long long int)pow((double)base,(double)k));
	   }
}

void convertX(int baseX){
char tmp[MAX];
int i=0, j, k;
unsigned long long int div;
	while(numdec>0){
	     div = numdec%baseX;
	     if(div<=9)
	        tmp[i++]=div+48;
	     else
	        tmp[i++]=div+55;
	     numdec=numdec/baseX;
	}
	k=0;
	for(j=i-1; j>=0; j--)
	   numX[k++]=tmp[j];
	numX[k]='\0';
	if(i==0){
	  numX[0]='0';
	  numX[1]='\0';
	}
}

int isBase(char *a, int base){
register int i;
int max;
	max = -1;
	for(i=0; i<strlen(a); i++)
	   if(a[i]>max)
	     max = a[i];
	if(max<=57)
	   max = max%48;
	else
	   max = max%65 + 10;
	   
    if(max < base)
	   return 1;
    return 0;   
}   

int main(){
char num[MAX];
int b_orig, b_dest;

    while((scanf("%d %d %s",&b_orig, &b_dest, num))!=EOF){
         if(isBase(num,b_orig)==1){
            convertDecimal(num,b_orig);
            convertX(b_dest);
            printf("%s base %d = %s base %d\n",num, b_orig, numX, b_dest);
         }
         else
            printf("%s is an illegal base %d number\n", num, b_orig);
    }
    
 
return 0;   
}
