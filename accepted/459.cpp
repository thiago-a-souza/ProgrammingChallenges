/* Graph Connectivity - 18/06/2007 */
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

#define MAX 300
#define MAX2 30
#define BRANCO 1
#define CINZA 2
#define PRETO 3

vector<int> adj[MAX2];
int cor[MAX2];


void dfs(int s){
register int i;

	cor[s] = CINZA;
	for(i=0; i<adj[s].size(); i++)
	   if(cor[adj[s][i]]==BRANCO){
	      cor[adj[s][i]] = CINZA;
	      dfs(adj[s][i]);
	   }
	cor[s] = PRETO;
}

void initialize(int maior){
register int i;

	for(i=0; i<maior; i++)
	   cor[i] = BRANCO;

}

main(){
register int i, j, k;
char str[MAX];
int n, maior, cont;
bool verd;

	cin.getline(str,MAX);
	n = atoi(str);
	cin.getline(str,MAX);
	for(i=0; i<n; i++){
	   cin.getline(str,MAX);
	   if(i>0)
	     cout << endl;
	   for(j=0; j<strlen(str); j++)
	      if(str[j]!=' ')
	        break;
	   maior = str[j]-64;
	   initialize(maior);
	   cin.getline(str,MAX);	   
	   while(strlen(str)>0){
	        for(j=0; j<strlen(str); j++)
	           if(str[j]!=' ')
	             break;
	        for(k=j+1; k<strlen(str); k++)
	           if(str[k]!=' ')
	             break;
	        adj[(int)str[j]-65].push_back((int)str[k]-65);
	        adj[(int)str[k]-65].push_back((int)str[j]-65);
	        cin.getline(str,MAX);
	   }
/*	   for(j=0; j<maior; j++){
	      for(k=0; k<adj[j].size(); k++)
	         cout << adj[j][k] << " ";
	      cout << endl;
	   }   
	         
cout << "passou\n";*/
	   cont = 0;
	   verd = true;
	   while(verd){
	        verd = false;
	        for(j=0; j<maior; j++)
	           if(cor[j]==BRANCO){
	             cont++;
	             dfs(j);
	             verd = true;
	           }  
	   }
	   cout << cont << endl;
	   for(j=0; j<maior; j++)
	      adj[j].clear();
	}
}

