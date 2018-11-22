#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

#define MAXTOTAL 10000
#define NUMERO_ELEMENTOS 21 
using namespace std;

int moedas[NUMERO_ELEMENTOS] = {9261,8000,6859,5832,4913,4096,3375,2744,2197,1728,1331,1000,729,512,343,216,125,64,27,8,1};
unsigned long long numManeiras[MAXTOTAL+1];

void inicializa(){
int c;

	numManeiras[0] = 1;
	for(int i=1; i<=MAXTOTAL; i++)
	    numManeiras[i] = 0;
    for(int i=0; i<NUMERO_ELEMENTOS; i++){
       c = moedas[i];
       for(int j=c; j<=MAXTOTAL; j++)
           numManeiras[j] += numManeiras[j-c];
    }

}

main(){
int money;

	inicializa();
	while(scanf("%d",&money) != EOF){
	      cout << numManeiras[money] << endl;
	}
}
