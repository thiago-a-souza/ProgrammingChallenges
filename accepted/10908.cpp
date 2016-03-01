#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

#define MAXSIZE 105 
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

char board[MAXSIZE][MAXSIZE];
int rows, cols;

int findSquare(int x, int y){
int ans = 1;
int maxLength;
bool flag = true;

	maxLength = MAX(rows, cols);
	
	for(int len = 1; len<maxLength && flag; len++){
	   if(x - len < 0 || x + len >= rows || y - len < 0 || y + len >= cols)
	      break;
	   for(int i=x-len; i<=(x+len) && flag; i++)
	      for(int j=y-len; j<=(y+len); j++) 
	          if(board[i][j] != board[x][y]){
	             flag = false;
	             break;
	          }
	    if(flag)
	       ans = 1+len*2;      
	}
	return ans;
}




int main(){
int t,  queries;
int r, c;
int tmp, max;

	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&rows, &cols, &queries);
		memset(board, '\0', sizeof(board));
		for(int i=0; i<rows; i++)
		    scanf("%s", board[i]);
		printf("%d %d %d\n", rows, cols, queries);
		for(int q=0; q<queries; q++){
		    scanf("%d %d",&r,&c);
		    max = 0;
		    printf("%d\n", findSquare(r, c));		    
		}
		    
	}
}

