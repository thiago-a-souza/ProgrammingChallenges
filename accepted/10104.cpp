#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>

using namespace std;


/*
Algoritmo extendido de Euclides.
x1 = 1; y1 = 0; x2=0; y2 = 1;

ax + by = d

x(i) = x(i-2) - q(i)*x(i-1);
y(i) = y(i-2) - q(i)*y(i-1);

*/

main() {
int a,b, q, r;
int x1, y1, x2, y2, x,y;
        
        while(scanf("%d%d",&a,&b) == 2) {
                x1 = 1; y2 = 1;
                y1 = 0; x2 = 0;
                while (b>0){
                        q=a/b;
                        r=a-q*b;
                        
                        x=x1-q*x2; 
                        y=y1-q*y2;
                        a=b;
                        x1=x2; 
                        y1=y2;
                        b=r; 
                        x2=x; 
                        y2=y;
                }
                printf("%d %d %d\n",x1,y1,a);
        }
}

