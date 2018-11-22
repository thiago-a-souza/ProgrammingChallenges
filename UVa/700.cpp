/* Date Bugs -  05/01/2008 */
/* Category: ad hoc */
/* Algoritmo: construir uma tabela com os anos possíveis, encontrar um ocorrencia em comum entre todos anos */
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
#define MAXS 31
#define LIM 10000

using namespace std;

typedef struct{
int y, a, b;
int diff;
}TComp;

TComp comp[30];
bool table[30][LIM];
int imaiordiff, n;

void func(){
int val, count;
bool b;

 		f(i,30)
 		 f(j, LIM)
 		   table[i][j] = false;
 		f(i, n){
 		  count = 0;
 		  val = comp[i].y;
 		  while(val < LIM){
 		  // cout << " Val " << val << endl;
 		  		table[i][val] = true;
 		  		val += comp[i].diff;
 		  }
	    }//cout <<" ->>>" <<table[1][2005] << endl;


      f(i,LIM)
		 if(table[imaiordiff][i]){
		   b = true;
		   f(j, n)
		     if(!table[j][i]){
		        b = false;
		        break;
		     }
		   if(b){
		     printf("The actual year is %d.\n\n",i);
		     return;
		   }
		 }
		printf("Unknown bugs detected.\n\n");

}


main(){
int val, ite=1;
int maiordiff=0;

	while(true){
		scanf("%d",&n);
		if(n == 0)
		  break;
		f(i, n){
 		  scanf("%d %d %d",&comp[i].y,&comp[i].a,&comp[i].b);
 		  comp[i].diff = comp[i].b - comp[i].a;
 		  if(comp[i].diff > maiordiff){
 		    maiordiff = comp[i].diff;
 		    imaiordiff = i;
 		  }
 		}
	
 		printf("Case #%d:\n",ite); ite++;
 		if(n > 1)
 		  func();
 		else{
 		    printf("The actual year is %d.\n\n",comp[0].y);
 		}
		
		      
	}


}



