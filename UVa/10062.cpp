#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 2000
#define MAX_B 500

using namespace std;

typedef struct{
int freq, index;
} TStr;


main(){
TStr tstr[MAX_B], tmp;
char str[MAX];
int len;
bool first = true;
int  ch;

		while(gets(str)){
		     len = strlen(str);
		     if(!first)
                printf("\n");
             first = false;
		     for(int i=0; i<MAX_B; i++){
		        tstr[i].freq = 0;
		        tstr[i].index = i;
		     }
		     
		     for(int i=0; i<len; i++)
		         tstr[(int)str[i]].freq++;


		     for(int i=0; i<MAX_B-1; i++)
		        for(int j=i+1; j<MAX_B; j++){
		            if(tstr[j].freq < tstr[i].freq || 
		               ( tstr[j].freq == tstr[i].freq && tstr[j].index > tstr[i].index ) ){
		               tmp.freq = tstr[i].freq;
		               tmp.index = tstr[i].index;
		               
		               tstr[i].freq = tstr[j].freq;
		               tstr[i].index = tstr[j].index;
		               
		               tstr[j].freq = tmp.freq;
		               tstr[j].index = tmp.index;
		               
		            } 
		        }
		            
		            
		     for(int i=0; i<MAX_B; i++)
		         if(tstr[i].freq > 0)
		           printf("%d %d\n",tstr[i].index,tstr[i].freq);
		    
		}

}

