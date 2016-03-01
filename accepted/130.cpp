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

#define MAX 101

using namespace std;

main(){
int n, k;
int v[MAX];
int start, index, total, lastVal, lastIndex, count;
bool kill;


		while(scanf("%d %d",&n,&k) != EOF){
			 if(n == 0 && k == 0)
			    break;
			 for(int i=0; i<MAX; i++)
			    v[i] = i;

			 total = n;
			 start = 0;
			 while(total > 0){
 			      for(int i=0; i<MAX; i++)
			         v[i] = i;
			      start++;
			      total = n;
			      index = start;
			      count = 0;
			      kill = true;
			      lastVal = -1; 
			      lastIndex = -1;
			      
			      while(lastVal != 1){
			            if(v[index] > 0){
			               count++;
			            }
			            if(count == k){
			               count = 0;
			               if(kill){
			                  kill = false;
			                  lastVal = v[index];
			                  lastIndex = index;
			                  v[index] = -1;
			                  total--;
			               } else {
			                  kill = true;
			                  v[lastIndex] = v[index];
			                  v[index] = -1;
			                  index = ((lastIndex + 1)%(n+1)) > 0 ? (lastIndex + 1)%(n+1) : 1;
			                  continue;
			               }
			               
			            }
			            index = ((index + 1)%(n+1)) > 0 ? (index + 1)%(n+1) : 1;
			      }
			      
			      
			 }
		     printf("%d\n",start);
		     
			 
			    
		}


}

