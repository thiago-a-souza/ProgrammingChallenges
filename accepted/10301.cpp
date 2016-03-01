/* Rings and Glue - 18/01/2008 */
/* Category: geometry - intersection */

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
#define SQR(x) ((x)*(x))

using namespace std;

typedef struct{
	double x, y, rad;
	int grp;
}TRing;

/* global variables */
TRing ring[101];
int n_rings, qtd[101];

bool interceptRing(int a, int b){
double dist;

	dist = sqrt(SQR(ring[a].x - ring[b].x) + SQR(ring[a].y - ring[b].y));
	if((dist < ring[a].rad + ring[b].rad) && (fabs(ring[a].rad - ring[b].rad) < dist))
	   return true;
	return false;
}

void joinRing(int a, int b){
int tmp;

	if(ring[a].grp == ring[b].grp)
	  return;
	
	tmp = ring[b].grp;
	
	f(i, n_rings)
	  if(ring[i].grp == tmp){
	    ring[i].grp = ring[a].grp;
	    qtd[ring[a].grp]++;
	  }
	qtd[tmp] = 0;
}


main(){
int biggest;

	while(true){
	     scanf("%d",&n_rings);
	     if(n_rings == -1)
	        return 0;
	     f(i, n_rings){
	       scanf("%lf %lf %lf",&ring[i].x,&ring[i].y,&ring[i].rad);
	       ring[i].grp = i;
	       qtd[i] = 1;
	     }
	     
	     f(i, n_rings)
	       f(j, i)
	         if(interceptRing(i,j)){
	           joinRing(i,j);
	         }

	     biggest = 0;
	     f(i, n_rings)
	       if(qtd[i] > biggest)
	          biggest = qtd[i];
	     if(biggest == 1)
	       printf("The largest component contains 1 ring.\n");
	     else
	       printf("The largest component contains %d rings.\n",biggest);
	}
}



