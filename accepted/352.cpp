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

#define MAX 1000

char grid[MAX][MAX];
int n;
int visited[MAX][MAX];

using namespace std;

void visitAll(int i, int j){
     if(i < 0 || j < 0 || i >= n || j >= n)
       return;
     visited[i][j] = 1;
     
     if(grid[i+1][j] == '1' && visited[i+1][j] == 0)
        visitAll(i+1, j);
     if(grid[i-1][j] == '1' && visited[i-1][j] == 0)
        visitAll(i-1, j);
     if(grid[i][j+1] == '1' && visited[i][j+1] == 0)
        visitAll(i, j+1);
     if(grid[i][j-1] == '1' && visited[i][j-1] == 0)
        visitAll(i, j-1);
     if(grid[i-1][j-1] == '1' && visited[i-1][j-1] == 0)
        visitAll(i-1,j-1);
     if(grid[i-1][j+1] == '1' && visited[i-1][j+1] == 0)
        visitAll(i-1, j+1);
     if(grid[i+1][j-1] == '1' && visited[i+1][j-1] == 0)
        visitAll(i+1, j - 1);
     if(grid[i+1][j+1] == '1' && visited[i+1][j+1] == 0)
        visitAll(i+1, j+1);
}

main(){
int cont;
int t = 1;
		while(scanf("%d",&n) != EOF){
		     for(int i=0; i<n; i++)
		         scanf("%s",grid[i]);
		     for(int i=0; i<n; i++)
		        for(int j=0; j<n; j++)
		           visited[i][j] = 0;   
		     cont = 0;       
		     for(int i=0; i<n; i++)
		        for(int j=0; j<n; j++)
		           if(grid[i][j] == '1' && visited[i][j] == 0){
		              cont++;
		              visitAll(i,j);
		           }
		     printf("Image number %d contains %d war eagles.\n",t,cont);
		     t++;
			 
		}



}

