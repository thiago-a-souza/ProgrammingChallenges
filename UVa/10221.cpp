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
double s, a, rad, circ;
char str[10];

	while(scanf("%lf %lf %s",&s,&a,str) != EOF){
		if(strcmp(str,"min") == 0)
		  a = a/60.0;

		if( 360.0 - a <= 0.001)
		   printf("%.6lf %.6lf\n",0.0,0.0);
		else {
		   if(a >= 180.0)
		      a = 360.0 - a;
		   rad = (a*PI)/180.0;   
		   printf("%.6lf %.6lf\n",rad*(6440.0+s),2.0*(6440.0+s)*sin(rad/2.0));
		}
		 	     
	}
}

