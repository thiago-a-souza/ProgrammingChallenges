#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 30

using namespace std;

main(){
int n, index, count;
char str[MAX];

		while(true){
			  scanf("%d",&n);
			  if(n == 0)
			     break;
			  index = 0;
			  count = 0;
			  while(n > 0){
			        if(n%2 == 0)
			           str[index++] = '0';
			        else
			           str[index++] = '1';
			        n = n/2;
			  }
			  for(int i=0; i<index; i++)
			      if(str[i] == '1')
			         count++;
			  printf("The parity of ");
			  for(int i=index-1; i>=0; i--)
			      printf("%c",str[i]);
			  printf(" is %d (mod 2).\n", count);
			     
		}
}

