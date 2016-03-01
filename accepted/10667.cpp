#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

#define MAX 101
#define USED -32767

int board[MAX][MAX];
int sum[MAX][MAX][MAX];
int s;



using namespace std;

int maxSum(){
int biggest, tmp;

	for(int i=0; i<s; i++)
	   for(int j=0; j<s; j++)
	       sum[i][i][j] = 0;

	biggest = 0;
	  
	for(int i=0; i<s; i++)
	    for(int j=i; j<s; j++){
	         tmp = 0;
	        for(int k=0; k<s; k++){
	            sum[i][j+1][k] = sum[i][j][k] + board[j][k];
	            if(sum[i][j+1][k] + tmp > 0){
	               tmp += sum[i][j+1][k];
	               if(tmp > biggest)
	                  biggest = tmp;
	            } else tmp = 0;
	        }
	    }
	 return biggest;
}


int main(){
int tests;
int n;
int r1, c1, r2, c2;

	scanf("%d",&tests);
	while(tests--){
		for(int i=0; i<MAX; i++)
		    for(int j=0; j<MAX; j++)
		        board[i][j] = 1;
		
		scanf("%d",&s);
		scanf("%d",&n);
		for(int i=0; i<n; i++){
		   scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		   r1--; c1--; r2--; c2--;
		   for(int row=r1; row<=r2; row++)
		      for(int col=c1; col<=c2; col++)
		          board[row][col] = USED;
		   
		}  
		printf("%d\n", maxSum());    
		
	}
}

