#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 34
using namespace std;

int nbin[MAX], ubin[MAX];


void decToBin(long val, int bin[]){
int v[MAX];
int pos = 0;

	while(val > 0){
		v[pos++] = val%2;
		val = val/2;
	}	
	for(int i=MAX-1, j=0; j<pos; i--, j++)
	   bin[i] = v[j];
}

main(){
long n, l, u;
long m;
long power[MAX];
int index;

	power[MAX-1] = 1;
	for(int i=MAX-2; i>=0; i--)
	    power[i] = power[i+1]*2;    

	while(scanf("%ld %ld %ld",&n,&l,&u) != EOF){	   
	     
	     memset(nbin, 0, sizeof(nbin));  
	     memset(ubin, 0, sizeof(ubin));
		 decToBin(n,nbin);
         decToBin(u,ubin);         
         
         index = 0;
         
         while(index < MAX && nbin[index] == 0 && ubin[index] == 0 )
               index++;
         m = 0;
         for(int i=index; i<MAX; i++){
            if(nbin[i] == 0 && m + power[i] <= u)
               m = m + power[i];
            else if(nbin[i] == 1 && m + power[i] - 1 < l)
                    m = m + power[i];
            
         }
         cout << m << endl;
	}
}
