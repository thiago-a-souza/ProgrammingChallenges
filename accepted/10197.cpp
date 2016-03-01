#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 100

using namespace std;

main(){
char pt[MAX], en[MAX], root[MAX];
int len;
bool first = true;

	while(scanf("%s %s\n",pt, en) != EOF){
	     if(first)
	        first = false;
	     else
	        printf("\n");
	     len = strlen(pt);
	     printf("%s (to %s)\n",pt,en);
	     if(len < 2 || pt[len-1] != 'r' || !(pt[len-2] == 'a' || pt[len-2] == 'e' || pt[len-2] == 'i')){
	        printf("Unknown conjugation\n");
	     } else {
               
				memset(root, '\0', sizeof(root));
				for(int i=0; i<len-2; i++)
				    root[i] = pt[i];
				char tv = pt[len-2];
				printf("eu        %so\n",root);
				if(tv == 'a' || tv == 'e')
				   printf("tu        %s%cs\n",root, tv);
				else 
				   printf("tu        %ses\n",root);
				if(tv == 'a' || tv == 'e')
				   printf("ele/ela   %s%c\n",root, tv);
				else 
				   printf("ele/ela   %se\n",root);
				printf("n%cs       %s%cmos\n",(char)243,root,tv);
				if(tv == 'a' || tv == 'e')
				   printf("v%cs       %s%cis\n",(char)243,root,tv);
				else
  				   printf("v%cs       %s%cs\n",(char)243,root,tv);
  				if(tv == 'a' || tv == 'e')
				   printf("eles/elas %s%cm\n",root, tv);	     
				else
				   printf("eles/elas %sem\n",root);	     
	     }
	      
	}
	


}

