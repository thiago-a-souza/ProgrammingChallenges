/* Babelfish - 13/06/2007 */
#include<iostream>
#include<string>
#include<map>
#include <cstdio>

using namespace std;

main(){
register int i;
int cont=1;
char str[100001][25], tmp[25];
map<string,int> names;


	cin.getline(str[cont++],25);
	while(strlen(str[cont-1])>0){
	     for(i=0; i<strlen(str[cont-1]); i++)
	        if(str[cont-1][i]==' ')
	          break;
	     names[&str[cont-1][i+1]] = cont-1;
	     str[cont-1][i]='\0';
	     cin.getline(str[cont++],25);
	}
	while((scanf("%s",tmp))!=EOF){
	     if(names[tmp]>0)
	       printf("%s\n",str[names[tmp]]);
	     else
	       printf("eh\n");
	}
	     
}

