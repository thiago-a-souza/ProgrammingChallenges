#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 100
#define MAXDIES 2500


using namespace std;

char pic[MAX][MAX];
int rows, cols;
int id[MAX][MAX];
bool visited[MAX][MAX];

int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

void floodFillIDs(int x, int y, int label){
     if(x < 0 || x >= rows || y < 0 || y >= cols)
        return;
     if(pic[x][y] == '.' || visited[x][y] == true)
        return;
        
     visited[x][y] = true;
     
     if(pic[x][y] == '*' || pic[x][y] == 'X')
        id[x][y] = label;
        
     floodFillIDs(x-1, y,   label);
     floodFillIDs(x+1, y,   label);
     floodFillIDs(x,   y-1, label);
     floodFillIDs(x,   y+1, label);
}

void floodFillDots(int x, int y, int label){
     if(x < 0 || x >= rows || y < 0 || y >= cols)
        return;
     if(id[x][y] != label || visited[x][y] == true)
        return;
      
     
     visited[x][y] = true;
     
     if(pic[x][y] == 'X'){
       floodFillDots(x-1, y,   label);
       floodFillDots(x+1, y,   label);
       floodFillDots(x,   y-1, label); 
       floodFillDots(x,   y+1, label);
     }
     return;
     
}

int main(){
int dices;
int ans[MAXDIES];
int t = 1;
	while(true){
	     scanf("%d %d\n",&cols, &rows);
	     if(rows == 0 || cols == 0)
	        break;
	     for(int i=0; i<rows; i++)
	         scanf("%s", pic[i]);

	     for(int i=0; i<rows; i++)
	        for(int j=0; j<cols; j++){
	            id[i][j] = -1;
	            visited[i][j] = false;
	        }
	     
	     dices = 0;
	     for(int i=0; i<rows; i++)
	        for(int j=0; j<cols; j++)
	            if(id[i][j] < 0 &&  ( pic[i][j] == '*' || pic[i][j] == 'X' ) )
	               floodFillIDs(i, j, dices++); 


	     
	     for(int i=0; i<rows; i++)
	        for(int j=0; j<cols; j++)
	            visited[i][j] = false;
	     
	     for(int d=0; d<dices; d++){
	        ans[d] = 0;
	        for(int i=0; i<rows; i++)
	           for(int j=0; j<cols; j++)
	               if(id[i][j] == d && pic[i][j] == 'X' && visited[i][j] == false){
	                  floodFillDots(i, j, d);
	                  ans[d]++;
	               }

	     }
	     
	     qsort(ans, dices, sizeof(int), cmp);   
	     printf("Throw %d\n", t++);
	     for(int i=0; i<dices; i++){
	        if(i>0)
	           printf(" %d", ans[i]);
	        else
	           printf("%d", ans[i]);
	     }
	     printf("\n\n");
	           
	
	}
	return 0;
}


