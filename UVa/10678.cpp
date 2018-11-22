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

const double PI = acos(-1.0);

using namespace std;

main(){
double a, b;
int t, d, l;

	scanf("%d",&t);
	while(t--){
	    scanf("%d %d",&d, &l);
	    a = l/2.0;
	    b = sqrt((l/2.0)*(l/2.0) - (d/2.0)*(d/2.0));
	    printf("%.3lf\n",PI*a*b);
	}
}

