#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>

#define MAX 10000
int s[MAX];

using namespace std;

void maxIntervalSum(int nElementos, int &maxSum){
int max[MAX], start[MAX];
int posMax = 1;

	for(int i=1; i<MAX; i++)
	   max[i] = start[i]  = 0;
	start[0] = 1;
	
	for(int i=1; i<=nElementos; i++){
	   if(max[i-1] >= 0){
	      max[i] += max[i-1] + s[i];
	      start[i] = start[i-1];
	   } else {
	      max[i] += s[i];
	      start[i] = i;
	   }
	}
	
	for(int k=2; k<=nElementos; k++)
	   posMax = max[k] > max[posMax] ? k : posMax;
	maxSum = max[posMax];

}

main(){
int n;
int inicio, fim, maxsum;
	while(true){
	    scanf("%d",&n);
	    if(n == 0)
	       break;
	    for(int i=1; i<=n; i++)
	       scanf("%d",&s[i]);
	    inicio = 0; fim = n;
	    maxIntervalSum(n, maxsum);
	    if(maxsum <= 0)
	       printf("Losing streak.\n");
	    else
	       printf("The maximum winning streak is %d.\n",maxsum);
	}    
}

