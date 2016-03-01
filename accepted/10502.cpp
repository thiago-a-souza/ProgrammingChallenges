#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

#define MAX 105

using namespace std;

int main(){
int rows, cols, count;
char board[MAX][MAX];
bool flag;

	while(true){
		scanf("%d", &rows);
		scanf("%d", &cols);
		if(rows == 0 || cols == 0)
		   break;
		memset(board, '\0', sizeof(board));
		for(int i=0; i<rows; i++)
		    scanf("%s", board[i]);

		count = 0;
		for(int x1=0; x1<rows; x1++)
		   for(int y1=0; y1<cols; y1++)
		      for(int x2=x1; x2<rows; x2++)
		         for(int y2=y1; y2<cols; y2++){
		            flag = true;
		            for(int i=x1; i<=x2 && flag; i++)
		               for(int j=y1; j<=y2; j++)
		                  if(board[i][j] == '0'){
		                    flag = false;
		                    break;
		                  }
		            if(flag)
		              count++;
		         }
	     printf("%d\n", count);		          

	}
	
}

