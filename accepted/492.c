/* Pig-Latin - 13/06/2007 */
#include <stdio.h>

int is_vowel(char x){

	if(x=='a' || x=='A' || x=='e' || x=='E' || x=='i'|| x=='I'|| 
	   x=='o' || x=='O' || x=='u' || x=='U')
	  return 1;
	return 0;
}



main(){
int index=0;
char str[1000];
char ch;

	while((ch=getchar())!=EOF){
	     if((ch>=65 && ch<=90) || (ch>=97 && ch<=122))
	       str[index++]=ch;
	     else{
	     	 str[index]='\0';
	         if(is_vowel(str[0]) && index>0)
	           printf("%say",str);
	         else
	             if(index>0)
	               printf("%s%cay",&str[1],str[0]);
	         printf("%c",ch);
	         index = 0;
	     }     
	}
}

