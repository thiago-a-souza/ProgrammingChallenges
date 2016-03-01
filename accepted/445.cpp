#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 1000

using namespace std;

main(){
char str[MAX], ch;
int last, len;
bool b;
	while(true){
	     if(!cin.getline(str,MAX))
	        break;
	     len = strlen(str);

	     if(len == 0){
	        printf("\n");
	        continue;
	     }
	     else {
	        b = true;

	        for(int i=0; i<len; i++){
	            if(((int)str[i]) != 32 && ((int)str[i]) != 9){
	               b = false;
	            }
	        }
	        if(b){
	          printf("\n");
	          continue;
	        }
	     }
	        
	     for(int i=0; i<len; i++){
	        if(str[i] >= '0' && str[i] <= '9'){
	           last += ((int)str[i]) - 48;
	        } else if(str[i] == '!'){
	                last = 0;
	                printf("\n");
	        } else {
	           ch = str[i];
	           if(str[i] == 'b')
	              ch = ' ';
	           for(int j=0; j<last; j++)
	               printf("%c",ch);
	           last = 0;
	        }
	     }
	     printf("\n");
	}

}

