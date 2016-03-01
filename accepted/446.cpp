#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 1000

using namespace std;

int ans[MAX];
int sz;

void toBinary(int v){

	sz = 0;
	while(v > 0){
	    ans[sz++] = v%2;
	    v = v/2;
	}


}

main(){
char str1[MAX], str2[MAX], str3[MAX];
int len1, len3;
int n, val;
int nbr1, nbr2, tmp;

		scanf("%d",&n);
		while(n--){
		     scanf("%s",str1);
		     scanf("%s",str2);
		     scanf("%s",str3);
		     len1 = strlen(str1);
		     len3 = strlen(str3);
		     
		     tmp = 1;
		     nbr1 = 0;
		     for(int i=len1-1; i>=0; i--){
		        if(str1[i] >= 'A' && str1[i] <= 'F')
		           nbr1 += (((int)str1[i] - 55)*tmp);
		        else
		           nbr1 += (((int)str1[i] - 48)*tmp);
		        tmp = tmp*16;
		     }
		     
		     tmp = 1;
		     nbr2 = 0;
		     for(int i=len3-1; i>=0; i--){
		        if(str3[i] >= 'A' && str3[i] <= 'F')
		           nbr2 += (((int)str3[i] - 55)*tmp);
		        else
		           nbr2 += (((int)str3[i] - 48)*tmp);
		        tmp = tmp*16;
		     }
		     
		     if(strcmp(str2,"+") == 0)
		        val = nbr1 + nbr2;
		     else
		        val = nbr1 - nbr2;
		    
		    toBinary(nbr1);
		    for(int i=0; i<13-sz; i++)
		       printf("0");
		    for(int i=sz-1; i>=0; i--)
		       printf("%d",ans[i]);
		    
		    printf(" %s ",str2);
		       
		    toBinary(nbr2);
		    for(int i=0; i<13-sz; i++)
		       printf("0");
		    for(int i=sz-1; i>=0; i--)
		       printf("%d",ans[i]);
		    
            printf(" = %d\n",val);
		     
		               
		  
		     
		}
}

