#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>

#define MAX 1000

using namespace std;

char str[MAX];
int len;

int findChar(char ch){
int i, j;
bool b;
	for(i=0; i<len; i++)
	   if(str[i] == ch){
	      b = false;
	      for(j=i+1; j<len; j++){
	          if(str[j] == '='){
	             b = true;
	             j++;
	             break;
	          }
	          if(str[j] != ' ' || str[j] != '	')
	             break;
	      }
	      if(b){
	        while(j < len && (str[j] == ' ' || str[j] == '	'))
	              j++;
	        return j;
	      }
	   }
	   return -1;
}



main(){
int n;
int P, I, U;
int i, line=1;
double pp, ii, uu;


	scanf("%d\n",&n);
	while(n--){
		 cin.getline(str, MAX);
		 len = strlen(str);
         P = findChar('P');
         I = findChar('I');
         U = findChar('U');
         pp = -1.0; ii = -1.0; uu == -1.0;
         
         if(P > 0){
            pp = atof(&str[P]);
            i = P;
            while((str[i] >= '0' && str[i] <= '9') || str[i] == '.'|| str[i] == ' ' || str[i] == '	')
                  i++;
            if(str[i] == 'm')
               pp = pp*0.001;
            else if(str[i] == 'k')
                    pp = pp*1000.0;
            else if(str[i] == 'M')
                    pp = pp*1000000.0;
                
         }
         if(I > 0){
            ii = atof(&str[I]);
            i = I;
            while((str[i] >= '0' && str[i] <= '9') || str[i] == '.'|| str[i] == ' ' || str[i] == '	')
                  i++;
            if(str[i] == 'm')
               ii = ii*0.001;
            else if(str[i] == 'k')
                    ii = ii*1000.0;
            else if(str[i] == 'M')
                    ii = ii*1000000.0;
         }
         if(U > 0){
            uu = atof(&str[U]);
            i = U;
            while((str[i] >= '0' && str[i] <= '9') || str[i] == '.'|| str[i] == ' ' || str[i] == '	')
                  i++;
            if(str[i] == 'm')
               uu = uu*0.001;
            else if(str[i] == 'k')
                    uu = uu*1000.0;
            else if(str[i] == 'M')
                    uu = uu*1000000.0;

         }
         printf("Problem #%d\n", line);
         line++;
         
         if(P < 0){
            printf("P=%.2lfW\n\n",ii*uu);
         } else if(I < 0){
                  printf("I=%.2lfA\n\n",pp/uu);
         } else if(U < 0){
                  printf("U=%.2lfV\n\n",pp/ii);
         }		 
	}
}

