#include<iostream>
#include<cstdio>
#include<cstring>


#define MAX 10000

using namespace std;

int main(){
char ch;
char buff[MAX];
int index = 0;



	while(true){
	      ch = getchar();
	      if(ch == EOF) 
	         break;
	      else if(ch == ' '){
	              for(int i=index-1; i>=0; i--)
	                 printf("%c",buff[i]);
	              printf(" ");
	              index = 0;
	           }
	     else if(ch == '\n'){
	             for(int i=index-1; i>=0; i--)
	                 printf("%c",buff[i]);
	              printf("\n");
	              index = 0;
	          }
	     else {
	          buff[index++] = ch;
	     }
	}
	
}


