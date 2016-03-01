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
int n, sum, count;
int t = 1;
		while(true){
		     scanf("%d",&n);
		     if(n < 0)
		        break;
		     sum = 1;
		     count = 0;
		     while(sum < n){
		          sum = 2*sum;
		          count++;
		     }
		     printf("Case %d: %d\n",t,count);      
		     t++;
		}
		

}