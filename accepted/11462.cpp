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

#define MAX 2000001

using namespace std;

main(){
int vals[MAX], n;
int tmp;

	while(true){
	     scanf("%d",&n);
	     if(n == 0)
	        break;
	     memset(vals,0,sizeof(vals));
	     
	     for(int i=0; i<n; i++){
	         scanf("%d",&tmp);
	         vals[tmp]++;
	     }
	     tmp = 0;
	     for(int i=0; i<MAX; i++){
	        if(vals[i] != 0){
	          for(int j=0; j<vals[i]; j++){
	              printf("%d",i);
	              tmp++;
	              if(tmp < n){
	                 printf(" ");
	              } else {
	                i = MAX;
	                break;
	              }
	          }
	        }
	     }
	     printf("\n");
	}
}

