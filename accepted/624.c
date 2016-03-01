/* CD - 24/06/2007 */
#include<stdio.h>

#define MAX 30000
#define MAXL 30
#define UP 1
#define CORNER 2
#define maxi(a,b) (a>b ? a : b)

int cam[MAXL][MAX], costs[MAXL],tab[MAXL][MAX];
int tam, total, it;

void printPath(int u, int v){

	if(u == 0 || v == 0)
	  return;

	if(cam[u][v]==CORNER){
	  if(total+costs[u]<=tam){
	    total = total+costs[u];
	  }
	  printPath(u-1,v-costs[u]);
	  printf("%d ", costs[u]);
	}
	else
	   printPath(u-1,v);

}

main(){
register int i, j;
int n;

	while((scanf("%d",&tam))!=EOF){
	     scanf("%d",&n);
	     
	     for(i=1; i<=n; i++)
	        scanf("%d",&costs[i]);
	     for(i=0; i<=tam; i++)
	        tab[0][i]=0;
	     for(i=1; i<=n; i++)
	        tab[i][0]=0;
	     for(i=1; i<=n; i++)
	        for(j=1; j<=tam; j++)
	           if(costs[i] > j){
	             tab[i][j] = tab[i-1][j];
	             cam[i][j] = UP;
	           }
	           else{
	             tab[i][j] = maxi(tab[i-1][j],tab[i-1][j-costs[i]]+costs[i]);
	             if(tab[i][j]==tab[i-1][j-costs[i]]+costs[i])
	               cam[i][j] = CORNER;
	             else
	               cam[i][j] = UP;
	           }
	     total = 0;
	     it=0;
	     printPath(n,tam);
	     printf("sum:%d\n", total);
	}

}
