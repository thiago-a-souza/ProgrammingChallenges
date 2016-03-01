/* Testing the CATCHER - 08/06/2007 */
#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

#define MAX 1000

main(){
register int i, j;
int v[MAX], cmp[MAX], count, tmp, it=1;

	do{	
		if(it>1)
		  printf("\n");
		count = 1;
		while(true){
		      scanf("%d",&tmp);
		      if(tmp==-1)
		        break;
		      v[count++] = tmp;
		}
		for(i=0; i<count; i++)
		   cmp[i]=1;
		   
		for(i=count-1; i>0; i--)
		   for(j=i-1; j>=0; j--)
		      if(v[j]>v[i])
		        if(cmp[i]+1 > cmp[j])
		           cmp[j] = cmp[i]+1;
		printf("Test #%d:\n  maximum possible interceptions: %d\n",it++,cmp[1]);
		scanf("%d",&tmp);
		v[0] = tmp;
	}while(tmp!=-1);
}
