#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 200 
#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

int N, M, S;
char mat[MAX][MAX];

using namespace std;

main(){
char ch;
int stickers;
int row, col, dir;

	while(true){
	    scanf("%d %d %d\n",&N, &M, &S);
	    if(N == 0 && M == 0 && S == 0)
	       break;
	    for(int i=0; i<N; i++)
	       scanf("%s\n",mat[i]);

	    for(int i=0; i<N; i++)
	       for(int j=0; j<M; j++)
	           if(mat[i][j] == 'N' || mat[i][j] == 'S' || mat[i][j] == 'L' || mat[i][j] == 'O'){
	              row = i; 
	              col = j;
	              
	              if(mat[i][j] == 'N')
	                 dir = NORTH;
	              else if(mat[i][j] == 'S')
	                      dir = SOUTH;
	              else if(mat[i][j] == 'L')
	                      dir = EAST;
	              else if(mat[i][j] == 'O')
	                      dir = WEST;
	              mat[i][j] = '.';
	              break;
	           }
	              
	    stickers = 0;
	    
	    for(int i=0; i<S; i++){
	       scanf("%c",&ch);
	       if(ch == 'D'){
	          if(dir == NORTH)
	             dir = EAST;
	          else if(dir == EAST)
	                  dir = SOUTH;
	          else if(dir == SOUTH)
	                  dir = WEST;
	          else if(dir == WEST)
	                  dir = NORTH;
	       } else if(ch == 'E'){
	                 if(dir == NORTH)
	                    dir = WEST;
	                 else if(dir == WEST)
	                         dir = SOUTH;
	                 else if(dir == SOUTH)
	                         dir = EAST;
	                 else if(dir == EAST)
	                         dir = NORTH;
	       } else if(ch == 'F'){
	                 if(dir == NORTH){
	                    if(row - 1 < 0)
	                       continue;
	                    else if(mat[row-1][col] == '#')
	                            continue;
	                    else if(mat[row-1][col] == '.')
	                            row--;
	                    else if(mat[row-1][col] == '*'){
	                            stickers++;
	                            mat[row-1][col] = '.';
	                            row--;
	                    }
	                 } else if(dir == EAST){
	                           if(col + 1 >= M) 
	                               continue;
	                           else if(mat[row][col+1] == '#') 
	                                  continue;
	                           else if(mat[row][col+1] == '.')
	                                   col++;
	                           else if(mat[row][col+1] == '*'){
	                                   stickers++;
	                                   mat[row][col+1] = '.';
	                                   col++;
	                           }
	                 } else if(dir == SOUTH){
	                           if(row + 1 >= N)
	                              continue;
	                           else if(mat[row+1][col] == '#')
	                                  continue;
	                           else if(mat[row+1][col] == '.')
	                                   row++;
	                           else if(mat[row+1][col] == '*'){
	                                  stickers++;
	                                  mat[row+1][col] = '.';
	                                  row++;
	                           }
	                             
	                 } else if(dir == WEST){
	                           if(col - 1 < 0)
	                              continue;
	                           else if(mat[row][col-1] == '#')
	                                   continue;
	                           else if(mat[row][col-1] == '.')
	                                   col--;
	                           else if(mat[row][col-1] == '*'){
	                                   stickers++;
	                                   mat[row][col-1] = '.';
	                                   col--;
	                           }
	                 } 
	       }
	    }
	    scanf("%c\n",&ch);
        printf("%d\n",stickers);	    
	}

}

