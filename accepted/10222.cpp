#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

main(){
char src[100] =  {' ',']','[','p','o','i','u','y','t','r','e','\'',';','l','k','j','h','g','f','d','/','.',',','m','n','b','v','c','x','z','s','a','q','w' };
char dest[100] = {' ','p','o','i','u','y','t','r','e','w','q','l' ,'k','j','h','g','f','d','s','a',',','m','n','b','v','c','x','z','x','z','s','a','q','w' };
char ch;
int found = 0;


	while(true){
	     ch = getchar();
	     if(ch == EOF)
	        break;
             else if((int)ch == 13)
	              printf("\n");
	     else if(ch == ' ')
                     printf(" ");
             else {
                 ch = tolower(ch);
                 found = 0 ;
                 for(int i=0; i<100; i++)
                    if(ch == src[i]){
                       printf("%c",dest[i]);
                       found = 1;
                    }
                 if(!found)
                    printf("%c",ch);
             }	     
	}
}

