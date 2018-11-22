#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 2000

using namespace std;

char enc[MAX], wrd[MAX];
int len_enc, len_wrd;

bool check(int key){
int start, count = 0;
	
	for(int i=0; i<=len_enc; i++){
	   if(enc[i] < 100 && count <= 0){
	      start = i;
	      count++;
	   }
	   else if(enc[i] < 100)
	           count++;
	   else {
	      
	      if(count > 0 && i - start == len_wrd){
	         bool b = true;
	         for(int j=start, k = 0; j<i; j++, k++)
	             if((wrd[k] + key)%26 != enc[j]){
	                b = false;
	                break;
	             }
	         if(b) 
	           return true;
	      }
	      count = 0;
	      start = -1;
	   }
	}
	return false;

}

main(){
int n;

	scanf("%d\n",&n);
	while(n--){
	    memset(enc, '\0', sizeof(enc));
	    memset(wrd, '\0', sizeof(wrd));
		cin.getline(enc, MAX);
		cin.getline(wrd, MAX);
		
		len_enc = strlen(enc);
		len_wrd = strlen(wrd);
		
		for(int i=0; i<=len_enc; i++){
		   if(enc[i] >= 'a' && enc[i] <= 'z')
		      enc[i] = enc[i] - 'a';
		   else
		      enc[i] = 100;
	    }
	    
	    for(int i=0; i<=len_wrd; i++){
	       if(wrd[i] >= 'a' && wrd[i] <= 'z')
	          wrd[i] = wrd[i] - 'a';
	       else 
	          wrd[i] = 100;
	    }
	    
		
		for(int k=0; k<26; k++)
		   if(check(k))
		      printf("%c",(char)(k+'a'));
		printf("\n");
	
	}
}