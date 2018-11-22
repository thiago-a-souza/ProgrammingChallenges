#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map> 
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack> 
#include <climits>

#define MAX 10000

using namespace std;

main(){
char str[MAX];
int len;
bool ans;

		while(true){
		     cin.getline(str,MAX);
		     len = strlen(str);
		     for(int i=0; i<len; i++)
		         str[i] = tolower(str[i]);

		     if(strcmp(str,"done") == 0)
		        break;
		        
		     for(int i=0; i<len; i++){
		        if(str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!'){
		           for(int j=i; j<len; j++)
		              str[j] = str[j+1];
		           len--;
		           i--;
		        }
		     }   
		     
		     ans = true;
		     for(int i=0, j=len-1; i<(len/2); i++, j--)
		         if(str[i] != str[j]){
		           ans = false;
		           break;
		         }
		     if(ans)
		       printf("You won't be eaten!\n");
		     else
		       printf("Uh oh..\n");       
		}
}

