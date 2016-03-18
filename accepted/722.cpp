#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 1000

using namespace std;


char m[MAX][MAX];
int len[MAX], visited[MAX][MAX];
int totalRows;
int sol;

int dx[4] = {-1, 1,  0, 0};
int dy[4] = { 0, 0, -1, 1};

void floodFill(int r, int c){
     
	if(r < 0 || c < 0 || r >= totalRows || c >= len[r] || m[r][c] == '1' || visited[r][c])
	   return;

	visited[r][c] = 1;
	sol++;
	for(int i = 0; i < 4; i++)
	    floodFill(r + dx[i], c + dy[i]);

}

int main(){
int tests;
int row, col;

	scanf("%d\n", &tests);
	while(tests--){
	      scanf("%d %d\n", &row, &col);

	      memset(visited, 0, sizeof(visited));
	      memset(len, 0, sizeof(len));
	      totalRows = 0;
	      while(true){
	            cin.getline(m[totalRows], MAX);
	            len[totalRows] = strlen(m[totalRows]);
	            totalRows++;
	            if(len[totalRows-1] == 0)
	               break;
	            
	            
	      }
	      sol = 0;
	      floodFill(row - 1, col - 1);
	      cout << sol << endl;
	      if(tests > 0)
	         printf("\n");
	}
	return 0;
}

