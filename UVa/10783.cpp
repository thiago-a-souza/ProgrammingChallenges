#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

main(){
int T, a, b, count;
int lab = 1;
     scanf("%d",&T);
     while(T--){
        scanf("%d",&a);
        scanf("%d",&b);
        count = 0;
        
        if(a%2 == 0)
          a++;
        if(b%2 == 0)
          b--;
          
        for(int i=a; i<=b; i+=2)
            count+=i;
        printf("Case %d: %d\n",lab,count);
        lab++;
     }

}

