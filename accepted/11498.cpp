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
int tests;
int x, y, x0, y0;

	while(true){
	     scanf("%d",&tests);
	     if(tests == 0)
	        break;
	     scanf("%d %d",&x,&y);
	     for(int i=0; i<tests; i++){
	         scanf("%d %d",&x0, &y0);
	         if(x == x0 || y == y0)
	            printf("divisa\n");
	         else if(x0 > x && y0 > y)
	                printf("NE\n");   
	         else if(x0 > x && y0 < y)
	                 printf("SE\n");
	         else if(x0 < x && y0 > y)
	                printf("NO\n");
	         else printf("SO\n");        
	     }
	         
	     
	}
}