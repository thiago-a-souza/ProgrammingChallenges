/* Is This Integration? - 05/08/2007*/
#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
#define PI acos(-1)

main(){
double integral, meio, semi_circ, a, b;
double d, dx, dy, dz;
	while(cin>>a){
	      meio=a/2.0;
	      integral = (meio/2.0)*(sqrt(a*a-meio*meio))+(a*a/2.0)*(asin(0.5));
	      semi_circ=(a*a*PI)/4.0;
	      b=a*a-(PI*a*a)/4.0;
	//      cout << integral;
	      d=0.5;
	      dx=2.0*integral+0.5*b-a*a;
	      dx=dx/d; dx=dx*4.0;
	      dy=2.5*a*a-2.0*b-4.0*integral;
	      dy=dy/d;
	      dz=0.5*a*a-integral;
	      dz=dz/d; dz=dz*4.0;
	      printf("%.3lf %.3lf %.3lf\n",dy,dx,dz);
	}
}
