/* Where is the Marble? - 14/06/2007 */
#include<stdio.h>
#include<stdlib.h>

#define MAX 10001

int v[MAX];

int compara(const void *a, const void *b){
int *x, *y;

	x=(int*)a;
	y=(int*)b;
	if(*x>*y)
	  return 1;
	if(*x<*y)
	  return -1;
	return 0;
}

int binarySearch(int query, int n){
int low, mid, high, firstfound;
	low = 1;
	high = n;
	firstfound = -1;
	while(low<=high){
	     mid=(low+high)/2;
	     if(v[mid]==query && low==mid)
	       return mid;
	     else
	       if(v[mid]==query)
	          firstfound = mid;
	     if(v[mid]<query)
	       low = mid+1;
	     else
	       high = mid-1;
	}
	return firstfound;
}

main(){
register int i;
int n, q, query, rs, scenario;

	scenario = 1;
	scanf("%d %d",&n,&q);
	v[0]=-30;
	while(n!=0 && q!=0){
	     for(i=1; i<=n; i++)
	        scanf("%d",&v[i]);
	     qsort(v,n+1,sizeof(int),compara);
	     printf("CASE# %d:\n",scenario);
	     scenario++;
	     for(i=0; i<q; i++){
	        scanf("%d",&query);
	        rs = binarySearch(query, n);
	        if(rs>0)
	          printf("%d found at %d\n",query,rs);
	        else
	          printf("%d not found\n",query);
	     }
	     scanf("%d %d",&n,&q);
	}
	
}

