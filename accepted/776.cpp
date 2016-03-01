/* Monkeys in a Regular Forest - 05/02/2008 */
/* Category: ad hoc - flood fill */
/* Comments: output related problem */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define mp(a,b) make_pair((a),(b))
#define all(c) (c).begin(),(c).end()
#define ff(i,v,n) for(int i=v; i<n; i++)
#define f(i,n) ff(i,0,n)
#define pb push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define debug(x) 
#define LEN 1000

using namespace std;

char mapa[LEN][LEN];
int visit[LEN][LEN];
int row, column, monkey;

void floodFill(int x, int y){

	visit[x][y] = monkey;
	if(x + 1 < row){
		if(mapa[x+1][y] == mapa[x][y] && visit[x+1][y] == 0)
		   floodFill(x+1,y);
		if(y-1 >= 0 && mapa[x+1][y-1] == mapa[x][y] && visit[x+1][y-1] == 0)
		   floodFill(x+1,y-1);
		if(y+1 < column && mapa[x+1][y+1] == mapa[x][y] && visit[x+1][y+1] == 0)
		   floodFill(x+1,y+1);
	}
	
	if(x - 1 >= 0){
		if(mapa[x-1][y] == mapa[x][y] && visit[x-1][y] == 0)
		   floodFill(x-1,y);
		if(y-1 >=0 && mapa[x-1][y-1] == mapa[x][y] && visit[x-1][y-1] == 0)
		   floodFill(x-1,y-1);
		if(y+1 < column && mapa[x-1][y+1] == mapa[x][y] && visit[x-1][y+1] == 0)
		   floodFill(x-1,y+1);
	}
	if(y-1 >= 0 && mapa[x][y-1] == mapa[x][y] && visit[x][y-1] == 0)
	  floodFill(x,y-1);
	if(y+1 < column && mapa[x][y+1] == mapa[x][y] && visit[x][y+1] == 0)
	   floodFill(x,y+1);

}

void printLine(){
char str[10];
int biggest[column], sz, total;
int spaces;

	memset(biggest,0,sizeof(biggest));

	f(i, row)
	 f(j, column){
	   sprintf(str,"%d",visit[i][j]);
	   sz = strlen(str);
	   if(sz > biggest[j])
	     biggest[j] = sz;
	 }
	 
	total = 0;
	
	f(i, column){
	 biggest[i] += total - 1;
	 total = biggest[i] + 2;
	}
	
	f(i, row){
	  total = 0;
	  f(j, column){
	    sprintf(str,"%d",visit[i][j]);
	    sz = strlen(str);
	    spaces = biggest[j] - (sz - 1 + total);
	    total += spaces + sz;
	    f(i,spaces)
	      printf(" ");
	    printf("%s",str);
	  }
	  printf("\n");
	}
	printf("%\n");
}

main(){
char ans[LEN][LEN];
char str[LEN];
int tmp;



	while(cin.getline(str,LEN)){

		column = strlen(str);

		tmp = 0;		   
	    for(int i=0, j=0; i<column; i=i+2,j++){
	       mapa[0][j] = str[i];
	       tmp++;
	    }
	    row = 1; 
	    while(cin.getline(str,LEN)){
	         if(strlen(str) == 1 && str[0] == '%'){
	            break;
	         }
	         for(int i=0, j=0; i<column; i=i+2,j++)
	            mapa[row][j] = str[i];
	         row++;
	    }

	    column = tmp;

		f(i, row)
		  f(j, column)
		    visit[i][j] = 0;

		monkey = 1;
		
		f(i, row)
		  f(j, column)
		    if(visit[i][j] == 0){
		      floodFill(i,j);
		      monkey++;
		    }
		printLine();
	}
}


