#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 30
#define INF 9999999
using namespace std;

int N, M;
int mat[MAX][MAX];

main(){
char names[MAX][MAX];
int u, v, w;
int ans[MAX], low, index;
int line = 1;

	while(true){
		scanf("%d %d",&N,&M);
		if(N == 0 && M == 0)
		   break;
		for(int i=0; i<N; i++)
		   scanf("%s",names[i]);
		for(int i=0; i<N; i++){
		   for(int j=0; j<N; j++)
		      mat[i][j] = INF; 
		   mat[i][i] = 0;
		}  
		for(int i=0; i<M; i++){
            scanf("%d %d %d",&u,&v,&w);
            mat[u-1][v-1] = w;
            mat[v-1][u-1] = w;
		}
		
		for(int k=0; k<N; k++)
		   for(int i=0; i<N; i++)
		      for(int j=0; j<N; j++)
		          if(mat[i][k] < INF && mat[k][j] < INF && 
		             mat[i][k] + mat[k][j] < mat[i][j])
		             mat[i][j] = mat[i][k] + mat[k][j];
		             
		for(int i=0; i<N; i++)
		   ans[i] = 0;
		for(int i=0; i<N; i++)
		   for(int j=0; j<N; j++)
		       if(i != j && mat[i][j] < INF){
                 ans[j] += mat[i][j];
		       }
		low = INF;
		index = 0;
		for(int i=0; i<N; i++)
		   if(ans[i] < low){
		      low = ans[i];
		      index = i;
		   }
		printf("Case #%d : %s\n", line++, names[index]);
	}

}