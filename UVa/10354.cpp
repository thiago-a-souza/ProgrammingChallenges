#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>

#define MAXV 120
#define MAXE 500
#define INVALID -1

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define INF 1000000
using namespace std;


int P, R, BH, OF, YH, M;

void floyd(int a[MAXV][MAXV]){

	for(int k=1; k<=P; k++)
	   for(int i=1; i<=P; i++)
	      for(int j=1; j<=P; j++)
	           a[i][j] = MIN(a[i][j], a[i][k] + a[k][j]);

}



int main(){
int adjBoss[MAXV][MAXV], adjYou[MAXV][MAXV];
int s, t, w;
bool marked[MAXV];


	while(scanf("%d %d %d %d %d %d",&P, &R, &BH, &OF, &YH, &M) != EOF){

	      
	      for(int i=1; i<=P; i++){
	         for(int j=1; j<=P; j++){
	             adjBoss[i][j] = adjYou[i][j] = INF;
	         }
	         adjBoss[i][i] = adjYou[i][i] = 0;
	      }
	      
	      for(int i=0; i<R; i++){
	          scanf("%d %d %d",&s, &t, &w);
	          adjBoss[s][t] = adjYou[s][t] = w;
	          adjBoss[t][s] = adjYou[t][s] = w;
	      }
	      
	      floyd(adjBoss);
	      
	      memset(marked, 0, sizeof(marked));
	      for(int i=1; i<=P; i++){
	          if(adjBoss[BH][i] + adjBoss[i][OF] == adjBoss[BH][OF])
	             marked[i] = true; 
	      }
	      
	      for(int i=1; i<=P; i++){
	         if(!marked[i])
	            continue;
	         for(int j=1; j<=P; j++){
	             adjYou[i][j] = adjYou[j][i] = INF;
	         }
	      }
	      
	      floyd(adjYou);
	      if(adjYou[YH][M] < INF)
	         printf("%d\n", adjYou[YH][M]);
	      else 
	         printf("MISSION IMPOSSIBLE.\n");
	
	    
	      
	}
	
	return 0;
}

