#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 200

#define WHITE 1 
#define BLACK 2

using namespace std;

int adj[MAX][MAX*100], grau[MAX];
int ans[MAX], max_blacks;
int n;

void candidates(int *c, int index, int *ncand, int *colour){
bool adjBlack = false;
	if(grau[index] == 0){
	   c[0] = BLACK;
	   *ncand = 1;
	   return;
	}

	for(int i=0; i<grau[index]; i++)
	    if(colour[adj[index][i]] == BLACK){
	       adjBlack = true;
	       break;
	    }
	if(!adjBlack){
	  c[0] = BLACK;
	  c[1] = WHITE;
	  *ncand = 2;
	} else {
	  c[0] = WHITE;
	  *ncand = 1;
	}
	
	
}

void backtrack(int *colour, int index, int cnt){
int c[2], ncand;
//int cont;
int v;
	if(index >= n || cnt == n || n - index < max_blacks - cnt)
	   return ;
 
	index++;
	candidates(c, index, &ncand, colour);
	v = cnt;
	for(int i=0; i<ncand; i++){
	   colour[index] = c[i];
	   if(colour[index] == BLACK)
	      cnt++;
	   else 
	      cnt = v;
	   if(n - index < max_blacks - cnt)
          return;   
	   backtrack(colour, index, cnt);
	   if(cnt > max_blacks){
	      max_blacks = cnt;
	      for(int jj=1; jj<=n; jj++)
	          ans[jj] = colour[jj];
	   }  
	}
}


main(){
int tests, k;
int u, v;
int colour[MAX];
bool first;

	scanf("%d",&tests);
	while(tests--){
	     scanf("%d %d",&n,&k);
	     memset(grau, 0, sizeof(grau));
	     memset(colour, 0, sizeof(colour));
	     
	     for(int i=0; i<k; i++){
	        scanf("%d %d",&u, &v);
	        adj[u][grau[u]++] = v;
	        adj[v][grau[v]++] = u;
	     }
	     
	     max_blacks = 0;
	     backtrack(colour, 0,0);

	     printf("%d\n",max_blacks);
	     first = true;
         for(int i=1; i<=n; i++)
	         if(ans[i] == BLACK){
	           if(first){
	              first = false;
	              printf("%d",i);
	           } else {
	              printf(" %d",i);
	           }
	         }
	    printf("\n");
	}
}





