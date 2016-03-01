#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 100

using namespace std;

main(){
long long n;
int v[MAX], sz;

		while(true){
		     scanf("%llu",&n);
		     if(n < 0)
		       break;
		     if(n == 0){
		       printf("0\n");
		       continue;
             }
		     sz = 0;
		     while(n > 0){
		          v[sz++] = n%3;
		          n = n/3;
		     }
		     for(int i=sz-1; i>=0; i--)
		         printf("%d",v[i]);
		     printf("\n");
		}


}

