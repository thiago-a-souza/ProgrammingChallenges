/*
Category: backtracking, dynamic programming
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define debug(x) x
#define MAX 101 
using namespace std;

int N, R, C;
int mat[MAX][MAX];
int dp[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int longestPath(int row, int col){
int ans, aux;
	if(dp[row][col] != -1 )
	   return dp[row][col];
	else {
	   ans = 0;
	   for(int i=0; i<4; i++)
	      if(row+dr[i] >= 0 && row+dr[i] < R && col+dc[i] >= 0 && col+dc[i] < C &&
	         mat[row][col] > mat[row+dr[i]][col+dc[i]]){
	            aux = longestPath(row+dr[i], col+dc[i]) + 1;
	            if(aux > ans)
	               ans = aux;
	         }
	   dp[row][col] = ans;
	   return ans;
	}
}




main(){
char name[1000];
int ans, aux;

	scanf("%d",&N);
	while(N--){
	      scanf("%s %d %d",name, &R, &C);
	      for(int i=0; i<R; i++)
	         for(int j=0; j<C; j++){
	            scanf("%d",&mat[i][j]);
	            dp[i][j] = -1;
	         }
	      ans = 0;
	      for(int i=0; i<R; i++)
	         for(int j=0; j<C; j++){
	             aux = longestPath(i,j);
	             if(aux > ans)
	                 ans = aux;
	         }
	      printf("%s: %d\n",name,ans+1);
	             
	     

	             
	}
}

