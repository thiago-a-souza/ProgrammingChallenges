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

#define ABS(x) ((x < 0) ? (-x) : (x))
using namespace std;

main(){
double x1, y1, x2, y2, x3, y3;
double xc, yc, radius;
double z1, z2, z3;
double d, da, db, dc;
double A, B, C;
		while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3) != EOF){
		      z1 = -1.0*(x1*x1) - (y1*y1);
		      z2 = -1.0*(x2*x2) - (y2*y2);
		      z3 = -1.0*(x3*x3) - (y3*y3);
		      
		      d = x1*y2 + x3*y1 + x2*y3 - (x3*y2 + x2*y1 + x1*y3);
		      da = z1*y2 + z3*y1 + z2*y3 - (z3*y2 + z2*y1 + z1*y3);
		      db = x1*z2 + x3*z1 + x2*z3 - (x3*z2 + x2*z1 + x1*z3);
		      dc = x1*y2*z3 + x3*y1*z2 + x2*y3*z1 - (x3*y2*z1 + x2*y1*z3 + x1*y3*z2);
		      A = da/d;
		      B = db/d;
		      C = dc/d;
		      
		      xc = -(A/2.0);
		      yc = -(B/2.0);
		      radius = sqrt(xc*xc + yc*yc - C);
		      
		      printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", xc < 0 ? '+' : '-',
		             abs(xc), yc < 0 ? '+' : '-', abs(yc), radius );
		      
		      printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n",A < 0 ? '-' : '+', 
		      abs(A), B < 0 ? '-' : '+', abs(B), C < 0 ? '-' : '+', abs(C));
		      
		      printf("\n");
		}
}

