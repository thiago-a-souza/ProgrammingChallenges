#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

#define MAX 1010

using namespace std;

main(){
char str[MAX];
int len, odd, even;
int ans;

	while(true){
	   scanf("%s",str);
	   odd = 0; even = 0;
	   if(strcmp(str,"0") == 0)
	      break;
	   len = strlen(str);
	   for(int i=0; i<len; i+=2)
	      even += ((int)str[i]) - 48;
	   for(int i=1; i<len; i+=2)
	      odd += ((int)str[i]) - 48;
	   ans = abs(even-odd);
	   if(ans % 11 == 0)
	     printf("%s is a multiple of 11.\n",str);
	   else
	     printf("%s is not a multiple of 11.\n",str);
	   
	}

}

