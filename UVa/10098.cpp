#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>

using namespace std;

main(){
int n, length;
char str[100];
set<string> s;
        scanf("%d",&n);
        while(n--){
             scanf("%s",str);
             length = strlen(str);
             sort(str,str+length);
             s.clear();
             do{
                if(s.count(str) == 0){
                   s.insert(str);
                   printf("%s\n",str);
                }
             }while(next_permutation(str,str+length));
               printf("\n");
        }

}

