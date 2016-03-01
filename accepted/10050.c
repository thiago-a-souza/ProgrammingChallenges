/* HARTALS */
#include <stdio.h>

#define MAX 3651


main(){
int t, n, p,i,j,k,d, count;
char str[MAX];
	scanf("%d",&t);
	for(i=0;i<t;i++){
	   count = 0;
	   scanf("%d",&n);
	   scanf("%d",&p);
	   for(j=0;j<MAX;j++)
	      str[j]='\0';
	   for(j=0;j<p;j++){
	      scanf("%d",&d);
	      for(k=d;k<=n;k=k+d)
		 str[k]='!';
	   }
	   for(j=1;j<=n;j++)
	      if(str[j]=='!')
		if((j+1)%7!=0 && j%7!=0)
		   count++;
	   printf("%d\n",count);
	}
}

