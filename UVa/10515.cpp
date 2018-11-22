#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>

#define MAX 200

using namespace std;

int main(){
char n[MAX], m[MAX];
int len1, len2;
int n1, m1, tmp, ans;

	while(true){
	   scanf("%s %s",n,m);
	   len1 = strlen(n);
	   len2 = strlen(m);
	   if(len1 == 1 && len2 == 1 && strcmp(n,"0") == 0 && strcmp(m,"0") == 0)
	      break;
	   n1 = atoi(&n[len1-1]);
	   if(len2 > 1)
	     m1 = atoi(&m[len2-2]);
	   else
	     m1 = atoi(&m[len2-1]);
	   
	   if(len2 == 1 && m1 == 0)
	     printf("1\n");
	   else if(n1 == 0 || n1 == 1 || n1 == 5 || n1 == 6)
	     printf("%d\n", n1);
	   else {
	   	tmp = m1%4;
	   	if(tmp == 0) 
	   	   tmp = 4;
	   	ans = 1;
	   	for(int i=0; i<tmp; i++)
	   	   ans = ans*n1;
	   	ans = ans%10;
	   	printf("%d\n",ans);
	   }
	}
}

