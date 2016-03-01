#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 5000

using namespace std;

int N, n;
char sq1[MAX][MAX], sq2[MAX][MAX], aux[MAX][MAX];

void rotate(){

	for(int i=0, y=n-1; i<n; i++, y--)
	   for(int j=0, x=0; j<n; j++, x++)
	       aux[x][y] = sq2[i][j];
	for(int i=0; i<n; i++)
	   for(int j=0; j<n; j++)
	       sq2[i][j] = aux[i][j];
}


bool containsSquare(int r, int c){
	for(int i=r, x=0; x<n; i++, x++)
	   for(int j=c, y=0; y<n; j++, y++)
	      if(sq1[i][j] != sq2[x][y])
	         return false;
	return true;
}


main(){
int ans;
bool first;
	while(true){
		scanf("%d %d",&N, &n);
		if(!N && !n)
		   break;
		for(int i=0; i<N; i++)
		   scanf("%s",sq1[i]);   
		for(int i=0; i<n; i++)
		   scanf("%s",sq2[i]);   
		   		
		first = true;
		
		for(int rot=0; rot<4; rot++){
		   ans = 0;
		   for(int i=0; i<=(N-n); i++)
		      for(int j=0; j<=(N-n); j++){
		         if(containsSquare(i,j))
		           ans++;
		      }
		   if(first){
		      printf("%d",ans);
		      first = false;
		   } else 
		      printf(" %d",ans);
		      
		   if(rot < 3)
		      rotate();
		}
		printf("\n");
		      
	}
}

