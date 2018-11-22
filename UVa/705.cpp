/* Slash Maze 14/08/2007 */
#include<iostream>
#include<cstdio>

#define PRINT(x)
#define MAX 300
#define EMPTY 0
#define OBS 1
#define FLOOD 2

#define UP 3
#define DOWN 4
#define LEFT 5
#define RIGHT 6

int ist, jst;
int C, L;
int a[MAX][MAX], ciclelength, squares;
bool iscicle;

using namespace std;



void floodFill(int i, int j){

	if(i>=0 && j>=0 && i<L && j<C)
	  if(a[i][j]==EMPTY){
	    squares++;
	    a[i][j]=FLOOD;
	    floodFill(i+1,j);
	    floodFill(i,j-1);
	    floodFill(i,j+1);
	    floodFill(i-1,j);
	  }

}

void flood(int i, int j, int parent){

	if(iscicle)
	  return;

	if(i>=0 && j>=0 && i<L && j<C)
	  if(a[i][j]==FLOOD){//cout << "-> i " << i << " j " << j << endl;
	    a[i][j]=parent;
	    ciclelength++;
	    
	    if(i==ist && j-1==jst && a[i][j]!=LEFT && ciclelength==squares){
	       iscicle = true;
	       return;
	    }
	    flood(i,j-1,RIGHT); // esq
	    if(i==ist && j+1==jst && a[i][j]!=RIGHT && ciclelength==squares){
	       iscicle = true;
	       return;
	    }
	    flood(i,j+1,LEFT); // dir  
	    if(i-1==ist && j==jst && a[i][j]!=UP && ciclelength==squares){
	       iscicle = true;
	       return;
	    }
	    flood(i-1,j,DOWN); // cima      
	    if(i+1==ist && j==jst && a[i][j]!=DOWN && ciclelength==squares){
	      iscicle = true;
	      return;
	    }
	    flood(i+1,j,UP); // baixo
	  }

}



void clearBuffer(){
	for(int i=0; i<L; i++)
	   for(int j=0; j<C; j++)
	      a[i][j]=EMPTY;
}

main(){
char ch;
int biggestLength, cicles;
int ite=1;

	cin >> C >> L;
	while(C && L){
	     C*=3; L*=3;
	     clearBuffer();
	     for(int i=0; i<L; i+=3)
	        for(int j=0; j<C; j+=3){
		   cin >> ch;
		   if(ch=='\\')
		     a[i][j]=a[i+1][j+1]=a[i+2][j+2]=OBS;
		   else
		     a[i][j+2]=a[i+1][j+1]=a[i+2][j]=OBS;
		}
	     biggestLength=0; cicles=0;
	     for(int i=0; i<L; i++)
	        for(int j=0; j<C; j++)
	           if(a[i][j]==EMPTY){
	             squares=0;
		     floodFill(i,j);
		     if(squares>11){
		       ciclelength=0; iscicle=false;
		       ist=i; jst=j; PRINT(cout << "i " << i << " j " << j << endl;)
		       flood(ist,jst,UP); PRINT(cout << ciclelength << " " << iscicle <<  endl);
		       if(iscicle){
		         cicles++;
		         if(ciclelength>biggestLength)
		           biggestLength = ciclelength;
		       }
		     }
	           }
	     printf("Maze #%d:\n",ite); ite++;
	     if(cicles>0)
	       printf("%d Cycles; the longest has length %d.\n",cicles,biggestLength/3);
	     else
	       printf("There are no cycles.\n");
	     cout << endl;
	     cin >> C >> L; 
	}

}
