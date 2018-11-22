/* Tic Tac Toe - 15/11/2007 */
/* Categoria: AD HOC        */

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

using namespace std;

main(){
int n, cross, circle;
char buff[3][4];
bool crossWins, circleWins;

	scanf("%d",&n);
	while(n--){

	     f(i,3)
	      scanf(" %s",buff[i]);
	      
	     cross = circle = 0; 
	      
	     f(i,3)
	      f(j,3)
	        if(buff[i][j] == 'X')
	          cross++;
	        else if(buff[i][j] == 'O')
	               circle++;

	     crossWins = circleWins = false;
	     
	     if((buff[0][0] == 'X' && buff[0][1] == 'X' && buff[0][2] == 'X') ||
	        (buff[1][0] == 'X' && buff[1][1] == 'X' && buff[1][2] == 'X') ||
	        (buff[2][0] == 'X' && buff[2][1] == 'X' && buff[2][2] == 'X') ||
	        (buff[0][0] == 'X' && buff[1][0] == 'X' && buff[2][0] == 'X') ||
	        (buff[0][1] == 'X' && buff[1][1] == 'X' && buff[2][1] == 'X') ||
	        (buff[0][2] == 'X' && buff[1][2] == 'X' && buff[2][2] == 'X') ||
	        (buff[0][0] == 'X' && buff[1][1] == 'X' && buff[2][2] == 'X') ||
	        (buff[0][2] == 'X' && buff[1][1] == 'X' && buff[2][0] == 'X'))
	          crossWins = true;

	     if((buff[0][0] == 'O' && buff[0][1] == 'O' && buff[0][2] == 'O') ||
	        (buff[1][0] == 'O' && buff[1][1] == 'O' && buff[1][2] == 'O') ||
	        (buff[2][0] == 'O' && buff[2][1] == 'O' && buff[2][2] == 'O') ||
	        (buff[0][0] == 'O' && buff[1][0] == 'O' && buff[2][0] == 'O') ||
	        (buff[0][1] == 'O' && buff[1][1] == 'O' && buff[2][1] == 'O') ||
	        (buff[0][2] == 'O' && buff[1][2] == 'O' && buff[2][2] == 'O') ||
	        (buff[0][0] == 'O' && buff[1][1] == 'O' && buff[2][2] == 'O') ||
	        (buff[0][2] == 'O' && buff[1][1] == 'O' && buff[2][0] == 'O'))	     
	           circleWins = true;
	           
	     if(crossWins && circleWins)
	        printf("no\n");
	     else if(crossWins)
	             if(cross == circle + 1)
	                printf("yes\n");
	             else
	                printf("no\n");
	     else if(circleWins)
	             if(circle == cross)
	                printf("yes\n");
	             else
	                printf("no\n");
	     else {
	     	   if(cross == circle + 1 || cross == circle)
	     	      printf("yes\n");
	     	   else
	     	      printf("no\n");
	     	   
	     
	     }
	            
	
	}

}
