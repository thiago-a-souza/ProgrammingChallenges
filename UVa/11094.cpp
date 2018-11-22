#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

#define MAX 30

using namespace std;

char mat[MAX][MAX];
int visit[MAX][MAX];
int rows, cols;
int label;
int rr, cc;


void floodFill(int r, int c){
     if(r < 0 || r >= rows || c < 0 || c >= cols || mat[r][c] != mat[rr][cc] || visit[r][c] != 0)
        return;
     
     visit[r][c] = label;
     
     if(c == 0)
        floodFill(r, cols-1);
     if(c == cols-1)
        floodFill(r, 0);
        
     floodFill(r-1, c); 
     floodFill(r,c-1);
     floodFill(r,c+1);
     floodFill(r+1,c);
}

main(){
int curLabel;
int tmp, ans;
		while(scanf("%d %d",&rows, &cols) != EOF){
		     for(int i=0; i<rows; i++)
		        scanf("%s",mat[i]);
		     scanf("%d %d",&rr,&cc);
		     		     
		     label = 1;
		     for(int i=0; i<rows; i++)
		        for(int j=0; j<cols; j++)
		            visit[i][j] = 0;

		     for(int i=0; i<rows; i++)
		        for(int j=0; j<cols; j++)
		            if(mat[i][j] == mat[rr][cc] && visit[i][j] == 0){
		               floodFill(i,j);
		               label++;
		            }
		     
		     curLabel = visit[rr][cc];
		      ans = 0;
		     for(int l=1; l<label; l++){
		        if(l == curLabel)
		           continue;
		        tmp = 0;
		        for(int i=0; i<rows; i++)
		            for(int j=0; j<cols; j++)
		                if(visit[i][j] == l)
		                   tmp++;
		        if(tmp > ans)
		           ans = tmp;
		     }
		     printf("%d\n",ans);
		        
		     
		}
}

