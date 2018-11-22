#include<iostream>
#include<cstdio>
#define MAX 1000000

using namespace std;

main(){
char str[MAX];
int a, b, n;
int tmp, line =1;
bool bo;
        while(scanf("%s",str) != EOF ){
             scanf("%d",&n);
             printf("Case %d:\n",line);
             line++;
             for(int i=0; i<n; i++){
                 scanf("%d %d",&a, &b);
                 if(a > b){
                    tmp = a;
                    a = b; 
                    b = tmp;
                 }
                 bo = true;
                 for(int j=a; j<=b; j++)
                    if(str[a] != str[j]){
                       bo = false;
                       break;
                    }
                 if(bo)
                   printf("Yes\n");
                 else
                   printf("No\n");                 
             }
             
        }


}


