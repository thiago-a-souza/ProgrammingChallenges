#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#define MAX 1000

using namespace std;

int main(){
int n, len;
char str[MAX];

	scanf("%d",&n);
	while(n--){
	    scanf(" %s",str);
	    len = strlen(str);

	    
	    if( ( len == 1  &&  ( strcmp(str,"1") == 0 || strcmp(str,"4") == 0 ) ) ||
	    (len == 2 && strcmp(str,"78") == 0))
	       printf("+\n");
	    else if(len >= 2 && str[len-2] == '3' && str[len-1] == '5')
	            printf("-\n");
	    else if(len >= 2 && str[0] == '9' && str[len-1] == '4')
	            printf("*\n");
	    else if(len >= 3 && str[0] == '1' && str[1] == '9' && str[2] == '0')
	            printf("?\n");
	    

	}


}