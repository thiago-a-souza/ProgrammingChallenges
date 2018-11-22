#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define PI 3.14159265359

using namespace std;

main(){
double sides, radius;

		while(scanf("%lf %lf",&radius, &sides) != EOF){
		      printf("%.3lf\n",((radius*radius*sin(((2.0*PI)/sides)))/2.0)*sides);
		}
}


