/* Pizza Cutting */
/* Category: math formula */
#include<iostream>

using namespace std;

main(){
long long  n;
	while(true){
		scanf("%llu",&n);
		if(n < 0)
		   break;
		n = n*(n+1)/2 + 1;
		printf("%llu\n",n);
		
	
	}

}



