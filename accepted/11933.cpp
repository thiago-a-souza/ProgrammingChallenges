#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 50

using namespace std;

bool src[MAX];
int sz_src, sz_a, sz_b;

void decToBin(int n){

	sz_src = 0;
	while(n > 0){
		src[sz_src++] = n%2;
		n = n/2;
	}
}



int binToDec(bool *x){
int mul = 1;
int ans = 0;
	
	      
	for(int i=0; i<sz_src; i++){
	   if(x[i])
	      ans += mul;
	   mul = mul*2;
	}
	return ans;
	    
}

main(){
int n;
bool last;
bool a[MAX], b[MAX];

	while(true){
		scanf("%d",&n);
		if(n == 0)
		   break;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		   
		decToBin(n);

		last = true;
		for(int i=0; i<sz_src; i++){
		   if(src[i]){
		      if(last){
		        a[i] = true;
		        last = false;
		      } else 
		          last = true;
		   }
		}
				
		last = true;
		for(int i=0; i<sz_src; i++){
			if(src[i]){
			   if(!last){
			      b[i] = true;
			      last = true;
			   } else
			      last = false;
			}
		}
		
		printf("%d %d\n",binToDec(a), binToDec(b));
		   
	}

}