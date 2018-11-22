#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

main(){
map<char, int> m;
char str[300];
int len, last, curr;
        m['B'] = 1; m['F'] = 1; m['P'] = 1; m['V'] = 1;
        m['C'] = 2; m['G'] = 2; m['J'] = 2; m['K'] = 2; m['Q'] = 2; m['S'] = 2; m['X'] = 2; m['Z'] = 2;
        m['D'] = 3; m['T'] = 3;
        m['L'] = 4;
        m['M'] = 5; m['N'] = 5;
        m['R'] = 6;

        while(scanf("%s",str) != EOF ){
              len = strlen(str);
              last = -1;
              for(int i=0; i<len; i++){
                  curr = m[str[i]];
                  if( curr != 0 && last != curr )
                     printf("%d",curr);
                  last = curr;
              }
              printf("\n");
        }
        
}

