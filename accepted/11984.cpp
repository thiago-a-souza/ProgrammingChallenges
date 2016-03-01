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
int T, C, F;
int line = 1;
double tmp;

	scanf("%d",&T);
	while(T--){
	     scanf("%d %d",&C,&F);
	     tmp = 1.8*C + 32;   
	     tmp = ((F+tmp-32.0)*5.0)/9.0;
	     printf("Case %d: %.2lf\n",line,tmp);
	     line++;
	}
}

