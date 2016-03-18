#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>

#define MAX 3005
#define MAXCUBES 501
#define MIN(a,b) ((a) < (b) ? (a) : (b))


using namespace std;

int input[MAXCUBES][6], d[MAXCUBES][6], prow[MAXCUBES][6], pcol[MAXCUBES][6];
int opposite[6] = {1, 0, 3, 2, 5, 4};
string side[6] = {"front", "back", "left", "right", "top", "bottom"};
int ansrow[MAXCUBES], anscol[MAXCUBES], sz;

void showPath(int i, int j){

	if(i < 0 || j < 0)
	   return;
	ansrow[sz] = i + 1;
	anscol[sz] = j;
	sz++;
	showPath(prow[i][j], pcol[i][j]); 
}

int main(){
int n, sq = 1;
int maxDist, maxRow, maxCol;
bool first = true;

	while(true){
		scanf("%d", &n);
		if(n == 0)
		   break;
		
		if(first)
		   first = false;
		else
		   printf("\n");   
		   
		
		for(int i=0; i<n; i++)
		    for(int j=0; j<6; j++)
		       scanf("%d", &input[i][j]);
		
		memset(d, 0, sizeof(d));
		memset(prow, -1, sizeof(prow));
		memset(pcol, -1, sizeof(pcol));		
		maxDist = maxRow = maxCol = sz = 0;
		for(int i=1; i<n; i++)
		   for(int j=0; j<6; j++){
		      int temp = -1, row = -1, col = -1;
		      for(int ii=i-1; ii>=0; ii--){
		         for(int jj=0; jj<6; jj++){
		             if(input[i][j] == input[ii][jj]){
		                if(d[ii][opposite[jj]] > temp){
		                   temp = d[ii][opposite[jj]];
		                   row = ii;
		                   col = jj;
		                }
		             }
		         }
		      }
		      if(temp + 1 > d[i][j]){
		         d[i][j] = temp + 1;
		         prow[i][j] = row;
		         pcol[i][j] = opposite[col];
		         if(d[i][j] > maxDist){
		            maxDist = d[i][j];
		            maxRow = i; 
		            maxCol = j;
		         }
		      }
		   }

      showPath(maxRow, maxCol);

	printf("Case #%d\n%d\n", sq++, sz);
	for(int ii=sz-1; ii>=0; ii--)
	    cout << ansrow[ii] << " " << side[anscol[ii]] << endl;
		
 
	}
	return 0;
}

