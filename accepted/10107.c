/* What is the Median? */
#include <stdio.h>

void ordena(int mat[], int n){
int aux, i, j;
	for(i=1; i<n; i++){
		aux=mat[i];
		for(j=i-1; j>=0 && mat[j]>aux; j--)
			mat[j+1]=mat[j];
		mat[j+1]=aux;
		}
}

main(){
int i=0, mat[10000];

	while((scanf("%d",&mat[i]))!=EOF){
	   if(i==0)
	    printf("%d\n", mat[i]);
	   else{
	    ordena(mat,i+1);
	    if(i%2==0)
	     printf("%d\n",mat[i/2]);
	    else
	     printf("%d\n",(mat[i/2]+mat[(i+1)/2])/2);
	   }
	i++;
	}
}

