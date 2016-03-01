#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

main(){
long long a, b, c, n;
		while(true){
		     scanf("%llu",&n);
		     if(n == -1)
		        break;
		     if(n == 0){
		        printf("0 1\n");
		        continue;
		     }
		     
		     a = 1; b = 2; 
		     for(long long i=1; i<n; i++){
		         c = a + b + 1;
		         a = b;
		         b = c;
		     }
		     printf("%llu %llu\n",a,b);
		}
		
}

