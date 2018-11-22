#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
int tests;
char str[10];
int len;

	scanf("%d",&tests);
	while(tests--){
	      scanf("%s",str);
	      len = strlen(str);
	      if(len == 3){
	         if((str[0] == 'o' && str[1] == 'n') || (str[0] == 'o' && str[2] == 'e') || (str[1] == 'n' && str[2] == 'e'))
	            printf("1\n");
	         else if((str[0] == 't' && str[1] == 'w') || (str[0]=='t' && str[2] == 'o') || (str[1] == 'w' && str[2] == 'o'))
	                 printf("2\n");
	      } else 
	         printf("3\n");
	}
}

