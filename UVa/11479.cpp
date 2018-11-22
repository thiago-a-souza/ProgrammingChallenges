#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

main(){
long long t, a, b, c;
int nbr = 1;
bool invalid;

		scanf("%llu",&t);
		while(t--){
		     scanf("%llu %llu %llu",&a,&b,&c);
		     invalid = false;
		     if(a < 0 || b < 0 || c < 0)
		        invalid = true;
		     else if(!(abs(b-c) < a && a < b+c))
		            invalid = true;
		     if(invalid)
		        printf("Case %d: Invalid\n",nbr);
		     else if(a == b && b == c)
  		             printf("Case %d: Equilateral\n",nbr);
		     else if(a == b || a == c || b == c)
		             printf("Case %d: Isosceles\n",nbr);
		     else printf("Case %d: Scalene\n",nbr);
		     nbr++;
		     
		}
}

