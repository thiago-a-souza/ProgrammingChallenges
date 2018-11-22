#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 100

using namespace std;

int main(){
int tests, v[MAX];
int N, P, Q;
int totalWeight, eggs;
int line = 1;

	scanf("%d",&tests);
	while(tests--){
		scanf("%d %d %d",&N,&P,&Q);
		for(int i=0; i<N; i++) 
		   scanf("%d", &v[i]);

	    totalWeight = 0; eggs = 0;
		
		for(int i=0; i<N; i++){
		    if(totalWeight + v[i] > Q || eggs + 1 > P)
		       break;
		     totalWeight += v[i];
		     eggs++;		    
		}
		printf("Case %d: %d\n", line, eggs);
		line++;
		
	}

	
}

