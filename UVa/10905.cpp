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

#define MAX 2000
using namespace std;

int cmp(char *a, char *b){
int sza, szb;
int sz;
char c[2*MAX], d[2*MAX];

	sza = strlen(a);
	szb = strlen(b);
	memset(c,'\0',2*MAX);
	memset(d,'\0',2*MAX);
	
	for(int i=0; i<sza; i++){
	   c[i] = a[i];
	   d[i+szb] = a[i];
	}
	for(int i=0; i<szb; i++){
	   c[i+sza] = b[i];
	   d[i] = b[i];
	}
	
	sz = strlen(c);
	for(int i=0; sz; i++){
	   if(c[i] != d[i]){
	      if(c[i] > d[i])
	         return 1;
	      else
	         return -1;
	   }
	         
	}
	return 0;      
	    
	
}

main(){
char nbr[MAX][MAX];
char tmp[MAX];
int n;



	while(true){
	     scanf("%d",&n);
	     if(n == 0)
	       break;
	     for(int i=0;i<n; i++)
	        memset(nbr[i],'\0',MAX);
	     for(int i=0; i<n; i++)
	        scanf("%s",nbr[i]);
	        
	        
	     for(int i=0; i<(n-1); i++)
	        for(int j=i+1; j<n; j++)
	            if(cmp(nbr[i], nbr[j]) < 0){
	               memset(tmp,'\0',MAX);
	               strcpy(tmp,nbr[j]);
	               strcpy(nbr[j],nbr[i]);
	               strcpy(nbr[i],tmp);
	            }   
	      for(int i=0; i<n; i++)
	         printf("%s",nbr[i]);
	    cout << endl;
	}

}

