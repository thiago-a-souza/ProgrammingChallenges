#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

main(){
int ans[51], v;
int t, n;     
    ans[1] = 1;
    ans[2] = 3;
    v = 4;
	for(int i = 3; i<51; i+=2){
	    ans[i] = ans[i-1] + v;
	    ans[i+1] = ans[i] + v;
	    v += 2;
	}
	
    scanf("%d",&t);
    while(t--){
         scanf("%d",&n);
         printf("%d\n",ans[n]);
    } 
	    
}

