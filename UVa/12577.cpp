#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
char str[100];
int len;
int line = 1;

	while(true){
	     scanf("%s",str);
	     len = strlen(str);
	     if(len == 1)
	        break;
	     if(len == 4)
	        printf("Case %d: Hajj-e-Akbar\n",line);
	     else
	        printf("Case %d: Hajj-e-Asghar\n",line);
	     line++;
	     
	}
}

