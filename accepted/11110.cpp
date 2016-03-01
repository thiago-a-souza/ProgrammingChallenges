#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAXN 200
#define MAXLINE 10000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int board[MAXN][MAXN], n;
bool visited[MAXN][MAXN];


int floodFill(int x, int y, int search){

	if(x < 0 || y < 0 || x >= n || y >= n)
	   return 0;
    if(board[x][y] == search && !visited[x][y]){
       visited[x][y] = 1;
       return 1 + floodFill(x-1, y, search) + floodFill(x+1, y, search) + floodFill(x, y-1, search) + floodFill(x, y+1, search);
    }
    return 0;
    
}

int main(){
char str[MAXLINE];
int len, aux, x, y, cnt;
int label;
bool flag, ans;

	while(true){
		  scanf("%d\n",&n);
		  if(n == 0)
		     break;
	      memset(board, 0, sizeof(board));
	      memset(visited, 0, sizeof(visited));
	      label = 1;
		  for(int i=0; i<n-1; i++){
		      cin.getline(str, MAXLINE);
		      len = strlen(str);
		      cnt = 0; 
		      
		      for(int j=0; j<len; j++){
		         if(str[j] >= '0' && str[j] <= '9'){
		            int aux = atoi(&str[j]);
		            cnt++;
		            if(cnt == 1){
		               x = aux;
		            } else {
		               y = aux;
		               cnt = 0;
		               board[x-1][y-1] = label;
		            }
		         }
		         while(j < len && str[j] >= '0' && str[j] <= '9')
		              j++;
		      }
		      label++;
		  }		  
		  
		  ans = true;
		  for(int f=0; f<label && ans; f++){
		     flag = true;
		     for(int i=0; i<n && flag; i++)
		        for(int j=0; j<n && flag; j++){
		           if(board[i][j] == f){
		              if(floodFill(i,j, f) != n)
		                 ans = false;
		              flag = false;
		           }
		        }
		  }
		  
		  if(ans)
		     printf("good\n");
		  else
		     printf("wrong\n");
		  
	}
	return 0;
}

