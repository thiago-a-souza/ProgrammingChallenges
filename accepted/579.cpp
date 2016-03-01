#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

main(){
int hour, min;
double hour_angle, min_angle;
double angle;

	while(true){
	   scanf("%d:%d",&hour,&min);
	   if(hour == 0 && min == 0)
	      return 0;

	   hour_angle = ((double)hour)*30.0 + (((double)(min))*30.0)/60.0;
	   min_angle =  ((double)min)*6.0;
	   angle = abs(hour_angle - min_angle);
	   if(angle > 180.0)
	     angle = 360.0 - angle;
	   printf("%.3lf\n",angle);
		   
	   
	}
	return 0;

}


