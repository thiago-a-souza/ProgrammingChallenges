#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>

char input[13000], output[13000];
int len_in, len_out;

using namespace std;

bool checkPE(){
char a[13000], b[13000];
int len_a=0, len_b=0;

  memset(a,'\0', sizeof(a));
  memset(b,'\0', sizeof(b));
  
  for(int i=0; i<len_in; i++)
     if(input[i] >= '0' && input[i] <= '9'){
        a[len_a] = input[i];   
        len_a++;
     }
  for(int i=0; i<len_out; i++)
      if(output[i] >= '0' && output[i] <= '9'){
         b[len_b] = output[i];
         len_b++;
      }
  if((len_a == 0 && len_b == 0) || strcmp(a,b) == 0)
     return true;
  return false;
}

main(){
char str[200];

int n, m, tmp;
int line = 1;

	while(gets(str) != NULL){
	     n = atoi(str);
	     if(n == 0)
	        break;
	     memset(input,'\0', sizeof(input));
	     memset(output,'\0', sizeof(output));
	     len_in = 0;
	     len_out = 0;
	     for(int i=0; i<n; i++){
	         gets(str);
	         tmp = strlen(str);
	         for(int j=len_in, k=0; k<tmp; j++, k++)
	             input[j] = str[k];	         
	         len_in += tmp;     
	         input[len_in++] = '\n';
	     }
	     gets(str);
	     m = atoi(str);
	     for(int i=0; i<m; i++){
	         gets(str);
	         tmp = strlen(str);
	         for(int j=len_out, k=0; k<tmp; j++, k++)
	             output[j] = str[k];
	         len_out += tmp;
	         output[len_out++] = '\n';
	     }
	     if(strcmp(input,output) == 0)
	        printf("Run #%d: Accepted\n",line);
	     else if(checkPE())
	             printf("Run #%d: Presentation Error\n",line);
	     else 
	        printf("Run #%d: Wrong Answer\n",line);
	     
	     line++;
	     
	}
}

