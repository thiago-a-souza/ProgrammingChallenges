/* The Knights Of The Round Table */
#include<stdio.h>
#include<math.h>

main(){
double a, b, c, s, r;

	while((scanf("%lf %lf %lf",&a,&b,&c))!=EOF){
	      if(a==0 || b==0 || c==0)
		printf("The radius of the round table is: 0.000\n");
	      else{
	          s = (a+b+c)/2;
	          r = (sqrt(s*(s-a)*(s-b)*(s-c)))/s;
	          printf("The radius of the round table is: %0.3lf\n",r);
	      }
	}

}

