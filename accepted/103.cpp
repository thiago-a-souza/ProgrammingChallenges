/* Stacking Boxes - 11/02/2008 */
/* Category: dynamic programming lis */
/* Algorithm: sort each box dimmension and then sort all boxes, finally run lis */

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


typedef struct{
int id, num[10];
}TBox;

TBox box[30];
int boxes, dim;
int path[30], ind;
int rev_path[30], rev_ind;
//////////////////////

int cmp(const void *a, const void *b){
TBox *x, *y;
int i = 0;

	x = (TBox*)a;
	y = (TBox*)b;
	
	while( i < dim && x->num[i] == y->num[i] )	
	      i++;
	if(x->num[i] < y->num[i])
	   return -1;
	if(x->num[i] > y->num[i])
	   return 1;
	return 0;
}

bool maior(int a, int b){
int i = 0;

	while(i < dim){
	      if(box[a].num[i] <= box[b].num[i])
	         return false;
	      i++;
	}
	return true;
}

void printPath(int x){

	if(path[x] == -1){
	   rev_path[rev_ind++] = box[x].id;
	   return ;
	}
	rev_path[rev_ind++] = box[x].id;
	printPath(path[x]);

}

int lis(){
int ans=1, seq[30];

	f(i, boxes)
	  seq[i] = 1;
	memset(path, -1, sizeof(path));
	ind = 0;
	
	f(i, boxes - 1)
	 ff(j, i+1, boxes)
	   if(maior(j,i)){
	     if(seq[i] + 1 > seq[j]){
	       seq[j] = seq[i] + 1;
	       path[j] = i;
	       if(seq[j] > ans){
	         ans = seq[j];
	         ind = j;
	       }
	     }
	   }
	
	return ans;
}

int main(){
int val;

	while(scanf("%d %d",&boxes,&dim) == 2){
	      f(i, boxes){
	        box[i].id = i + 1;
	        f(j, dim){
	          scanf("%d",&val);
	          int k = j;
	          while(k > 0 && box[i].num[k-1] > val){
	              box[i].num[k] = box[i].num[k-1];
	              k--;
	          }
	          box[i].num[k] = val;
	        }
	      }
	      
	      qsort(box,boxes,sizeof(TBox),cmp);

	      cout << lis() << endl;
	      rev_ind = 0;
	      printPath(ind);
	      for(int i=rev_ind-1; i>=0; i--)
	         if(i > 0)
	           printf("%d ",rev_path[i]);
	         else
	           printf("%d\n",rev_path[i]);
	}

}


