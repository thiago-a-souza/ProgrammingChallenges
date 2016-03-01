#include<iostream>
#include<cstdio>

using namespace std;

main(){
char ch;
bool first = true;

        while( true ){
             ch = getchar();
             if( ch == EOF )
                break;
             if(ch == '"'){
                if(first){
                   printf("``");
                   first = false;
                } else {
                   printf("''");
                   first = true;
                }
             } else {
                printf("%c",ch);
             }
             
        }

}

