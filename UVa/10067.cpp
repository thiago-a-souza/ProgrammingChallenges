/****************************
PLAYING WITH WHEELS - 06/04/2007

Para solucionar o problema eh montado um grafo com todas as possibilidades para numeros.
Ex.: para o numero 9051: 9052,9061,9151,9951,0052
Apos isso, os vertices proibidos sao pintados com a cor preta(para nao passar pelo vertice).
Finalmente eh percorrido o grafo com o BFS, e calculada a distancia ate o objetivo.

*****************************/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define BRANCO '1'
#define CINZA '2'
#define PRETO '3'
#define MAX 10000
#define INF 320000

vector <int> adj[MAX];
char cor[MAX];
int d[MAX];

int readNumber(){
int a, b;

	cin >> a;
	b = a*1000;
	cin >> a;
	b += a*100;
	cin >> a;
	b += a*10;
	cin >> a;
	b += a;
	return b;
}

void BFS(int s, int end){
register int i;
int u;
queue<int> Q;


	d[s]=0;
	Q.push(s);
	bool flag = true;
	while(!(Q.empty()) && flag){
	      u=Q.front();
	      Q.pop();
	      for(i=0;i<adj[u].size();i++)
		  if(cor[adj[u][i]]==BRANCO){
		     cor[adj[u][i]]=CINZA;
		     d[adj[u][i]]=d[u]+1;
		     Q.push(adj[u][i]);
		     if(i==end)
		        flag = false; 
		  }
	     cor[u]=PRETO;
	}
}


main(){
register int i, j, k, l;
int T, start, end, nforbidden, u, tmp;
char str[10];

	for(i=0; i<10; i++)
	   for(j=0; j<10; j++)
	      for(k=0; k<10; k++)
		 for(l=0; l<10; l++){
		    u = l+10*k+100*j+1000*i;
		    if(l==0){
		       tmp = 1 + 10*k+100*j+1000*i;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		       tmp += 8;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		    }
		    else{
		       tmp = ((l+1)%10)+10*k+100*j+1000*i;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		    }
		    if(k==0){
		       tmp = l+10+100*j+1000*i;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		       tmp += 80;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);			
		    }
		    else{
		       tmp = l+((k+1)%10)*10+100*j+1000*i;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		    }
		    if(j==0){
		       tmp = l+k*10+100+1000*i;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		       tmp += 800;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		    }
		    else{
		       tmp = l+k*10+((j+1)%10)*100+1000*i;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		    }
		    if(i==0){
		       tmp = l+k*10+j*100+1000;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		       tmp += 8000;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);		       

		    }
		    else{
		       tmp = l+k*10+j*100+((i+1)%10)*1000;
		       adj[u].push_back(tmp);
		       adj[tmp].push_back(u);
		    }
		 }

	cin >> T;
	for(int r=0; r<T; r++){
	    start=readNumber();
	    end=readNumber();
	    cin >> nforbidden;
	    for(i=0;i<MAX;i++){
		cor[i]=BRANCO;
		d[i]=INF;
	    }
	    cor[start]=CINZA;
	    for(i=0;i<nforbidden;i++){
		cor[readNumber()]=PRETO;
	    }
	    BFS(start,end);
	    if(d[end]!=INF)
	       cout << d[end] << endl;
	    else
	       cout << "-1" << endl; 
	}
}



