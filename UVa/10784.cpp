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

/* n*(n-3)/2 = N
   n^2 - 3n >= 2N
   n^2 - 3n - 2N >= 0
  */

using namespace std;

main(){
long long N;
int line = 1;

		while(scanf("%llu",&N) != EOF){
		     if(N == 0)
		        break;
		     N = ceil((3.0 + sqrt(9.0 + 4.0*(2.0*((double)N))))/2.0);
		     printf("Case %d: %llu\n",line,N);
		     line++;
		}

}

