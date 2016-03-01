#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 150

using namespace std;

int N;
char game[MAX][MAX];


void floodFill(int R, int C){
    
	if(R < 0 || R >= N || C < 0 || C >= N || game[R][C] == '.')
	   return;
	
	game[R][C] = '.';
	floodFill(R-1, C);
	floodFill(R+1, C);
	floodFill(R, C-1);
	floodFill(R, C+1);

}

main(){
int T, line = 1;
int cnt, ans;

	scanf("%d",&T);
	while(T--){
	     scanf("%d",&N);
	     for(int i=0; i<N; i++)
	        scanf("%s",game[i]);
	            
	     ans = 0;
	     for(int i=0; i<N; i++)
	        for(int j=0; j<N; j++)
	           if(game[i][j] == 'x'){
	              ans++;
	              floodFill(i,j);
	           }
	  
	     printf("Case %d: %d\n",line, ans);
	     line++;
	}


}

