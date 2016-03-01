/*All Roads Lead Where? - 31/07/2007 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

#define BRANCO '1'
#define CINZA '2'
#define PRETO '3'
#define MAX 100
#define INF 320000

vector <int> adj[MAX];
char cor[MAX];
int d[MAX], p[MAX];

void BFS(int s, int end){
register int i;
int u;
queue<int> Q;

	for(i=0; i<MAX; i++){
	   p[i]=-1;
	   d[i]=INF;
	}
	memset(cor,BRANCO,sizeof(cor));
	p[s]=s;
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
		     p[adj[u][i]]=u;
		     Q.push(adj[u][i]);
		  }
	     cor[u]=PRETO;
	}
}

void printFather(int f){

	if(p[f]!=f){
	  printFather(p[f]);
	printf("%c",p[f]+65);
	}
}

int main(){
register int i, j;
int m, n, t;
int tmp1, tmp2;
string str1, str2;


	cin >> t;
	for(i=0; i<t; i++){
	   cin >> m >> n;
	   for(j=0; j<m; j++){
	      cin >> str1 >> str2;
	      tmp1=str1[0]%65;
	      tmp2=str2[0]%65;
	      adj[tmp1].push_back(tmp2);
	      adj[tmp2].push_back(tmp1);
	   }
	   for(j=0; j<n; j++){
	      cin >> str1 >> str2;
	      tmp1=str1[0]%65;
	      tmp2=str2[0]%65;
	      BFS(tmp1,tmp2);
	      printFather(tmp2);
	      printf("%c\n",tmp2+65);
	   
	   }
	   for(j=0; j<MAX; j++)
	       adj[j].clear();
	   if(i+1!=t)
	     cout << endl;
	     
	}

}
