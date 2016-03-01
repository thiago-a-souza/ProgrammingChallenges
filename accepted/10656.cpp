#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
int n, aux;
bool  first;
	

	while(true){
		scanf("%d",&n);
		if(!n)
		  break;
		first = true;
		for(int i=0; i<n; i++){
		   scanf("%d",&aux);
		   if(aux > 0){
		      if(first){
		         printf("%d",aux);
		         first = false;
		      } else 
		         printf(" %d",aux);
		   }
		}
		if(first)
		  printf("0");
		cout << endl;
	}
}