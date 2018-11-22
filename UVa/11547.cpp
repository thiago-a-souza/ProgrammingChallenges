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
int t, n;
long long ans;

		scanf("%d",&t);
		while(t--){
		      scanf("%d",&n);    
              ans = (((((n*567)/9)+7492)*235)/47)-498;
              if(ans < 0)
                 ans = -ans;
              ans = ans/10;
              printf("%d\n", (int)ans%10);
              
		}
}