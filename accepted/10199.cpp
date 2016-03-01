/* Tourist Guide - 16/08/2007 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack>  

#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define mp(a,b) make_pair((a),(b))
#define all(c) (c).begin(),(c).end()
#define FOR(i,v,n) for(int i=v; i<n; i++)
#define FORD(i,v,n) for(int i=(n-1); i>=v; i--)
#define rep(i,n) FOR(i,0,n)
#define repd(i,n) FORD(i,0,n)
#define pb push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define MAX_V 100
#define MAX_A
#define INF
#define PRINT(x)
#define WHITE 1
#define GRAY 2
#define BLACK 3
const double PI = acos(-1.0); 

using namespace std; 


int cor[MAX_V], low[MAX_V], num[MAX_V], parent[MAX_V];
int idVertex;
set<int> artPoint;

map<int,string> citName;
map<string,int> citNum;
vector<string> ans;
vector<int> adj[MAX_V];
int visitado[MAX_V], n;


void _clearArtic(){

	for(int i=0; i<MAX_V; i++)
	   cor[i] = WHITE;
	artPoint.clear();
	idVertex = 1;
}

void findArticulation(int v){

	cor[v] = visitado[v] = BLACK;
	num[v] = low[v] = idVertex++;
	for(int i=0; i<adj[v].size(); i++){
	   if(cor[adj[v][i]] == WHITE){
	     parent[adj[v][i]] = v;
	     findArticulation(adj[v][i]);
	     if(low[adj[v][i]] >= num[v])
	       artPoint.insert(v);
	     low[v] = MIN(low[v],low[adj[v][i]]);
	   }
	   else if(parent[v] != adj[v][i])
	   		low[v] = MIN(low[v],num[adj[v][i]]);
	
	}
}

void checkArticulation(int inicial){
set<int> tmp;
set<int> :: iterator it;

	_clearArtic();
	findArticulation(inicial);
	tmp = artPoint;
	_clearArtic();
	findArticulation(adj[inicial][0]);
	if(artPoint.find(inicial) != artPoint.end())
	  for(it=tmp.begin(); it!=tmp.end(); it++)
	     ans.pb(citName[*it]);
	else
	  for(it=tmp.begin(); it!=tmp.end(); it++)
	     if(*it != inicial)
	        ans.pb(citName[*it]);	
}

void _clearBuffer(){
	for(int i=0; i<n; i++){
	   visitado[i] = WHITE;
	   adj[i].clear();
	}
	ans.clear();
	citName.clear();
	citNum.clear();
}

void readInput(){
char str[100];
int x, y, r;

	_clearBuffer();
	for(int i=0; i<n; i++){
		scanf("%s", str);
		citName[i] = str;
		citNum[str] = i;
	}
	scanf("%d",&r);
	for(int i=0; i<r; i++){
	   scanf("%s", str);
	   x = citNum[str];
	   scanf("%s", str);
	   y = citNum[str];
	   adj[x].pb(y);
	   adj[y].pb(x);
	}

}

main(){
bool b;
int ite=1;
	scanf("%d",&n);
	while(n){
		 if(ite > 1)
		   cout << endl;
		 readInput();
		 b = true;
		 while(b){
		      b = false;
		      for(int i=0; i<n; i++)
		         if(!adj[i].empty() && visitado[i]==WHITE){
		           checkArticulation(i);
		           b = true;
		           break;
		         }
		 }
		 printf("City map #%d: %d camera(s) found\n",ite,ans.size());
		 ite++;
		 sort(all(ans));
		 for(int i=0; i<ans.size(); i++)
		    cout << ans[i] << endl;
	     scanf("%d",&n);
	}

}

