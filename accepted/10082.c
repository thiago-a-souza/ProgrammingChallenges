/* WERTYU */
#include <stdio.h>
#include <string.h>


int main(){
char str[]={"1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./"};
char leit[2], ch, *p;
int i, n;

	leit[1]='\0';
	while(1){
	     while((ch=getchar())!='\n')
		  if(ch==EOF)
		     return 1;
		  else
		      if(ch==' ')
			 printf(" ");
		      else{
		         leit[0]=ch;
			 p=strstr(str,leit);
			 *(p--);
			 leit[0]=p[0];
			 printf("%s",leit);
		      }
	     printf("\n");
	}
	return 1;

}

