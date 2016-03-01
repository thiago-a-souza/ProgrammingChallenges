#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 101

using namespace std;

int main(){
int ans[MAX];
int input;

	ans[0] = 0;
	for(int i=1; i<MAX; i++)
	    ans[i] = ans[i-1] + i*i;

	while(1){
		scanf("%d",&input);
		if(input == 0)
		   break;
	    printf("%d\n",ans[input]);
	}	    
}

