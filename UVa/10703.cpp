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
int w, h, n, x1, y1, x2, y2;
int matrix[501][501];
int ans, tmp;
		while(true){
		     scanf("%d %d %d",&w,&h, &n);
		     if(w == 0 && h == 0 && n == 0)
		        break;
		     memset(matrix, 0, sizeof(matrix));
		            
		     for(int a=0; a<n; a++){
		        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		        if(x2 < x1){
		           tmp = x1;
		           x1 = x2;
		           x2 = tmp;
		        }
		        if(y2 < y1){
		           tmp = y1;
		           y1 = y2;
		           y2 = tmp;
		        }
		        for(int i=y1; i<=y2; i++)
		           for(int j=x1; j<=x2; j++)
		                matrix[i][j] = 1;
		     }
		     ans = 0;
		     for(int i=1; i<=h; i++)
		        for(int j=1; j<=w; j++)
		            if(matrix[i][j] == 0)
		               ans++;
		     if(ans == 0)
		        printf("There is no empty spots.\n");
		     else if(ans == 1)
		             printf("There is one empty spot.\n");
		     else printf("There are %d empty spots.\n",ans);	     
		}
	
}

