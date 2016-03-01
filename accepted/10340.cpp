#include<iostream>
#include<cstdio>
#include<cstring>

#define MAX 100000

using namespace std;

main(){
char s[MAX], t[MAX];
int s_length, t_length, count;

     while(scanf("%s %s",&s,&t) != EOF){
       s_length = strlen(s);
       t_length = strlen(t);

       count = 0;
       for(int i=0; i<t_length; i++)
           if(count < s_length && t[i] == s[count])
              count++;

       if(count == s_length)
          printf("Yes\n");
       else
          printf("No\n");
     }

}

