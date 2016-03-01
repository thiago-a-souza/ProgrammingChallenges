/*  Ecosystem - 21/06/2007 */
#include<stdio.h>

#define MAX 101

main(){
register int i, j, k;
int adj[MAX][MAX];
int n, cont;

	while((scanf("%d",&n))!=EOF){
		for(i=0; i<n; i++)
		   for(j=0; j<n; j++)
		      scanf("%d",&adj[i][j]);
		cont = 0;
		for(i=0; i<n; i++)
		   for(j=0; j<n; j++)
		      for(k=0; k<n; k++)
		         if(adj[i][j] && adj[j][k] && adj[k][i])
		            if((i>j && j>k) || (i<j && j<k)){
		               printf("%d %d %d\n",i+1,j+1,k+1);
		               cont++;
		            }
		printf("total:%d\n\n",cont);
		            
	}


}
