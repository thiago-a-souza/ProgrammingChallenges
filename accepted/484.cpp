#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

main(){
map<int,int> m1, m2;
int n, count=1;

        while(scanf("%d",&n) != EOF){
             if(m2[n] == 0)
                m1[count++] = n;
             m2[n] = m2[n] + 1;
        }
        for(int i=1; i<count; i++)
            printf("%d %d\n",m1[i],m2[m1[i]]);
              
        

}

