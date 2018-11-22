#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 110
using namespace std;

main(){
char str[MAX][MAX];
int index = 0, max_len = 0;

        for(int i=0; i<MAX; i++)
           for(int j=0; j<MAX; j++)
               str[i][j] = ' ';
        while(gets(str[index++]))
         if(strlen(str[index-1]) > max_len)
            max_len = strlen(str[index-1]);
        
        index--;
        for(int j=0; j<max_len; j++){
           for(int i=index-1; i>=0 ; i--){
              if(str[i][j] == '\0' || str[i][j] == '\n')
                 printf(" ");
              else
                 printf("%c",str[i][j]);
           }
           printf("\n");
        }
        

}

