#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>

#define MAX 1000000

int pos[MAX];
int sz;
char val[MAX][100];
char ans[MAX][100];
int sv;

using namespace std;



void getPositions(char str[], int len){
int i, nbr;

     i = 0;
     sz = 0; 
     while(i < len){
          if(str[i] >= '0' && str[i] <= '9'){
             nbr = atoi(&str[i]);
             pos[sz++] = nbr;
	             
	         while(i < len && !(str[i] == ((char)32)  || str[i] == ((char)9) ))	 
	              i++;               
          } else {
	             i++;
          }
     }
}

void getVals(char str[], int len){
int i, j, k, last;

	i=0;
	last = 0;
	
	while(str[0] == ((char)32) || str[0] == ((char)9)){
	      for(int j=0; j<len; j++)
	          str[j] = str[j+1];
	      len--;
	}

	while(str[len-1] == ((char)32) || str[len-1] == ((char)9)){
	      str[len-1] = str[len];
	      len--;
	}

	
	while(i < len - 1){
	     if((str[i] == ((char)32) || str[i] == ((char)9))  && 
	        (str[i+1] == ((char)32) || str[i+1] == ((char)9)) ){
	        for(int j=i; j<len; j++)
	           str[j] = str[j+1];
	        len--;
	        i--;
	     }
	     i++;
	}
	last = 0;
	sv = 0;

    for(i=0; i<=len; i++)
       if(str[i] == ((char)32) || str[i] == ((char)9) || i == len){
         for(j=last, k=0; j<i; j++, k++){
             val[sv][k] = str[j];
             
         }
         val[sv][k] = '\0';
         sv++;
         last = i+1;
         
       }


	   
}

main(){
int tests, len, i;
int nbr;
char str[MAX];
bool first = true;



		scanf("%d\n",&tests);	
		while(tests > 0){
		     cin.getline(str, MAX);
		     len = strlen(str);
		     
		     if(len == 0)
		        continue;



		     if(!first)   
		        printf("\n");

		     first = false;
		     getPositions(str,len);

		     cin.getline(str, MAX);
		     len = strlen(str);

             getVals(str,len);
             
             for(i=0; i<sz; i++){
                strcpy(ans[pos[i]-1], val[i]);
             }
             for(i=0; i<sz; i++)
                printf("%s\n",ans[i]);
             
		     tests--;
		
		}
}

