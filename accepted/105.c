/* SKYLINE */
#include<stdio.h>


#define MAX 10001

main(){
int mat[MAX]; 
int i, j, l, h, r;
int ult;

	for(i=0;i<MAX;i++)
	   mat[i]=0;

	while((scanf("%d %d %d",&l,&h,&r))!=EOF)
	     for(i=l;i<r;i++)
		if(mat[i]<h)
		  mat[i]=h;
	i=0;
	while(mat[i]==0)
	     i++;
	ult=mat[i];
	printf("%d %d",i,mat[i]);
	for(j=i; j<MAX; j++){
	   while(mat[j]==ult)
		j++;
	   if(j<MAX){
	     printf(" %d %d",j,mat[j]);
	     ult=mat[j];
	   }	   
	}
	printf("\n");
}

