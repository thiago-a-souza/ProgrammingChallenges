#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

using namespace std;

#define MAX 50000
#define INF 2000000000

int height[MAX];
int mid;

void binarySearch(int start, int end, int key){

 	while(end - start > 0){
          int temp = (start + end)/2;
	      if( temp == mid )
	          return;
          mid = temp;
          if(height[mid] == key)
	         return;
	      if(height[mid] < key)
	         start = mid;
	      else
	         end = mid;
	      binarySearch(start, end, key);
	      return;
	}
}


int main(){
int N, Q, last=0;
int key;
int aux;

    scanf("%d", &N);
	for(int i=0; i<N; i++){
	   scanf("%d", &aux);
	   if(last == 0)
	      height[last++] = aux;
	   else if(height[last-1] != aux)
	            height[last++] = aux;
	}
	   
	   
	scanf("%d",&Q);
	
	for(int i=0; i<Q; i++){
	   scanf("%d",&key);
	   mid = 0;
       binarySearch(0, last, key);

	   if(height[mid] == key){
	      if(mid - 1 >= 0)
	        printf("%d", height[mid-1]);
	      else
	        printf("X");
	   
	      if(mid + 1 < last)
	         printf(" %d\n", height[mid+1]);
	      else
	         printf(" X\n");  
	   } else {
	       if(height[mid] < key)
	          printf("%d", height[mid]);
	       else if(mid - 1 >= 0) 
	               printf("%d", height[mid-1]);
	       else printf("X");
	       
	       if(height[mid] > key)
	          printf(" %d\n", height[mid]);
	       else if(mid + 1 < last)
	               printf(" %d\n", height[mid+1]);
	       else printf(" X\n");	            
	   }
	   

	
	}

	return 0;
}

