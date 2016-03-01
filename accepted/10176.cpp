#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>

#define MAX 10000
#define VAL 131071


char str[MAX];
int len;

using namespace std;

int calc(){
int base2 = 1;
int ans = 0;

	for(int i=len-1; i>=0; i--){
	    if(str[i] == '1')
	       ans = (ans + base2)%VAL;
	    base2 = (2*base2)%VAL;
	}
	if(ans == 0)
	   return 1;
	return 0;
	
}

int main(){
char ch;

	memset(str, '\0', MAX);
	while(true){
	    ch = getchar();
	    if(ch == EOF)
	       return 0;
	    if(ch == '#'){
	       if(calc())
	          printf("YES\n");
	       else
	          printf("NO\n");
	       len = 0;
	       memset(str, '\0', MAX);
	    }
	    if(ch == '0' || ch == '1')
	       str[len++] = ch;   
		
	}

	return 0;
}

