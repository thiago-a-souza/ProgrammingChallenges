#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAX 2000
#define INF 9999999
#define BOMB 1

int mat[MAX][MAX], d[MAX][MAX];
int R, C;

using namespace std;

void bfs(int srcR, int srcC, int dstR, int dstC){
int rr, cc;
queue< pair< int, int > > Q;

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
           d[i][j] = INF;
	d[srcR][srcC] = 0;
	Q.push(make_pair(srcR,srcC)); 
	
	while(!Q.empty()){
	     rr = Q.front().first; 
	     cc = Q.front().second; 

	     Q.pop();
	     
	     if(mat[rr][cc] == BOMB)
	        continue;
	     
	     if(rr - 1 >= 0 && d[rr-1][cc] >= INF){
	        d[rr-1][cc] = d[rr][cc] + 1;
	        Q.push(make_pair(rr-1,cc));
	     }
	     
	     if(rr + 1 < R && d[rr+1][cc] >= INF){
	        d[rr+1][cc] = d[rr][cc] + 1;
	        Q.push(make_pair(rr+1,cc));
	     }
	     
	     if(cc - 1 >= 0 && d[rr][cc-1] >= INF){
	        d[rr][cc-1] = d[rr][cc] + 1;
	        Q.push(make_pair(rr,cc-1));
	     }
	     
	     if(cc + 1 < C && d[rr][cc+1] >= INF){
	        d[rr][cc+1] = d[rr][cc] + 1;
	        Q.push(make_pair(rr,cc+1));
	     }	     
	}
}



main(){
int rows, rowNbr, mines, pos;
int srcR, srcC, dstR, dstC;
		while(true){
		      scanf("%d %d",&R,&C);
		      if(R == 0 && C == 0)
		         break;
		      scanf("%d",&rows);
		      for(int i=0; i<R; i++)
		         for(int j=0; j<C; j++)
		             mat[i][j] = 0;
		      for(int i=0; i<rows; i++){
		          scanf("%d",&rowNbr);
		          scanf("%d",&mines);
		          for(int i=0; i<mines; i++){
		             scanf("%d",&pos);
		             mat[rowNbr][pos] = BOMB;
		          }
		      }
		      scanf("%d %d %d %d",&srcR, &srcC,&dstR, &dstC);
		      mat[srcR][srcC] = 0;
		      bfs(srcR,srcC,dstR,dstC);
		      printf("%d\n",d[dstR][dstC]);
		    
		}
}



