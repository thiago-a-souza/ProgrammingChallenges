/* Beverages - 26/08/2007 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack>  

#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define MP(a,b) make_pair((a),(b))
#define ALL(c) (c).begin(),(c).end()
#define FOR(i,v,n) for(int i=v; i<n; i++)
#define FORD(i,v,n) for(int i=(n-1); i>=v; i--)
#define REP(i,n) FOR(i,0,n)
#define REPD(i,n) FORD(i,0,n)
#define PB push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define MAX_V 300
#define MAX_A 300
#define INF 10e9 
#define PRINT(x)
const double PI = acos(-1.0); 

using namespace std;

/* topological_sort */
int adj[MAX_V][MAX_A], grau[MAX_V], used[MAX_V];
int indegree[MAX_V];
queue<int> L;
/* read input */
set<string> drinks;
map<string,int> DrinkNum;
map<int,string> NumDrink;

void topological_sort(){
priority_queue< pair<int,int> > z; //grau,vertice
int v, w;


	memset(indegree, 0, sizeof(indegree)); 
	REP(i, MAX_V)
	   if(grau[i])
	   	REP(j, grau[i])
	   	   indegree[adj[i][j]]++;

	REP(i, MAX_V)
	   if(used[i] && !indegree[i]){ PRINT(cout << " i " << i << endl;)
	     z.push(MP(-indegree[i], -i));}

	while(!z.empty()){
		v =-(z.top().second); z.pop(); PRINT(cout << "v " << v << endl;)
		L.push(v);
		REP(i, grau[v]){
		   w = adj[v][i];
		   indegree[w]--;
		   if(!indegree[w]){
		     z.push(MP(-indegree[w],-w));}
		}
	}
}

void readInput(int n){
char str[60];
int count, m;
int a, b;
	count = 1;
	REP(i, n){
		scanf("%s",str);
		if(drinks.find(str) == drinks.end()){
		  DrinkNum[str] = count; PRINT( cout << str << " " << count << endl;)
		  NumDrink[count] = str;
		  used[count] = 1;
		  count++;
		}
	}
	scanf("%d",&m);
	REP(i, m){
		scanf("%s",str);
		a = DrinkNum[str];
		scanf("%s",str);
		b = DrinkNum[str];
		adj[a][grau[a]++] = b;
	}
}

void clearBuffer(){

	drinks.clear();
	DrinkNum.clear();
	NumDrink.clear();
}

void showOutput(){
int num;

	while(!L.empty()){
		num = L.front();
	     L.pop();
	     cout << NumDrink[num];
	     if(!L.empty())
	       cout << " ";
	     else{
	       cout << ".\n";
	       break;
	     }
	}
	cout << endl;
}

main(){
int n, ite;
	ite = 1;
	while(scanf("%d",&n)==1){
		memset(grau, 0, sizeof(grau));
		memset(used, 0, sizeof(used));
		clearBuffer();
		readInput(n);
		topological_sort();
		printf("Case #%d: Dilbert should drink beverages in this order: ", ite);
		ite++;
		showOutput();
	}

}


