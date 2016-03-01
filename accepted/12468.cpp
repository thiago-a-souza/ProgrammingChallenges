#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
int a, b;
int tmp;

	while(true){
	      scanf("%d %d",&a,&b);
	      if(a == -1 && b == -1)
	         break;
	      if(a > b){
	         tmp = a;
	         a = b;
	         b = tmp;
	      }
	      if( b - a < 100 - b + a)
	         printf("%d\n",b-a);
	      else
	         printf("%d\n",100-b+a);      
	      
	}
}

