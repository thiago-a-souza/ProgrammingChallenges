/* Power of Cryptography - 3/10/2007 */
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

main(){
double n, p, k;

	while(scanf("%lf %lf", &n, &p) == 2){
		k = pow(10,(log10(p)/n));
		printf("%.0lf\n",k);
	}
	

}



