#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <cmath>

#define PI 3.14159265359
#define EPS 0.00000001 

using namespace std;

int p, q, r, s, t, u;

/*
f(x) = p*e^(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x^2 + u
f'(x) = -p*e^(-x) + q*cos(x) - r*sen(x) + s/(cos^2(x)) + 2*t*x
*/

double fx(double x0){
  return p*exp(-x0) + q*sin(x0) + r*cos(x0) + s*tan(x0) + t*x0*x0 + u;
}

double dx(double x0){
  return -p*exp(-x0) + q*cos(x0) - r*sin(x0) + s/(cos(x0)*cos(x0)) + 2*t*x0;
}

double newton_raphson(double x0){
double diff = 1.0;
double fx0, dx0, x1;

     if(fx(0) == 0.0)
        return 0;
    
     while(diff > EPS){
	       fx0 = fx(x0);
	       dx0 = dx(x0);
	        
	       x1 = x0 - (fx0/dx0);

           diff = abs(x1 - x0);
	      x0 = x1;
	 }
	 return x1;
}

main(){

	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) != EOF){
	     
	     if(fx(0)*fx(1) > 0.0){
	       printf("No solution\n"); 
	     } else {
	       printf("%.4lf\n",newton_raphson(0.5));
	     }
	     
	     
	}

}

