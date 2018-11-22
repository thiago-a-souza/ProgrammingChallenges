/* Walking on the Safe Side - 28/07/2007 **************************************/
/* Algoritmo: 1 na posicao adj[1][1]
/*	      0 nas posicoes proibidas e nas posicoes adj[0][j] e adj[j][0]
/*	      nas demais posicoes marcar adj[i][j] = adj[i-1][j] + adj[i][j-1]
/******************************************************************************/
#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define MAX 500

main(){
register int i, j, k;
int adj[MAX][MAX], n, L, C;
int tmp, strsize, lblock, cblock;
char str[MAX], ch;

	cin >> n;
	for(i=0; i<n; i++){
	   if(i>0)
	     cout << endl;
	   cin >> L >> C;

   	   for(j=0; j<=C; j++)
	      adj[0][j] = 0;
	   for(j=1; j<=L; j++)
	      adj[j][0] = 0;
	      
	   for(j=1; j<=L; j++)
	      for(k=1; k<=C; k++)
	         adj[j][k] = -1;

	   ch = getchar();// pega o ultimo \n pra usar o getline
	   
	   for(j=0; j<L; j++){
	      cin.getline(str,MAX);
	      lblock = atoi(str);
	      k=0;
	      strsize = strlen(str);
	      while(1){
	           while(isdigit(str[k]) && k<strsize)
	                k++;
	           while(!isdigit(str[k]) && k<strsize)
	                k++;
	           if(k<strsize){
	             tmp = atoi(&str[k]);
	             adj[lblock][tmp] = 0;
	           }
	           else
	             break;
	      }
	   }
	   adj[1][1] = 1;
	   for(j=2; j<=C; j++)
	      if(adj[1][j]!=0)
	         adj[1][j] = adj[1][j-1];
	   for(j=2; j<=L; j++)
	      for(k=1; k<=C; k++)
	         if(adj[j][k]!=0)
	            adj[j][k] = adj[j-1][k] + adj[j][k-1]; 
	   cout << adj[L][C] << endl;
	}
	   
}




