/* Reverse and Add */
#include <stdio.h>
#include <string.h>

void inverte(char *num2){
char tmp[2];
int i, j;

	tmp[1]='\0';
	i=0;
	j=strlen(num2)-1;
if(strlen(num2)>=2)
	while(i<j){
	   tmp[0]=num2[i];
	   num2[i]=num2[j];
	   num2[j]=tmp[0];
	   i++;
	   j--;
	}
}

void inverte_zero(char *str){
int i, j;
char tmp[2];

	tmp[1]='\0';
	i=0;
	j=strlen(str)-1;
if(strlen(str)>=2)
	while(i<j){
	   tmp[0]=str[i];
	   str[i]=str[j];
	   str[j]=tmp[0];
	   i++;
	   j--;
	}
	for(i=strlen(str); i<14; i++)
	   str[i]='0';
	str[14]='\0';
}

void soma(char *num1){
int i, x, sobeum=0;
char num2[15];

	strcpy(num2,num1);

	for(i=strlen(num2); i<14; i++)
	   num2[i]='0';
	num2[14]='\0';

	inverte_zero(num1);

	for(i=0; i<11; i++){
	  x=num1[i]+num2[i]+sobeum-96;
	  sobeum=x/10;
	  x=(x%10)+48;
	  num1[i]=x;
	}
	for(i=13; i>=0; i--)
	   if(num1[i]=='0')
		num1[i]='\0';
	   else
		i=-1;
	inverte(num1);
}

int palindrome(char *num1){
char num2[15];

	strcpy(num2,num1);
	inverte(num2);

	if((strcmp(num1,num2))==0)
	  return 1;
	return 0;
}

void limpa(char *num1){
int i;

	for(i=0; i<15; i++)
	  num1[i]='\0';
}

main(){
char num1[15];
int i, j, x, n;
	scanf("%d", &n);
	for(j=0; j<n; j++){
		scanf("%s", num1);
		if(strlen(num1)>1){
		i=0; x=0;
		while(x!=1 && i<1000 && strlen(num1)<=10){
		   soma(num1);
		   x=palindrome(num1);
		   i++;
		}
		if(x==1)
		printf("%d %s\n", i, num1);
		}
		limpa(num1);
	}
}

