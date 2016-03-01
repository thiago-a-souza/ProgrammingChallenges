/* The Necklace - 14/01/2008 
Category: eulerian graph - hard to code
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define mp(a,b) make_pair((a),(b))
#define all(c) (c).begin(),(c).end()
#define ff(i,v,n) for(int i=v; i<n; i++)
#define f(i,n) ff(i,0,n)
#define pb push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define debug(x) 
#define MAX_V 90
#define MAX_A 1010

using namespace std;

vector<int> ePath, circuit;
int adj[MAX_V][MAX_A], grau[MAX_V], edges;
int visited[MAX_V];
int start;


void showAdj(){
	ff(i,1,5){
	  cout << i << "=> ";
	  f(j,grau[i])
	   cout << adj[i][j] << " ";
	  cout << endl;
	}
}

int findVertex(){
	f(i, ePath.size())
	 if(grau[ePath[i]] > 1)
	    return ePath[i];

}

void insertCicle(){
	if(ePath.size() == 0)
	  ePath.insert(ePath.begin(), circuit.begin(), circuit.end());
	else{
	  for(vector<int>::iterator it=ePath.begin(); it!=ePath.end(); it++)
	     if(*it == start){
	       ePath.insert(it,circuit.begin(), circuit.end()-1);
	       break;
	     }
	}

}

void removeEdge(int u, int v){
	edges--;
	f(i, grau[u])
	  if(adj[u][i] == v && grau[u] > 1){
	    adj[u][i] = adj[u][grau[u]-1];
	    break;
	  }
	grau[u]--;
	f(i, grau[v])
	  if(adj[v][i] == u && grau[v] > 1){
	    adj[v][i] = adj[v][grau[v]-1];
	    break;
	  }
	grau[v]--;
}

void findCicle(int u, int v){
	removeEdge(u, v);
	if(v == start)
	  return;
	circuit.pb(v);
	u = v;
	v = adj[v][0];
	findCicle(u, v);
}




void getEulerian(){
int u, v;

	f(i, MAX_V)
	  if(grau[i] > 1){
	     start = i;
	     break;
	  }
	  
	circuit.pb(start);
	u = start; v = adj[u][0];
	
	while(true){
	     findCicle(u, v);
	     circuit.pb(start);
	     insertCicle();
	     if(edges < 1)
	       return;
	     circuit.clear();
	     start = findVertex();
	     u = start;
	     v = adj[start][0];
	     circuit.pb(start);
	}
}


void dfsVisit(int s){
int t;
	visited[s] = 1;
	f(i, grau[s]){
	   t = adj[s][i];
	   if(!visited[t])
	     dfsVisit(t);
	}
}


bool isEulerian(){

	f(i, MAX_V)
	  if(grau[i]%2 != 0)
	     return false;

	memset(visited, 0, sizeof(visited));	     
	     
	f(i, MAX_V)
	  if(grau[i] > 0){
	     dfsVisit(i);
	     break;
	  }
	
	f(i, MAX_V)
	  if(grau[i] > 0 && visited[i] == 0)
	     return false;

	return true;
}

main(){
int t, u, v;
int iter = 1;


	scanf("%d",&t);
	while(t--){
	
	     if(iter != 1)
	       printf("\n");
	       
	     scanf("%d",&edges);

	     memset(grau, 0, sizeof(grau));
	     
	     f(i, edges){
	       scanf("%d %d",&u, &v);
	       adj[u][grau[u]++] = v;
	       adj[v][grau[v]++] = u;
	     }

	     printf("Case #%d\n", iter);
	     iter++;
	     
	     if(isEulerian()){
	       getEulerian();
	       f(i, ePath.size()-1)
	        printf("%d %d\n",ePath[i], ePath[i+1]);
	       ePath.clear();
	       circuit.clear();
	     }
	     else
	        printf("some beads may be lost\n");
	     
		
	}

}















