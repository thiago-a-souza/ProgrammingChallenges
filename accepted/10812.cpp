#include<iostream>
#include<cstdio>

using namespace std;

main(){
int n, s1, s2, x, y;

        scanf("%d",&n);
        while(n--){
             scanf("%d %d",&s1,&s2);
             x = (s1+s2)/2;
             y = s1 - x;
             if(y < 0 || x + y != s1 || x - y != s2)
                printf("impossible\n");
             else if( x > y)
                     printf("%d %d\n",x,y);
             else printf("%d %d\n",y,x);
                     
        }
}

