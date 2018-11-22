/* Common Permutation */
#include <iostream>
#include <cstdio>

using namespace std;

#define MAX1 1001
#define MAX2 30

int readLine(char *str){
char ch;
int i=0;

	while((ch=getchar())!='\n'){
	     if(ch==EOF)
	       return -1;
	     str[i++]=ch;
	}
	str[i]='\0';
	return 1;

}

main(){
register int i, j, count=0;
int freq1[MAX2], freq2[MAX2];
char str1[MAX1], str2[MAX1];



	while(readLine(str1)>0 && readLine(str2)>0){
		for(i=0; i<MAX2; i++){
		   freq1[i]=0;
		   freq2[i]=0;
		}
		for(i=0; i<strlen(str1); i++)
		   if(str1[i]<=122)
		     freq1[str1[i]%97]++;
		for(i=0; i<strlen(str2); i++)
		   if(str2[i]<=122)
		     freq2[str2[i]%97]++;
	
		for(i=0; i<=26; i++)
		   if(freq1[i]>0 && freq2[i]>0)
		      if(freq1[i]<freq2[i])
		        for(j=0; j<freq1[i]; j++)
		            printf("%c", i+97);
		      else
		          for(j=0; j<freq2[i]; j++)
		            printf("%c", i+97);
		cout << endl;
	}

}

