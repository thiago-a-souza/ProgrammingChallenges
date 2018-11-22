#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

main(){
long long n, sqr;
long long dist;
int  x, y;
//printf("---> %d\n",(int)floor(sqrt(7.0))); return 0;
        while(true){
            scanf("%llu",&n);
            if( n == 0) 
               break;
            sqr = (long long) (floor(sqrt(n)));
            dist = n - (sqr*sqr);
            if( dist == 0 ){
               if(sqr%2 == 0){
                  x = sqr;
                  y = 1;
               } else {
                  x = 1; 
                  y = sqr;
               }
            } else {
               if(sqr%2 == 0){
                  if(sqr*sqr + 1 == n){
                     x = sqr + 1;
                     y = 1;
                  } else if(n < sqr*sqr + sqr + 2){
                           x = sqr + 1;
                           y = n - (sqr*sqr);
                  } else {
                          x = (sqr+1)*(sqr+1) - n + 1;
                          y = sqr + 1;
                  }
                    
               } else {
                  if(sqr*sqr + 1 == n){
                     x = 1;
                     y = sqr + 1;
                  } else if(n < sqr*sqr + sqr + 2 ){
                            x = n - (sqr*sqr);
                            y = sqr + 1;
                  } else {
                     x = sqr + 1;
                     y = (sqr+1)*(sqr+1) - n + 1;
                  }
               
               }
            }
            //printf("n=%llu ---> %d %d\n",n,x,y);
            printf("%d %d\n",x,y);
        }
        
        
        

}

