#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 30

using namespace std;

double m[MAX][MAX][MAX];
int p[MAX][MAX][MAX];
int n;
int ans[MAX+2], pos;

void showPath(int a, int b, int step){
   if(step < 0)
      return;
   ans[pos++] = p[a][b][step];
   showPath(a, p[a][b][step], step-1);
}

main(){
double tmp;
bool arbitrage;
	while(scanf("%d",&n) != EOF){
	     for(int s=1; s<n; s++)
	     for(int i=0; i<n; i++)
	     for(int j=0; j<n; j++)
	     for(int k=0; k<n; k++)
	        m[i][j][s] = 0.0;
	        
	     for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++){
	            if(i == j)
	               m[i][j][0] = 1.0;
	            else
	               scanf("%lf",&m[i][j][0]);
	            p[i][j][0] = i;
	        }
	    for(int s=1; s<n; s++){
	       for(int i=0; i<n; i++)
	          for(int j=0; j<n; j++)
	             for(int k=0; k<n; k++){
	                 tmp = m[i][k][s-1]*m[k][j][0];
	                 if( tmp > m[i][j][s] ){
	                   m[i][j][s] = tmp;
	                   p[i][j][s] = k;
	                 }
	             }
	    }
	    arbitrage = false;
	    for(int s=1; s<n; s++)
	       for(int i=0; i<n; i++)
	          if(m[i][i][s] > 1.01){
	             arbitrage = true;
	             pos = 0;
	             showPath(i,i,s);
	             i = n; s = n;

	          }
	    if(arbitrage){
	       for(int i=pos-1; i>=0; i--)
	          printf("%d ",ans[i]+1);
	       printf("%d\n",ans[pos-1]+1);
	    } else {
	       printf("no arbitrage sequence exists\n");
	    }
	}
}

