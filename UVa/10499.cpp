#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>

using namespace std;

/*
área da circunferência = 4*PI*r^2;
área do circulo = PI*r^2;

área de cada segmento = (área do circulo/2)*2 + área da circunferência;
área de todos segmentos = N*(área de cada segmento);

lucro = área de todos segmentos/área da circunferência;
*/


main(){
long long n;

		while(true){
		     scanf("%llu",&n);
		     if(n < 0)
		        break;
		     if(n == 1)
		       printf("0%%\n");
		     else
		       printf("%llu%%\n",(long long)round((n/4.0)*100.0));
		
		}

}