#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
int n, positive, zeroes;
int tmp;
int line = 1;
	while(true){
	     scanf("%d",&n);
	     if(n == 0)
	        break;
	     positive = 0; 
	     zeroes = 0;
	     for(int i=0; i<n; i++){
	        scanf("%d",&tmp);
	        if(tmp != 0)
	           positive++;
	        else
	           zeroes++;
	     }
	     printf("Case %d: %d\n",line,positive-zeroes);
	     line++;
	        
	}
}

