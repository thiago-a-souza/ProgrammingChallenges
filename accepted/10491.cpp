#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(){
double ncows, ncars, nshow;
double s1, s2;

	while(scanf("%lf %lf %lf",&ncows, &ncars, &nshow) != EOF){
	     s1 = (ncows/(ncows+ncars))*(ncars/(ncars+ncows-nshow-1));
	     s2 = (ncars/(ncars+ncows))*((ncars-1)/(ncars+ncows-nshow-1));
	     printf("%.5lf\n",s1+s2);
	}

	return 0;
}

