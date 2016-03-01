/* What Base Is This? - 05/05/2007 */
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAX 30
#define INF 100000

int getMax(char *a){
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
}

void convert(char *a, int minbase, unsigned long long int *vec){
register int i, j, k;
int val;

	for(i=minbase; i<=36; i++){
	   vec[i]=0;
	   for(j=strlen(a)-1, k=0; j>=0; j--, k++){
	      if(a[j]<=57)
	         val=a[j]%48;
	      else
	         val=a[j]%65 + 10;
	      vec[i] += val*((unsigned long long int)pow((double)i,(double)k));
	   }
	}	      

}

int main(){
register int i, j;
char numa[MAX], numb[MAX];
unsigned long long int vala[37], valb[37];
int maxa, maxb;

	while((scanf("%s %s",numa,numb))!=EOF){
	     maxa = getMax(numa);
	     maxa++;
	     if(maxa==1)
	       maxa++;
	     convert(numa,maxa,vala);
	     maxb = getMax(numb);
	     maxb++;
	     if(maxb==1)
	       maxb++;
	     convert(numb,maxb,valb);
	     for(i=maxa; i<=36; i++)
	         for(j=maxb; j<=36; j++)
	             if(vala[i]==valb[j]){
	                cout << numa << " (base "<<i<<") = "<< numb<<" (base "<<j<<")"<<endl;
	                i=INF;
	                j=INF;  
	             }
	     if(i<INF)
	       cout << numa << " is not equal to " << numb << " in any base 2..36\n";
	}
return 0;
}
