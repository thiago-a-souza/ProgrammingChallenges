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
int n, v[10];
bool b;
	scanf("%d",&n);
    printf("Lumberjacks:\n");
	while(n--){
	   for(int i=0; i<10; i++)
	      scanf("%d",&v[i]);
	
	   b = true;
	
	   for(int i=0; i<9; i++)
	      if(v[i] < v[i+1]){
	         b = false;
	         break;
	      }
	   if(b)
	      printf("Ordered\n");
	   else {
	      b = true;
	      for(int i=0; i<9; i++)
	        if(v[i] > v[i+1]){
	          b = false;
	          break;
	        }
	      if(b)
	        printf("Ordered\n");
	      else
	        printf("Unordered\n");
	   }
	}
}

