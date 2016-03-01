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

using namespace std;

main(){
int t, a, b, c;
int cont = 1;
	scanf("%d",&t);
	while(t--){
	     scanf("%d %d %d",&a,&b,&c);
	     if(a > b && a > c){
	       if(b > c)
	         printf("Case %d: %d\n",cont,b);
	       else 
	         printf("Case %d: %d\n",cont,c);
	     } else if( b > a && b > c) {
	               if(a > c)
	                  printf("Case %d: %d\n",cont,a);
	               else
	                  printf("Case %d: %d\n",cont,c);
	     } else if(c > a && c > b){
	               if(a > b)
	                 printf("Case %d: %d\n",cont,a);
	               else
	                 printf("Case %d: %d\n",cont,b);
	     }
	     cont++;
	}
}

