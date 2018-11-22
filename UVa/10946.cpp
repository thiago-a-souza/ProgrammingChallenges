#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 100
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

char board[MAX][MAX];
bool visited[MAX][MAX];
int rows, cols;

typedef struct { 
char label;
int sz;
} THole;

int cmp(const void *a, const void *b){
THole *x, *y;
    x = (THole*)a;
    y = (THole*)b;
    if(x->sz < y->sz)
      return 1;
    if(x->sz > y->sz)
      return -1;
    if(x->label < y->label)
       return -1;
    if(x->label > y->label)
       return 1;
    return 0;
}

int floodFill(int x, int y, char search){

	if(x < 0 || x >= rows || y < 0 || y >= cols)
	   return 0;
    if(!visited[x][y] && board[x][y] == search){
        visited[x][y] = true;
        return 1 + floodFill(x-1, y, search) + floodFill(x, y-1, search) +
                   floodFill(x, y+1, search) + floodFill(x+1, y, search);
    }
	return 0;
}

int main(){
THole hole[MAX*MAX];
int line = 1, index;

	while(true){
		scanf("%d %d\n",&rows, &cols);
		memset(board, '\0', sizeof(board));
		memset(visited, 0, sizeof(visited));
		index = 0;

		if(!rows || !cols)
		   break;

		for(int i=0; i<rows; i++)
		    scanf("%s", board[i]);

		for(int i=0; i<rows; i++)
		   for(int j=0; j<cols; j++)
		       if(!visited[i][j] && board[i][j] >= 'A' && board[i][j] <= 'Z'){
		         hole[index].label = board[i][j];
		         hole[index].sz = floodFill(i, j, board[i][j]);
		         index++;
		       }
		       
        qsort(hole, index, sizeof(THole), cmp);
        
        printf("Problem %d:\n", line++);
        for(int i=0; i<index; i++)
           printf("%c %d\n", hole[i].label, hole[i].sz);
	}
	return 0;
}

