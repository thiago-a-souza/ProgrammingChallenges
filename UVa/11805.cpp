#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <cmath>

using namespace std;

main(){
int t, n, k, p;
int passes, index;
int line = 1;

		scanf("%d",&t);
		while(t--){
			scanf("%d %d %d",&n,&k,&p);
			passes = 0;
		    index = k;
		    while(passes < p){
		          passes++;
		          index = (index+1)%(n+1) > 0 ? (index+1)%(n+1) : 1;
		    }
		    printf("Case %d: %d\n",line,index);
		    line++;
			   
		}

}

