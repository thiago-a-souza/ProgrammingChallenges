#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

main(){
int code[30] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
char str[1000];
int len;

	while(cin.getline(str,1000)){
	    len = strlen(str);
	    for(int i=0; i<len; i++)
	       if(str[i] >= 'A' && str[i] <= 'Z')
	          printf("%d",code[((int)str[i] - (int)'A')]);
	       else 
	          printf("%c",str[i]);
	    printf("\n");
	}

}

