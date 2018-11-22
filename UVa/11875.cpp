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
int tests, n;
int v[11], greater[11], less[11];
int line = 1;
	scanf("%d",&tests);
	while(tests--){
	     scanf("%d",&n);
	     for(int i=0; i<n; i++)
	        scanf("%d",&v[i]);
	     for(int i=0; i<n; i++){
	        greater[i] = 0;
	        less[i] = 0;
	     }	      
	     for(int i=0; i<(n-1); i++)
	        for(int j=i+1; j<n; j++){
	            if(v[i] > v[j]){
	              greater[i]++;
	              less[j]++;
	            } else {
	               greater[j]++;
	               less[i]++;
	            }
	         }
	     for(int i=0; i<n; i++)
	         if(greater[i] == less[i])
	            printf("Case %d: %d\n",line,v[i]);
	     line++;
	        
	}
}