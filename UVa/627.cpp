/* The Net - 21/06/2007 */
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cctype>

using namespace std;

#define BRANCO '1'
#define CINZA '2'
#define PRETO '3'
#define MAX 305
#define INF 320000

vector <int> adj[MAX];
char cor[MAX];
int p[MAX];
int last;

void BFS(int s, int end){
register int i;
int u;
queue<int> Q;

	for(i=0; i<MAX; i++){
	   cor[i]=BRANCO;
	   p[i]=-1;   
	}
	   
	p[s]=s;
	Q.push(s);
	bool flag = true;
	while(!(Q.empty()) && flag){
	      u=Q.front();
	      Q.pop();
	      for(i=0;i<adj[u].size();i++)
		  if(cor[adj[u][i]]==BRANCO){
		     cor[adj[u][i]]=CINZA;
		     p[adj[u][i]] = u;
		     Q.push(adj[u][i]);
		  }
	     cor[u]=PRETO;
	}
}

void printPath(int s){

	if(p[s]==-1){
	  cout << "connection impossible";
	  return;
	} 
	if(p[s]!=s)
	  printPath(p[s]);
	if(s!=last)
	  printf("%d ",s);
	else
	  printf("%d",s);
}

main(){
register int i, j;
int n, orig, dest, tam, tmp;
char str[MAX], ch;


	while(cin.getline(str,MAX)){
	     n = atoi(str);
	     for(i=0; i<n; i++){
	        cin.getline(str,MAX);
	        tam = strlen(str);
	        j = 0;
	        while(!isdigit(str[j]) && j<tam)
	             j++;
	        orig = atoi(&str[j]);
	        while(j<tam){
	              while(isdigit(str[j]) && j<tam)
	                    j++;
	              while(!isdigit(str[j]) && j<tam)
	                    j++;
	              if(j<tam){
	                tmp = atoi(&str[j]);
	                adj[orig].push_back(tmp);
	              }
	        }
	     }
	     cin >> n;
	     cout << "-----\n";
	     for(i=0; i<n; i++){
	        cin >> orig >> dest;
	        last = dest;
	        BFS(orig,dest);
	        printPath(dest);
	        cout << endl;
	     }
	     for(i=0; i<MAX; i++)
	        adj[i].clear();
	     ch = getchar();
	     
	}
}

