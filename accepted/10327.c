/* Flip Sort */
#include <stdio.h>

#define MAX 1000

main(){
int N, vet[MAX],tmp;
int i,j, trocas;
	while((scanf("%d",&N))!=EOF){;
	     for(i=0; i<N; i++)
	        scanf("%d",&vet[i]);
	     trocas = 0;
	     for(i=N-1; i>=1; i--)
	         for(j=0; j<=i-1; j++)
		    if(vet[j]>vet[j+1]){
		       tmp=vet[j];
		       vet[j]=vet[j+1];
		       vet[j+1]=tmp;
		       trocas++;
		    }
	   printf("Minimum exchange operations : %d\n",trocas);
	}
}


