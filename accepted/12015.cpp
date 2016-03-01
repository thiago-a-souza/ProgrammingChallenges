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
int t;
char urls[10][150];
int rank[10], high, line = 1;

	scanf("%d",&t);
	while(t--){
	     high = -1;
	     for(int i=0; i<10; i++){
	        scanf("%s %d",urls[i], &rank[i]);
	        if(rank[i] > high)
	           high = rank[i];
	     }
	     printf("Case #%d:\n",line);
	     for(int i=0; i<10; i++)
	         if(rank[i] == high)
	            printf("%s\n",urls[i]);
	     line++;
	      
	}


}

