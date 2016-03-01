#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <stack>

#define MAX 30 

using namespace std;

int adj[MAX][MAX], invAdj[MAX][MAX];
int grau[MAX], invGrau[MAX];
int visited[MAX];
int id;
int N, M;

stack<int> S;

void dfsVisit(int v){

	visited[v] = 1;
	for(int i=0; i<grau[v]; i++)
	    if(!visited[adj[v][i]])
	       dfsVisit(adj[v][i]);
	S.push(v);
}

void dfsVisit2(int x){

	visited[x] = id;
	for(int i=0; i<invGrau[x]; i++)
	    if(!visited[invAdj[x][i]]){
	       dfsVisit2(invAdj[x][i]);
	    }

}


void kosaraju(int start, int end){
int u;

	memset(visited, 0, sizeof(visited));
	for(int i=start; i<end; i++)
	    if(!visited[i]){
           dfsVisit(i);
        }  
	memset(visited, 0, sizeof(visited));
	id = 1;
	while(!S.empty()){
	      u = S.top(); S.pop();
	      if(!visited[u]){
	         dfsVisit2(u);
	         id++;
	      } 
	}	     
}

main(){
char a[MAX], b[MAX];
int vertexes;
map<string, int> ms;
map<int, string> mi;
int u, v;
int line = 1;
bool first; 
//////////////////
/*int rows; 

	scanf("%d",&rows);
	memset(grau, 0, sizeof(grau));
	memset(invGrau, 0, sizeof(invGrau));
	for(int i=0; i<rows; i++){
	   scanf("%d %d",&u,&v);
	   adj[u][grau[u]++] = v;
	   invAdj[v][invGrau[v]++] = u;
	}
	
	for(int i=1; i<=8; i++){
	   printf("%d: ",i);
	   for(int j=0; j<grau[i]; j++)
	      printf("%d ", adj[i][j]);
	   printf("\n");
	}
	puts("");
	for(int i=1; i<=8; i++){
	   printf("%d: ",i);
	   for(int j=0; j<grauT[i]; j++)
	      printf("%d ", adjT[i][j]);
	   printf("\n");
	}
	kosaraju(1,8); */


//////////////////


	while(true){
	     scanf("%d %d",&N,&M);
	     if(N == 0 && M == 0)
	        break;
	     ms.clear(); mi.clear();
	     memset(grau, 0, sizeof(grau));
	     memset(invGrau, 0, sizeof(invGrau));
	     vertexes = 1;
		 for(int i=0; i<M; i++){
		    scanf("%s %s",a,b);
		    if(ms[a] <= 0){
		       ms[a] = vertexes;
		       mi[vertexes] = a;
		       vertexes++;
		    }
		    if(ms[b] <= 0){
		       ms[b] = vertexes;
		       mi[vertexes] = b;
		       vertexes++;
		    }
		    u = ms[a]; v = ms[b];
		    adj[u][grau[u]++] = v;
		    invAdj[v][invGrau[v]++] = u;
		 }
		 
	
	
		 
		 kosaraju(1, vertexes);

		 if(line > 1) 
		    printf("\n");
		 
		 printf("Calling circles for data set %d:\n",line++);
		 for(int i=1; i<id; i++){
		    first = true;
		    for(int j=1; j<vertexes; j++){            
		       if(visited[j] == i){
		          if(first){
		             first = false;
		             cout << mi[j];
		          } else { 
		             cout << ", " << mi[j] ;
		          }
		       }
		    }
		    cout << endl;
		 }
	}
}

