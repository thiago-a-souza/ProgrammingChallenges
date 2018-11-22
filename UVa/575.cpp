/* Skew binary - 4/10/2007*/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

main(){
char str[50];
int val[32], tam, x;
int d;
	val[0] = 1;
	for(int i=1; i<32; i++)
	   val[i] = val[i-1]*2;

	while(true){
	     scanf(" %s",str);
	     if(strlen(str) == 1 && str[0] == '0')
		return 0;
	     tam = strlen(str);
	     x = 0;
	     for(int i=0; i<strlen(str); i++){
		 d = str[i] - '0';
		 x +=  d*(val[tam]-1);
		 tam--;
	     }
	     printf("%d\n",x);
	}
	

}
