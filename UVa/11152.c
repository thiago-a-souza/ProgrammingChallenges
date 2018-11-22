/* Colourful Flowers */
#include <stdio.h>
#include <math.h>

#define PI acos(-1)

main(){
double a, b, c, p, area, r1, r2;
double sun, vio, ros;

	while((scanf("%lf %lf %lf",&a,&b,&c))!=EOF){
	     p=(a+b+c)/2;
	     area = sqrt(p*(p-a)*(p-b)*(p-c));
	     r1 = (a*b*c)/(4*area);
	     r2 = area/p;
	     sun = PI*r1*r1 - area;
	     ros = PI*r2*r2;
	     vio = area - ros;
	     printf("%.4lf %.4lf %.4lf\n",sun, vio, ros);
	}
}

