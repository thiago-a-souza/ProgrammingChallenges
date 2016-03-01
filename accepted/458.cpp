#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
char ch[10000];

	while(scanf("%s",ch) != EOF ){
		for(int i=0; i<strlen(ch); i++)
		    printf("%c",(char)ch[i]-7);
		printf("\n");
	}

}


