/* Basically Speaking - 06/05/2007 */
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

int main(){
char num[MAX];
int b_orig, b_dest, i;

    while((scanf("%s %d %d", num, &b_orig, &b_dest))!=EOF){
            convertDecimal(num,b_orig);
            convertX(b_dest);
            if(strlen(numX)<=7){
              for(i=0; i<7-strlen(numX); i++)
                 cout << " ";
              cout << numX << endl;
            }
            else
            cout << "  ERROR\n";    }
    
 
return 0;   
}
