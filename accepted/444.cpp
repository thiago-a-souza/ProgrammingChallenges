#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define MAX 1000
char str[MAX];

void encode(int len){
int val;

	for(int i=len-1; i>=0; i--){
	    if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') ||
	        str[i] == ' ' || str[i] == '!' || str[i] == ',' || str[i] == ',' || 
	        str[i] == ',' || str[i] == '.' || str[i] == ':' || str[i] == ';' ||
	        str[i] == '?'){
	        val = (int)str[i];
	        while(val > 0){
	              printf("%d",val%10);
	              val = val/10;
	        }
	     }  
	}
	printf("\n");
}

void decode(int len){
int	index = 0;
char dec[MAX];

	for(int i=0; i<len-1; i++){
	    if(str[i] >= '0' && str[i] <= '9' && str[i+1] >= '3'){
	       dec[index++] = (char)((str[i] - 48) + (str[i+1] - 48)*10);
	       i++;
	    } else if(str[i] >= '0' && str[i] <= '9' && str[i+1] >= '0' && str[i+1] <= '2'){
	              dec[index++] =(char) ((str[i] - 48) + (str[i+1] - 48)*10 +
	              (str[i+2] - 48)*100);
	              i+=2;
	    }
    }
	
	for(int i=index-1; i>=0; i--)
	    printf("%c",dec[i]);
	printf("\n");

}


main(){
char dec[MAX];
int len, val, index;
bool b;
		while(cin.getline(str, MAX)){
		     len = strlen(str);

			 if(str[0] >= '0' && str[0] <= '9')
			    decode(len);
			 else 
			    encode(len);
		}

}

