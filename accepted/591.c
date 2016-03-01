/* Box of Bricks */
#include <stdio.h>

main(){
int arr[100], sum;
int i, j, n, count;
	scanf("%d",&n);
	j=1;
	while(n!=0){
	   sum=0;
	   count=0;
	   for(i=0; i<n; i++){
	      scanf("%d",&arr[i]);
	      sum+=arr[i];
	   }
	   sum=sum/n;
	   for(i=0; i<n; i++)
	      if(arr[i]>sum)
		count=count+(arr[i]-sum);
	   printf("Set #%d\n",j);
	   printf("The minimum number of moves is %d.\n",count);
	   scanf("%d",&n);
	   printf("\n");
	   j++;
	}
}

