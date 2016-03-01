#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAXLINE 10000
#define MAXMAZE 100
#define TRUE 1

#define NORTH 0
#define SOUTH 1
#define EAST  2
#define WEST  3

using namespace std;

int main(){
int tests, initial, len;
int rows, cols; 
int r, c;
int orientation;

char ch;
char maze[MAXMAZE][MAXMAZE];
char leg[4] = {'N', 'S', 'E', 'W'};

	scanf("%d", &initial);
	tests = initial;
	while(tests--){
	      if(tests != initial - 1)
	         printf("\n");
	      scanf("%d %d\n",&rows, &cols);
	      
	      for(int i=0; i<rows; i++){
	          memset(maze[i], '\0', MAXMAZE);
	          cin.getline(maze[i], MAXMAZE);
	      }
	      scanf("%d %d\n", &r, &c);
	      r--; c--;
	      
	      orientation = NORTH;

	      while(TRUE){
	             ch = getchar();
	             if(ch == EOF)
	                break;
	             if(ch == 'Q')
	                 break;
	             if(ch == 'R'){
	                if(orientation == NORTH)
	                   orientation = EAST;
	                else if(orientation == EAST)
	                        orientation = SOUTH;
	                else if(orientation == SOUTH)
	                        orientation = WEST;
	             } else if(ch == 'L'){
	                       if(orientation == NORTH)
	                          orientation = WEST;
	                       else if(orientation == WEST)
	                               orientation = SOUTH;
	                       else if(orientation == SOUTH)
	                               orientation = EAST;
	                       else if(orientation == EAST)
	                               orientation = NORTH;
	             } else if(ch == 'F'){
	                       if(orientation == NORTH){
	                          if(r - 1 >= 0 && maze[r-1][c] == ' ')
	                             r--;
	                       } else if(orientation == SOUTH){
	                                 if(r + 1 < rows && maze[r+1][c] == ' ')
	                                     r++;
	                       } else if(orientation == WEST){
	                                 if(c - 1 >= 0 && maze[r][c-1] == ' ')
	                                      c--;
	                       } else if(orientation == EAST){
	                                 if(c + 1 < cols && maze[r][c+1] == ' ') 
	                                     c++;
	                       }
	             }
	      }
	      printf("%d %d %c\n", r+1, c+1, leg[orientation]);
	}
	
}

