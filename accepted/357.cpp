#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAXTOTAL 30001

using namespace std;

main(){
int coins[10] = {50, 25, 10, 5, 1};
long long ways[MAXTOTAL], c;
int n;

		ways[0] = 1;
		for(int i=1; i<MAXTOTAL; i++)
		    ways[i] = 0;
		for(int i=0; i<5; i++){
		   c = coins[i];
		   for(int j=c; j<MAXTOTAL; j++)
		       ways[j] += ways[j-c];
		}
				
		while(scanf("%d",&n) != EOF){
		     if(ways[n] == 1)
		        printf("There is only 1 way to produce %d cents change.\n",n);
		     else
		        printf("There are %llu ways to produce %d cents change.\n",ways[n],n);
		}		



}