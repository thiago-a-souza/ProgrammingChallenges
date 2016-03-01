#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <vector>

#define MAX 200002


using namespace std;

int isTwinPrime(int n){
int x = n+2;

  for(int i=3; i*i <= x; i += 2)
     if(n%i == 0 || x%i == 0) 
        return 0;
  return 1;
}

main(){
int twin[MAX], sz = 0;
int primes[1175775], count = 0;
int n;

		for(int i=3; i<=18409199; i+=2){
		    if(isTwinPrime(i))
		       twin[sz++] = i;
		}

		while(scanf("%d",&n) != EOF){
		     printf("(%d, %d)\n",twin[n-1],twin[n-1]+2);
		     
		}
}
