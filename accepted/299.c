/* Train Swapping */
#include <stdio.h>

#define MAX 50

main(){
int N, L, train[MAX],tmp;
int i,j, r, s, trocas;
	scanf("%d",&N);
	for(i=0; i<N; i++){
	   scanf("%d",&L);
	   trocas = 0;
	   for(j=0; j<L; j++)
	      scanf("%d",&train[j]);
	   for(r=L-1; r>=1; r--)
	      for(s=0; s<=r-1; s++)
		 if(train[s]>train[s+1]){
		    tmp=train[s];
		    train[s]=train[s+1];
		    train[s+1]=tmp;
		    trocas++;
		 }
	   printf("Optimal train swapping takes %d swaps.\n",trocas);
	}
}


