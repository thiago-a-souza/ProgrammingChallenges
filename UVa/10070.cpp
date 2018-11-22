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

#define MAX 10000

using namespace std;

int year[MAX];
int len;

bool div4(){
int d = 0, rem;

	for(int i=0; i<len; i++){
	   rem = (d*10 + year[i])%4;
	   d = rem;
	}
	if(d == 0)
	   return true;
	return false;
}

bool div100(){
	if(len < 2)
	   return false;
	if(year[len-1] == 0 && year[len-2] == 0)
	   return true;
	return false;
}

bool div400(){
int d = 0, rem;

	for(int i=0; i<len; i++){
	   rem = (d*10 + year[i])%400;
	   d = rem;
	}
	if(d == 0)
	   return true;
	return false;
}

bool div15(){
int d = 0, rem;
	for(int i=0; i<len; i++){
	   rem = (d*10 + year[i])%15;
	   d = rem;
	}
	if(d == 0)
	   return true;
	return false;
}

bool div55(){
int d = 0, rem;

	for(int i=0; i<len; i++){
	   rem = (d*10 + year[i])%55;
	   d = rem;
	}
	if(d == 0)
	   return true;
	return false;
}


main(){
char str[MAX];
bool first=true, isLeap, isHulu, isBulu;



		while(scanf("%s",str) != EOF){
		    if(!first)
		      printf("\n");
		    first = false;
		    
		    len = strlen(str);
		    for(int i=0; i<len; i++)
		       year[i] = (int)str[i] - '0';

		    
		    isLeap = false;
		    isHulu = false;
		    isBulu = false;
		    
			if((div4() && !div100()) || div400()){
			   printf("This is leap year.\n");
			   isLeap = true;
			}
			
			if(div15()){
			  printf("This is huluculu festival year.\n");
			  isHulu = true;
			}  
			if(div55() && isLeap){
			  printf("This is bulukulu festival year.\n");
			  isBulu = true;
			}
			
			if(!isLeap && !isHulu && !isBulu)
			  printf("This is an ordinary year.\n");
		}
}

