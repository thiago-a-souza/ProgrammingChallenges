/* Primary Arithmetic */
#include <stdio.h>
#include <string.h>

void empurra(char *str);

main(){
char num1[14], num2[14];
int i, x, sobeum, cont;




scanf("%s", num1);
scanf("%s", num2);

do{
sobeum=0;
cont=0;
empurra(num1);
empurra(num2);
	for(i=0; i<13; i++){
	  x=num1[i]+num2[i]+sobeum-96;
	  sobeum=x/10;
	  if(sobeum>=1)
	    cont++;
	}
	if(cont==0)
	  printf("No carry operation.\n");
	else
	    if(cont==1)
	  	printf("1 carry operation.\n");
	    else
		printf("%d carry operations.\n", cont);
	for(i=0; i<13; i++){
	num1[i]='\0';
	num2[i]='\0';
	}
	scanf("%s", num1);
	scanf("%s", num2);

}while(num1[0]!='0' || num2[0]!='0');

} 


void empurra(char *str){
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

	for(i=strlen(str); i<13; i++)
	   str[i]='0';
	str[13]='\0';
}

