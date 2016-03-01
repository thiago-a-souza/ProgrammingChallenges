#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 1000

using namespace std;

int main(){
int win[MAX][MAX], n;
int ans;

	while(scanf("%d",&n) != EOF){
	      
	      for(int i=0; i<n; i++)
	         for(int j=0; j<n; j++)
	             scanf("%d", &win[i][j]);
	      
	      ans = 0;
	      
	      for(int i=0; i<n; i++)
	         for(int j=0; j<n; j++)
	            for(int k=0; k<n; k++){
	                if(i == j || i == k || j == k)
	                   continue;
	                if(((i<j && j < k) || (i > j && j > k)) && win[i][j] && win[j][k] && win[k][i])
	                   ans++;
	                else if((i<j && j < k) && !win[i][j] && !win[j][i] && !win[i][k] && !win[i][k] && !win[k][i] && !win[j][k] && !win[k][j])
	                   ans++;
	            }
	      printf("%d\n", ans);
	      if(ans == 0)
	        continue;
	        
	      for(int i=0; i<n; i++)
	         for(int j=0; j<n; j++)
	            for(int k=0; k<n; k++){
	                if(i == j || i == k || j == k)
	                   continue;
	                if(((i<j && j < k) || (i > j && j > k)) && win[i][j] && win[j][k] && win[k][i])
	                   printf("%d %d %d\n", i+1, j+1, k+1);
	                else if((i<j && j < k) &&!win[i][j] && !win[j][i] && !win[i][k] && !win[i][k] && !win[k][i] && !win[j][k] && !win[k][j])
	                   printf("%d %d %d\n", i+1, j+1, k+1);
	            }
	            
	                   
	      
	}
	return 0;
}
