/*
Seja S[] a lista de somas, A[] a lista de números.
Algoritmo assume que A[0] seja conhecido e desconta A[0] dos demais
elementos de S para encontrar A[1-n]. 
Para garantir que o número seja exatamente o procurado são removidos os pares que não 
utilizaram A[0] (por exemplo, A[1]+A[2], A[1]+A[3], etc).
Deste modo, apenas restarão na lista S os elementos que utilizaram S[0], portanto, é claro 
que descontando A[0] irá encontrar os demais elementos.
Para determinar o elemento inicial A[0], podemos constatar que:
S[0] = A[0] + A[1] 
S[1] = A[0] + A[2]

Portanto, S[0] + S[1] = 2*A[0] + A[1] + A[2], basta procurarmos por todos S[i>2] que subtraídos 
de S[0] + S[1] sejam números pares, ou seja:

A[0] = (S[0] + S[1] - S[i])/2

Se na remoção A[0] de S[i] formar pares que não existam em S[i] fica claro que o valor A[0] não é válido.
*/

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

using namespace std;

int S[50], A[50], szS, szA;

int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

bool solve(){
bool finished, b;
int visited[50];

	for(int i=2; i<szS; i++){
	   
	   if((S[0] + S[1] - S[i]) % 2 != 0)
	      continue;
	      
	   finished = true;   
	   memset(visited, 0, sizeof(visited));
	   A[0] = (S[0] + S[1] - S[i])/2;
	   szA = 1;
	   
	   for(int j=0; j<szS; j++){
	       if(visited[j] == 1)
	          continue;
	       A[szA++] = S[j] - A[0];
	       b = true;
   	       
	       for(int k=0; k<(szA-1); k++){
	          b = true;
	          for(int l=0; l<szS; l++){

	              if(A[k] + A[szA-1] == S[l] && visited[l] == 0){
	                visited[l] = 1;
	                b = false;
	                break;
	              }
	           }
	           if(b){
	              finished = false;
	              break;
	           }
	       }
	       if(b){ // nao contem numero
	          finished = false;
	          break;
	       }
	   }
	   if(finished)
	      return true;   
	}
	return false;
}

main(){
int n;

	while(scanf("%d",&n) != EOF){
	     szS = (n*(n-1))/2;
	     for(int i=0; i<szS; i++)
	        scanf("%d",&S[i]);
	        
	     qsort(S,szS, sizeof(int), cmp);
	     
	     if(solve()){
	       
	       for(int i=0; i<n; i++)
	           if(i > 0)
	             printf(" %d",A[i]);
	           else
	             printf("%d",A[i]);  
	       printf("\n");so
	     } else
	        printf("Impossible\n");

	} 
}

