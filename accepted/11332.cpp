#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

using namespace std;

main(){
long long n, aux;

		while(true){
		     scanf("%llu",&n);

             if(n == 0)
		        break;
		     while(n > 9){
		          aux = n;
		          n = 0;
		          while(aux > 0){
		               n += aux%10;
		               aux = aux/10;
		          }  
		     }
		       printf("%llu\n",n);
		     
		}
}

