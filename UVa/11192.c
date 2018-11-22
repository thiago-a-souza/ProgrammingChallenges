/* Group Reverse */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 101

main(){
char str[MAX];
int i, j, g, n;

	scanf("%d",&g);
	while(g!=0){
		scanf("%s",str);
		g=strlen(str)/g;
		for(i=0;i<strlen(str);i=i+g){
		   j=i+g-1;
		   while(j>=i)
		    printf("%c",str[j--]);
		}
		printf("\n");
		scanf("%d",&g);
		for(i=0;i<MAX;i++)
		   str[i]='\0';
	}
}

