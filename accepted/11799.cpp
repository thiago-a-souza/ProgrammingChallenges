#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map> 
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack> 
#include <climits>

using namespace std;

main(){
int t, n, ans, tmp;
int line = 1;
		scanf("%d",&t);
		while(t--){
		     scanf("%d",&n);
		     ans = -1;
		     for(int i=0; i<n; i++){
		        scanf("%d",&tmp);
		        if(tmp > ans)
		           ans = tmp;
		     }
		     printf("Case %d: %d\n",line,ans);
		     line++;
		}
}
