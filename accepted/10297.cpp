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
double D, V;
double d;

		while(true){
		     scanf("%lf %lf",&D,&V);
		     if(D == 0.0 && V == 0.0)
		        break;
		     d = (D*D*D - ((6.0*V)/PI));
		     
		     printf("%.3lf\n",pow(d,1.0/3.0));
		     
		}
}

