/* Frogger - 11/06/2007 */
#include<stdio.h>
#include<math.h>

#define INFINITY 32000.0

int pos[201][2];
double w[201][201], p[201][201];


void initialize(int n){
register int i, j;

	for(i=0; i<=n; i++){
	   for(j=0; j<=n; j++){
	      w[i][j]=INFINITY;
	      p[i][j]=i;
	   }
	   w[i][i]=0;
	}
}


void floydMinMax(int n){
register int i, j, k;
double maior;

	for(k=0; k<n; k++)
	   for(i=0; i<n; i++)
	      for(j=0; j<n; j++){
	      	  if(w[i][k]>w[k][j])
	      	     maior = w[i][k];
	      	  else
	      	     maior = w[k][j];
	      	  if(w[i][j]>maior)
	      	     w[i][j]=maior;
	      }
}


main(){
register int i, j;
int n, x, y, result,scenario=1;


	scanf("%d",&n);
	while(1){
	     for(i=0; i<n; i++)
	        scanf("%d %d",&pos[i][0],&pos[i][1]);
	     initialize(n);
	     for(i=0; i<n-1; i++)
	        for(j=i+1; j<n; j++){
	           w[i][j]=sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0]) + (pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1])); 
	           w[j][i] = w[i][j];
	     }
	     floydMinMax(n);
	     printf("Scenario #%d\nFrog Distance = %0.3lf\n",scenario,w[0][1]);
	     scenario++;
	     scanf("%d",&n);
	     printf("\n");
	     if(n==0)
	       break;
	}
}


