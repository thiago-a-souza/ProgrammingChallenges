#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 8
#define DEBUG(x) 

using namespace std;

int chess[MAX][MAX];
int max_val;

void NQueens(int Q[], int r){
bool legal;
int sum = 0;

	if(r == MAX){
	  for(int i=0; i<MAX; i++)
	     sum += chess[i][Q[i]];
	  if(sum > max_val)
	     max_val = sum;
	} else {
	     for(int j=0; j<MAX; j++){
	        legal = true;
	        for(int i=0; i<r; i++){
               if(Q[i] == j || Q[i] == (j + r - i) || Q[i] == (j-r+i))
                  legal = false;
	        }
	        if(legal){
	          Q[r] = j;
	          NQueens(Q, r+1);
	        }
	     }
	}
}

main(){
int t;
int Q[MAX];

		scanf("%d",&t);
		while(t--){
		     for(int i=0; i<MAX; i++)
		         for(int j=0; j<MAX; j++)
		             scanf("%d",&chess[i][j]);
		     max_val = 0;
		     NQueens(Q, 0);
		     printf("%5d\n",max_val);
		}


}

