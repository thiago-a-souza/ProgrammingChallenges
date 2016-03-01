#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 500
#define INF 2147483647
#define DEBUG(X)

int mat[MAX][MAX], rows, cols;
int ans[MAX][MAX], parent[MAX][MAX];
int path[MAX][MAX], sz;

void walk(int x, int y){

	if(y == 0){
	  path[sz][y] = x;
	  return;
	}

	path[sz][y] = x;
	walk(parent[x][y],y-1);
}

bool isSmallerPath(int x1, int x2, int y){
	sz = 0;
	walk(x1, y);
	sz++;
	walk(x2, y);
	
	for(int i=0; i<=y; i++){
	   if(path[0][i] < path[1][i]) 
	      return false;
	   else if(path[0][i] > path[1][i])
	           return true;
	}
	return false;
}


using namespace std;

main(){
int min, sum, p;
int grade[MAX];

		while(scanf("%d %d",&rows, &cols) != EOF){
		    for(int i=0; i<rows; i++)
		       for(int j=0; j<cols; j++)
		          scanf("%d",&mat[i][j]);
		    for(int i=0; i<rows; i++)
		       ans[i][0] = mat[i][0];
		    
            for(int j=1; j<cols; j++)
               for(int i=0; i<rows; i++){
                  min = ans[i][j-1];
                  p = i;
                  
                  if( ans[(i+rows-1)%rows][j-1] < min || 
                     (ans[(i+rows-1)%rows][j-1] == min && isSmallerPath(p,(i+rows-1)%rows, j-1))){
                     min = ans[(i+rows-1)%rows][j-1];
                     p = (i+rows-1)%rows;
                  }
                  if( ans[(i+1)%rows][j-1] < min ||
                     (ans[(i+1)%rows][j-1] == min && isSmallerPath(p,(i+1)%rows, j-1))){
                          min = ans[(i+1)%rows][j-1];
                          p = (i+1)%rows;
                  }
                  ans[i][j] = mat[i][j] + min;
                  parent[i][j] = p;
               } 
 


             min = INF;
             for(int i=0; i<rows; i++)
                if(ans[i][cols-1] < min)
                   min = ans[i][cols-1];
             sz = 0;
             for(int i=0; i<rows; i++)
                 if(ans[i][cols-1] == min){
                    walk(i,cols-1);
                    sz++;
                 }

             memset(grade, 0, sizeof(grade));


			for(int j=0; j<cols; j++)
			   for(int i=0; i<sz-1; i++){
			      if(grade[i] == 1) 
			         continue;
			      for(int k=i+1; k<sz; k++){
			          if(grade[k] == 0 && path[i][j] < path[k][j]){
			             grade[k] = 1;
			          } else if(grade[k] == 0 && path[i][j] > path[k][j]){
			                  grade[i] = 1;   
			                  break;
			          }
			      }
			    }
			sum = 0;
			for(int i=0; i<cols; i++)
			   if(grade[i] == 0){
			     for(int j=0; j<cols; j++){
			        if(j > 0)
			          printf(" %d",path[i][j]+1);
			        else
			          printf("%d",path[i][j]+1);
			        sum += path[i][j];
			     }
                 printf("\n%d\n",min);
			     break;
			   }
			   

		             
		}

}

