/* Robot Motion - 28/06/2007*/
#include<iostream>
#include<cstdio>

using namespace std;

#define BRANCO 1
#define PRETO 2

int cor[15][15], total, nocycle;
int lin, col, ciclox, cicloy;
char map[15][15];

void dfs(int u, int v){

	if(u>=0 && v>=0 && u<lin && v<col){
	  if(cor[u][v] == BRANCO){
	    total++;
	    cor[u][v] = PRETO;
	    if(map[u][v]=='N')
	      dfs(u-1,v);
	    else if(map[u][v]=='S')
	           dfs(u+1,v);
	    else if(map[u][v]=='E')
		   dfs(u,v+1);
	    else if(map[u][v]=='W')
	            dfs(u,v-1);
	  }
	  else{
	     ciclox = u;
	     cicloy = v;
	  }

	}
}

void printPath(int u, int v){

	if(u>=0 && v>=0 && u<lin && v<col){
	  if(u==ciclox && v==cicloy)
	     return;
	  nocycle++;
	  if(map[u][v]=='N')
	    printPath(u-1,v);
	  else if(map[u][v]=='S')
	         printPath(u+1,v);
	  else if(map[u][v]=='E')
	         printPath(u,v+1);
	  else if(map[u][v]=='W')
	         printPath(u,v-1);
	}
}

void show(){
int i, j;

	for(i=0; i<lin; i++){
	   for(j=0; j<col; j++)
	       cout << map[i][j];
	   cout << endl;
	}
}

void clearBuffer(int l, int c){
int i, j;

	for(i=0; i<l; i++)
	   for(j=0; j<c; j++)
	      cor[i][j] = BRANCO;
}

main(){
int icol, i;

	while(1){
	   cin >> lin >> col >> icol;
	   if(!lin && !col && !icol)
	     break;
	   clearBuffer(lin,col);
	   for(i=0; i<lin; i++)
	      cin >> map[i];
	   total = 0;
	   ciclox = -1;
	   cicloy = -1;
	   dfs(0,icol-1);
	   if(ciclox==-1)
	     cout << total << " step(s) to exit" << endl;
	   else{
	     nocycle = 0;
	     printPath(0,icol-1);
	     printf("%d step(s) before a loop of %d step(s)\n",nocycle,total-nocycle);
	   }
	}
}

