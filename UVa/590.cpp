#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>


#define MAXN 11
#define MAXDAYS 1001
#define INF 2147483647
#define MAXK 2000


using namespace std;


typedef struct {
int sch[MAXN][MAXDAYS];
} TAdj;


TAdj adj[MAXN];
int N, K;


int sum(int a, int b){

	if(a == INF || b == INF)
	   return INF;
	return a + b;

}

int main(){
int line = 1;
int index, m, aux, minDist;
int A[MAXN][MAXK];


	while(true){
		scanf("%d %d", &N, &K);
		if(N == 0 && K == 0)
		   break;
				   
		for(int city = 0; city < N; city++){
		   index = 0;
		   for(int i = 0; i < N-1; i++){
		      if(index == city)
		         index++;
		      scanf("%d", &m);
		    
		      for(int j=1; j<=m; j++)
		          scanf("%d", &adj[city].sch[index][j]);
		      
		      aux = 1;
		      for(int j=m+1; j<MAXDAYS; j++){
		          adj[city].sch[index][j] = adj[city].sch[index][aux];
		          aux++;
		          if(aux > m)
		             aux = 1;
		      }
		      if(city > 0)
		         adj[city].sch[index][1] = INF;
		      
		      index++;
		   }
		}

	    for(int day=0; day<=K; day++)
	       for(int city = 0; city<N; city++)
	           A[city][day] = INF;

	    A[0][0] = 0;
	    for(int day=1; day<=K; day++){
	       for(int src = 0; src < N; src++){
	          minDist = INF;
	          for(int dst = 0; dst < N; dst++){
	              if(src == dst || adj[dst].sch[src][day] == 0)
	                 continue;
	              aux = A[dst][day-1];
	              if(sum(aux, adj[dst].sch[src][day]) < minDist)
	                 minDist = sum(aux, adj[dst].sch[src][day]);
	                 
	              
	          } 
              A[src][day] = minDist;
	         
	       }
	    }

		printf("Scenario #%d\n", line++);
		if(A[N-1][K] != INF)
           printf("The best flight costs %d.\n", A[N-1][K]);
        else
           printf("No flight possible.\n");
        printf("\n");
		
	}
	return 0;
}

