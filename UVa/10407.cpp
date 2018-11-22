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

#define MAX 1001
#define INF 1<<25
using namespace std;

int gcd(int a, int b){
      if( b == 0)
         return a;
    return gcd(b,a%b);
}

main(){
int min, ans, n, len;
int v[MAX], s[MAX];

	while(true){
	     scanf("%d",&v[0]);
	     if(v[0] == 0)
	        break;
	     min = v[0];
	     n = 1;
	     while(true){
	         scanf("%d",&v[n]);
	         if(v[n] == 0)
	            break;
	         if(v[n] < min)
	            min = v[n];
	         n++;
	     }
	     
	     if(n == 2){
	        if(v[0] < v[1])
	          printf("%d\n",v[1]-v[0]);
	        else
	          printf("%d\n",v[0]-v[1]);
	        continue;
	     }
	     
	     len = 0;
	     for(int i=0; i<n; i++){
	         if(v[i] - min != 0)
	            s[len++] = v[i] - min;
	     }

	     ans = gcd(s[0], s[1]);

	     for(int i=2; i<len; i++)
	           ans = gcd(ans, s[i]);

	     printf("%d\n",ans);
	     
	}
}

