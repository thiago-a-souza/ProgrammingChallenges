#include<iostream>
#include<cstdio>

using namespace std;

main(){
int n;
        while(scanf("%d",&n) != EOF){
             if( n>0 && n <= 7)
                printf("Underflow!\n");
             else if(n > 13)
                     printf("Overflow!\n");
             else if(n <= 0 ){
                     n = -n;
                     if(n%2 == 0)
                        printf("Underflow!\n");
                     else
                        printf("Overflow!\n");
             }
             else switch(n){
                    case 8 : printf("40320\n"); break;
                    case 9 : printf("362880\n"); break;
                    case 10 : printf("3628800\n"); break;
                    case 11 : printf("39916800\n"); break;
                    case 12 : printf("479001600\n"); break;
                    case 13 : printf("6227020800\n"); break;
             
                  }
             
             
        }

}
