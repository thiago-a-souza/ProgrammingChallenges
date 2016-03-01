#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
int B, S;
int min, tmp;
int line = 1;

	while(true){
		scanf("%d %d",&B,&S);
		if(!B && !S)
		  break;
		min = 100;
		for(int i=0; i<B; i++){
		   scanf("%d",&tmp);
		   if(tmp < min)
		     min = tmp;
		}		   
		for(int i=0; i<S; i++)
		   scanf("%d",&tmp);
		if(B <= S)
		   printf("Case %d: %d\n",line++,0); 
		else
		   printf("Case %d: %d %d\n",line++,B-S,min); 
	}
}

