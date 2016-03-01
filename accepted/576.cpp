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
#include <climits>
#include <cmath>

using namespace std;

main(){
char str[300];
int len; 
int line, syllable;
int last_index;
bool ans;
	while(true){
	     cin.getline(str,300);
	     len = strlen(str);
	     if(strcmp(str,"e/o/i") == 0)
	        break;
	     line = 1;
	     syllable = 0;
	     ans = true;
	     last_index = -2;
	     for(int i=0; i<len; i++){
	        if(str[i] == '/'){
	          if(line == 1 && syllable != 5){
	             printf("1\n");
	             ans = false;
	             break;
	          } else if(line == 2 && syllable != 7){
	                    printf("2\n");
	                    ans = false;
	                    break;
	          }
	          line++;
	          syllable = 0;
	          last_index = -2;
	        } else if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
	                  str[i] == 'o' || str[i] == 'u' || str[i] == 'y'){
	                  if(last_index != i - 1)
	                     syllable++;
	                  last_index = i;
	        }
	        
	        if(i == len - 1){
	           if(syllable != 5){
	              printf("3\n");
	              ans = false;
	           }
	        }
	     }
	     if(ans)
	       printf("Y\n");
	}
}