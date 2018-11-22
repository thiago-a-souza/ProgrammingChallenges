#include<iostream>
#include<cstdio>

using namespace std;

main(){
long long a, a2, l, sz;
int line = 1;
        while(true){
             scanf("%llu %llu",&a,&l);
             a2 = a;
             sz = 1;
             if(a < 0 && l < 0)
                break;
             while(a != 1 && a <= l && a >= 0){
                   while(a%2 == 0){
                        a = a/2;
                        sz++;
                   }
                   while(a > 1 && a%2 == 1){
                        a=a*3 + 1;
                        if(a <= l && a>=0)
                           sz++;
                        else
                           break;
                   }
             }
             printf("Case %d: A = %d, limit = %d, number of terms = %d\n",line,a2,l,sz);
             line++;
        }
}

