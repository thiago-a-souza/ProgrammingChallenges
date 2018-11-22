#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>

#define MAX 1000
#define MAXL 30

using namespace std;

typedef struct {
int label;
int freq;
} TFreq;

char m[MAX][MAX];
int visited[MAX][MAX];
int rows, cols;
TFreq tfreq[MAXL];

void floodFill(int r, int c, char ch){

    visited[r][c] = 1;
	if(r-1 >= 0 && m[r-1][c] == ch && visited[r-1][c] == 0)
	   floodFill(r-1, c, ch);
	   
   	  
	if(c-1 >= 0 && m[r][c-1] == ch && visited[r][c-1] == 0)
	   floodFill(r, c-1, ch);
	if(c+1 < cols && m[r][c+1] == ch && visited[r][c+1] == 0)
       floodFill(r, c+1, ch);
	
	if(r+1 < rows && m[r+1][c] == ch && visited[r+1][c] == 0)   
	   floodFill(r+1, c, ch);

}
main(){
int t, line=1;
TFreq tmp;

	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&rows,&cols);
		for(int i=0; i<rows; i++)
		   scanf("%s",m[i]);

		for(int i=0; i<rows; i++)
		   for(int j=0; j<cols; j++)
		       visited[i][j] = 0;
		for(int i=0; i<MAXL; i++){
		   tfreq[i].label = i + 97;
		   tfreq[i].freq = 0;
		}
		
		for(int i=0; i<rows; i++)
		   for(int j=0; j<cols; j++)
		      if(visited[i][j] == 0){
		         floodFill(i,j, m[i][j]);
		         tfreq[((int)m[i][j]) - 97].freq++;
		      }
		
		for(int i=0; i<(MAXL-1); i++)
		   for(int j=i+1; j<MAXL; j++)
		      if(tfreq[i].freq < tfreq[j].freq || 
		         (tfreq[i].freq == tfreq[j].freq && tfreq[i].label > tfreq[j].label)){
		           tmp.freq = tfreq[i].freq;
		           tmp.label = tfreq[i].label;
		           
		           tfreq[i].freq = tfreq[j].freq;
		           tfreq[i].label = tfreq[j].label;
		           
		           tfreq[j].freq = tmp.freq;
		           tfreq[j].label = tmp.label;
		         }
		
		
		printf("World #%d\n",line);
		line++;
		for(int i=0; i<MAXL; i++)
		  if(tfreq[i].freq > 0)
		      printf("%c: %d\n",(char)tfreq[i].label,tfreq[i].freq);
		
	}

}

