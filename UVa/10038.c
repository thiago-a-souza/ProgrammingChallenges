/* Jolly Jumpers */
#include <stdio.h>
#include <string.h>


#define MAX 3005

main(){
char nmb[MAX];
int i, n, v1, v2, dif;
	nmb[0]='*';
	while((scanf("%d",&n))!=EOF){
	     if(n>1){
		for(i=1; i<(MAX-1); i++)
		   nmb[i]='\0';
		scanf("%d",&v1);
		for(i=0; i<(n-1); i++){
		   scanf("%d",&v2);
		   dif=v1-v2;
		   if(dif<0)
		     dif=-dif;
		   nmb[dif]='*';
		   v1=v2;
		}

		if(strlen(nmb)==n)
		  printf("Jolly\n");
		else
		  printf("Not jolly\n");
	     }
	     else
		 if(n==1){
		   scanf("%d",&v1);
		   if(v1==1)
		     printf("Jolly\n");
		   else
		     printf("Not jolly\n");
		 }
	}
}

