#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 105

using namespace std;

char sky[MAX][MAX];
int mapSky[MAX][MAX];
int counts[MAX*MAX];
int label;
int R, C;

int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

void floodFill(int r, int c){

	mapSky[r][c] = label;
	counts[label]++;
	for(int i=0; i<8; i++)
	   if(r + dr[i] >= 0 && r + dr[i] < R && 
	      c + dc[i] >= 0 && c + dc[i] < C &&
	      sky[r+dr[i]][c+dc[i]] == '*' && 
	      mapSky[r+dr[i]][c+dc[i]] == 0)
	      floodFill(r + dr[i], c + dc[i]);
}


main(){
int ans;
	while(true){
		scanf("%d %d",&R,&C);
		if(R == 0 && C == 0)
		   break;
		   
		for(int i=0; i<R; i++)
		   for(int j=0; j<C; j++)
		      mapSky[i][j] = 0;
		      
		for(int i=0; i<R; i++)
		   scanf("%s", sky[i]);
		label = 1;
		memset(counts, 0, sizeof(counts));
		for(int i=0; i<R; i++)
		    for(int j=0; j<C; j++)
		        if(sky[i][j] == '*' && mapSky[i][j] == 0){
		           floodFill(i,j);
		           label++;
		        }
		ans = 0;
		for(int i=0; i<R*C; i++)
		   if(counts[i] == 1)
		      ans++;
		printf("%d\n",ans);
	}
}

