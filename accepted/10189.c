/* Minesweeper */
#include <stdio.h>

main(){
char str[102][102];
int cont[105][105];
int i,j,k,l,vez=1;

scanf("%d", &i);
scanf("%d", &j);

while(i!=0 && j!=0){

	for(k=0; k<i; k++)
   	  scanf("%s", str[k]);

	for(k=0; k<=i+2; k++)
   	   for(l=0; l<=j+2; l++)
      		cont[k][l]=0;

	for(k=0; k<i; k++)
 	  for(l=0; l<j; l++)
  	    if(str[k][l]=='*'){
		cont[k][l]++;
		cont[k][l+1]++;
		cont[k][l+2]++;
		cont[k+1][l]++;
		cont[k+1][l+2]++;
		cont[k+2][l]++;
		cont[k+2][l+1]++;
		cont[k+2][l+2]++;
		cont[k+1][l+1]=-1000;
	}
	printf("Field #%d:\n", vez);
	for(k=1; k<=i;k++){
   	   for(l=1; l<=j; l++)
		if(cont[k][l]<0)
	  	printf("*");
		else
	  	printf("%d", cont[k][l]);
   		printf("\n");
	}
	scanf("%d", &i);
	scanf("%d", &j);
	vez++;
	if(i!=0 && j!=0)
	printf("\n");
     }

}
