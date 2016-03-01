/* What's Cryptanalysis? - 21/01/2008 */
/* Category: ad-hoc sorting */
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
#define debug(x) x

using namespace std;


typedef struct{
int count;
int id;
}TStrc;

int cmp(const void *a, const void *b){
TStrc *x, *y;

	x = (TStrc*)a;
	y = (TStrc*)b;
	if(x->count < y->count)
	  return 1;
	if(x->count > y->count)
	  return 0;
	if(x->id > y->id)
	  return 1;
	if(x->id < y->id)
	  return 0;
	

}


main(){
char str[1000];
TStrc ident[30];
int n;

	while(scanf("%d",&n) == 1){
	     f(i,30)
	      ident[i].count = 0, ident[i].id = i;
	     cin.getline(str,1000);
		 f(i, n){
		   cin.getline(str,1000);
		   f(j,strlen(str))
		     if(str[j]>='a' && str[j]<='z')
		        ident[(int)str[j]-97].count++;
		     else if(str[j]>='A' && str[j] <='Z')
		             ident[(int)str[j]-65].count++;
		 }
		 qsort(ident,30,sizeof(TStrc),cmp);
		 f(i,30)
		   if(ident[i].count > 0)
		     printf("%c %d\n",(char)ident[i].id+65,ident[i].count);
	
	}
	

}


