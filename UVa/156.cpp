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

#define MAX 1010
using namespace std;

typedef struct {
map<char,int> freq;
char word[30];
char length;
int invalid;
} TAnag;

bool comp(TAnag a, TAnag b){
     if(strcmp(a.word, b.word) < 0)
        return true;
     return false;
}

main(){
TAnag anag[MAX];
char tmp[100];
int len;
int n = 0, i1, i2;
map<char,int> :: iterator it;
bool b;

		while(true){
		    
		     scanf(" %s ",tmp);
		     len = strlen(tmp);
		     
		     if(len == 1 && tmp[0] == '#')
		        break;
		     strcpy(anag[n].word, tmp);
		     anag[n].length = len;
		     anag[n].invalid = 0;
		     

		     
		     for(int i=0; i<len; i++){
		        if(tmp[i] >= 'A' && tmp[i] <= 'Z')
		           anag[n].freq[tmp[i]+32] = anag[n].freq[tmp[i]+32] +1;
		        else   
		           anag[n].freq[tmp[i]] = anag[n].freq[tmp[i]] + 1;
		     }
		     n++;
		}
		
		
		
		for(int i=0; i<n-1; i++){
		   for(int j=i+1; j<n; j++){
		      if(anag[i].length == anag[j].length){
		         b = true;
		         for(it = anag[i].freq.begin(); it != anag[i].freq.end(); it++){
		            if(anag[i].freq[it->first] != anag[j].freq[it->first]){
		              b = false;
		              break;
		            }
		            
		         }
		         if(b){
		            anag[i].invalid = 1;
		            anag[j].invalid = 1;
		         }
		       
		       
		      }
		   }
		}
		sort(anag,anag+n,comp);
		for(int i=0; i<n; i++)
		   if(anag[i].invalid == 0)
		     printf("%s\n",anag[i].word);

}

