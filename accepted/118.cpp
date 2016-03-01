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

#define MAX 100
#define DEBUG(x) 


#define N  1
#define E  2
#define S  3
#define W  4

using namespace std;

main(){
int rows, cols, x, y;
int grid[MAX][MAX];
int scent[MAX][MAX];
char orientation;
char movs[MAX];
char ch[5] = { 'X', 'N', 'E', 'S', 'W' };
int len;
bool lost;

        scanf("%d %d",&cols, &rows);
		while(scanf("%d %d %c",&x, &y, &orientation) != EOF){
		     scanf("%s",movs);
		     len = strlen(movs);
		     
		     for(int i=0; i<=rows; i++)
		        for(int j=0; j<=cols; j++){
		            grid[i][j] = 0;
		        }
		     
		     lost = false;
		     if(orientation == 'N')
		        grid[rows-y][x] = N;
		     else if(orientation == 'S')
		             grid[rows-y][x] = S;
		     else if(orientation == 'E')
		             grid[rows-y][x] = E;
		     else if(orientation == 'W')
		             grid[rows-y][x] = W;
		      
		     DEBUG( printf("x=%d  y=%d rows=%d cols=%d\n",x,y,rows,cols); )      
		     
		     for(int i=0; i<len; i++){
		     
		        if(movs[i] == 'L'){
		           if(grid[rows-y][x] == N)
		              grid[rows-y][x] = W;
		           else if(grid[rows-y][x] == W)
		                   grid[rows-y][x] = S;
   		           else if(grid[rows-y][x] == S)
		                   grid[rows-y][x] = E;
   		           else if(grid[rows-y][x] == E)
		                   grid[rows-y][x] = N;
		        } else if(movs[i] == 'R'){
		                  if(grid[rows-y][x] == N)
		                     grid[rows-y][x] = E;
		                  else if(grid[rows-y][x] == E)
		                          grid[rows-y][x] = S;
		                  else if(grid[rows-y][x] == S)
		                          grid[rows-y][x] = W;
		                  else if(grid[rows-y][x] == W)
		                          grid[rows-y][x] = N;
		        } else if(movs[i] == 'F'){
		                 if(grid[rows-y][x] == N){
		                    if(y+1 > rows ){
		                      if(scent[rows-y][x] == 0){
		                         scent[rows-y][x] = 1;
		                         lost = true;
		                         break;
		                      }
		                    } else {
		                      grid[rows-y][x] = 0;
		                      y++;
		                      grid[rows-y][x] = N;
		                    }
		                 } else if(grid[rows-y][x] == E){
		                           if(x+1 > cols){
		                              if(scent[rows-y][x] == 0){
		                                 scent[rows-y][x] = 1;
		                                 lost = true;
		                                 break;
		                              }
		                           } else {
		                              grid[rows-y][x] = 0;
		                              grid[rows-y][x+1] = E;
		                              x++;
		                           }
		                 } else if(grid[rows-y][x] == S){
		                           if(y-1 < 0){
		                              if(scent[rows-y][x] == 0){
		                                 scent[rows-y][x] = 1;
		                                 lost = true;
		                                 break;
		                              }
		                           } else {
		                              grid[rows-y][x] = 0;
		                              y--;
		                              grid[rows-y][x] = S;
		                           }
		                 } else if(grid[rows-y][x] == W){
		                           if(x - 1 < 0){
		                             if(scent[rows-y][x] == 0){
		                                 scent[rows-y][x] = 1;
		                                 lost = true;
		                                 break;
		                              }
		                           } else {
   		                              grid[rows-y][x] = 0;
		                              grid[rows-y][x-1] = W;
		                              x--;
		                           }
		                 }
		        }
		     }


		     printf("%d %d %c", x, y, ch[grid[rows-y][x]]);
		     if(lost)
		       printf(" LOST");
		     printf("\n");
		             
		             
		}



}

