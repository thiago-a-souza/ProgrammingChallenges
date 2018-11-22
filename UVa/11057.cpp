#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 10001

using namespace std;

int v[MAX];

int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int binarySearch(int start, int end, int key){

	if(start > end)
	   return -1;
	int mid = (start + end)/2;
	if(v[mid] > key)
	   return binarySearch(start, mid-1, key);
	if(v[mid] < key)
	   return binarySearch(mid + 1, end, key);
	return mid;
}

main(){
int n, money;
int ans, tmp;
int a, b, aux;
int x, y;
	while(scanf("%d",&n) != EOF){
	     for(int i=0; i<n; i++)
	        scanf("%d",&v[i]);
	     scanf("%d",&money);
	     qsort(v, n, sizeof(int), cmp);
	     x = 0; y = 99999999;
	     for(int i=0; i<n; i++){
	        if(v[i] > money)
	          continue;
	          
	     	tmp = binarySearch(0,n,money-v[i]);
	     	if(tmp >= 0){
	     	   a = money - v[i];
	     	   b = v[i];
	     	   if(a > b){
	     	      aux = a;
	     	      a = b;
	     	      b = aux;
	     	   }
	     	   if(b - a <  y - x){
	     	      x = a;
	     	      y = b;
	     	   }
	     	   
	     	}
	     }
	     
	     printf("Peter should buy books whose prices are %d and %d.\n\n",x,y);

	     
	}
}

