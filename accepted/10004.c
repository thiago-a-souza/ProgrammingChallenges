/* BICOLORING */
#include <stdio.h>

#define MAX 200
#define WHITE 1
#define BLACK 2
#define RED 3
#define INF 32000
#define TRUE 1
#define FALSE 0

int adj[MAX][MAX];

void clearbuffer(){
int i, j;

	for(i=0;i<MAX;i++)
	   for(j=0;j<MAX;j++)
		adj[i][j]=0;
}

int BFS(int s){
int stack[MAX], cor[MAX], index;
int i, u;
	for(i=0;i<MAX;i++)
	   cor[i]=WHITE;
	cor[s]=RED;
	stack[0]=-1;
	stack[1]=s;
	index=1;
	while(index>0){
	      u=stack[index--];
	      for(i=0;i<MAX;i++)
		if(adj[u][i]!=0)
		  if(cor[i]==WHITE){
		    if(cor[u]==RED)
			cor[i]=BLACK;
		    else
			cor[i]=RED;
		    stack[++index]=i;
		  }
		  else
			if(cor[i]==cor[u])
			  return FALSE;
	}
	return TRUE;
	
}

main(){
int i, n, l, a,b;
	scanf("%d",&n);
	while(n!=0){
		scanf("%d",&l);
		for(i=0;i<l;i++){
		   scanf("%d %d",&a,&b);
		   adj[a][b]=1;
		   adj[b][a]=1;
		}
		if(BFS(l-1)==TRUE)
		  printf("BICOLORABLE.\n");
		else
		  printf("NOT BICOLORABLE.\n");
		clearbuffer();
		scanf("%d",&n);
	}
}

