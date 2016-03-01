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
int t, l, w, h;
int line = 1;

	scanf("%d",&t);
	while(t--){
	    scanf("%d %d %d",&l,&w,&h);
	    if(l > 20 || w > 20 || h > 20)
	       printf("Case %d: bad\n",line);
	    else
	       printf("Case %d: good\n",line);
	    line++;
	}
}

