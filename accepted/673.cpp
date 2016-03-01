#include<iostream>
#include<cstdio>
#define MAX 100000
using namespace std;

main(){
int lines, pos, valid;
char str[MAX];
char ch;

   scanf("%d\n",&lines);

   while(lines--){
      pos = 0; 
      ch = getchar();
      valid = 1;

      while(ch != '\n' && ch != EOF){
           if(ch == '(' || ch == '[')
             str[pos++] = ch;
           else if(pos > 0 && (ch == ')' || ch == ']')){
              if( (ch == ')' && str[pos-1] != '(') || (ch == ']' && str[pos-1] != '[') )
                 valid = 0;
              else
                 pos--;
           } else if( ch == ')' || ch == ']')
                     valid = 0;
          ch = getchar();
      }
      if( valid > 0 && pos == 0 )
         printf("Yes\n");
      else
         printf("No\n");
   }
   

}
