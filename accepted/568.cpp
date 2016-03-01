#include<iostream>
#include<cstdio>
#define MAX 10000


main(){
int v[MAX+1];
long x, y;



        x = 1;
        for(int i=1; i<=MAX; i++){
            x = x*i;
            while( x%10 == 0)
                  x = x/10;
            x = x%100000;
            
            y = x;
            while(y%10 == 0)
                  y = y/10;
            v[i] = y%10;
        }

        while(scanf("%d",&x) != EOF ){
            printf("%5d -> %d\n",x,v[x]);
        }
            
        

}
