/* Is Bigger Smarter? - 27/01/2008 */
/* Category: dynamic programming lis */
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

using namespace std;

typedef struct {
int weight, iq, id;

} TEleph;

TEleph elephant[1000];
int length[1000], parent[1000];
int path[1000], size_path;

int cmp(const void *x, const void *y){
TEleph *a, *b;

	a = (TEleph*) x;
	b = (TEleph*) y;
	if(a->weight < b->weight)
	  return -1;
	if(a->weight > b->weight)
	   return 1;
	if(a->iq > b->iq)
	   return -1;
	if(a->iq < b->iq)
	   return 1;
	return 0;

}

void printPath(int index){

	if(index == parent[index]){
	  path[size_path++] = elephant[index].id;
	  return;
	}
	path[size_path++] = elephant[index].id;
	printPath(parent[index]);

}
 
main(){
int n = 0, max, index;


	while(cin >> elephant[n].weight >> elephant[n].iq){
		  elephant[n].id = n+1;
		  n++;
	}
	qsort(elephant, n, sizeof(TEleph), cmp);

	f(i,1000){
	  length[i] = 1;
	  parent[i] = i;
	}
	
	f(i,n-1)
	  ff(j,i+1,n)
	     if(elephant[j].weight > elephant[i].weight && elephant[j].iq < elephant[i].iq)
	       if(length[i] + 1 > length[j]){
	          length[j] = length[i] + 1;
	          parent[j] = i;
	       }

	max = -1;
	f(i,n)
	  if(length[i] > max){
	    max = length[i];
	    index = i;
	  }
	  
	
	size_path = 0;
	printPath(index);
	printf("%d\n",size_path);
	for(int i=size_path-1; i>=0; i--)
		  printf("%d\n",path[i]);
		 
}


