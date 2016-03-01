#include<cstdio>
#include<iostream>

#define MAX 4475

using namespace std;


int main(){
int v[MAX];
int n, cima, baixo;

	v[0] = 0;
	for(int i=1; i<MAX; i++)
	    v[i] = v[i-1] + i;
	    
	while(scanf("%d",&n) != EOF ){
	     int index = 1;
	     
	     while(n > v[index])
	          index++;
	          
	     if(index%2 == 0){
	        cima = index - (v[index] - n);
	        baixo =  1 + v[index] - n;
	     } else {
	        cima = 1 + v[index] - n;
	        baixo =  index - (v[index] - n);
	     }
	     
	     printf("TERM %d IS %d/%d\n",n, cima,baixo);
	}
}




