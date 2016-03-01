#include<iostream>
#include<cstdio>
#define MAX 200
using namespace std;

main(){
int a, b, c, d;
int a3, b3, c3;

        for(a = 2; a<= MAX; a++){
            a3 = a*a*a;
            for(b = 2; b<=MAX; b++){
                b3 = b*b*b;
                for(c = b+1; c<=MAX; c++){
                    c3 = c*c*c;
                    for(d = c+1; d<=MAX; d++)
                        if(a3 == (b3 + c3 + d*d*d)){
                          printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                        //  b = 1000;
                        //  c = 1000;
                        //  d = 1000;
                        //  break;
                        }
                }
            }
        
        }


}

