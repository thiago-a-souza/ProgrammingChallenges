/* Rails - 14/01/2008 */
/* Category: sorting */
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
#define debug(x)  x

using namespace std;

int num[1010], n;

bool rail(){
int index = 0, pos = 1;
int pilha[1010], ipilha=0;

	while(true){
	
	     if(pos == n + 1 && ipilha > 0 && pilha[ipilha-1] != num[index])
	       return false;
	     else if(pos == n + 1 && ipilha == 0)
	             return true;	
	
	     if(ipilha > 0 && pilha[ipilha-1] == num[index]){
	        ipilha--;
	        index++;
	        continue;
	     }
	     if(num[index] == pos){
	       pos++;
	       index++;
	       continue;
	     }
	     else if(pos <= n){
	     	     pilha[ipilha++] = pos;
	             pos++;
	     	  }
	}
}

main(){
int iter = 0;

	while(true){
	     scanf("%d",&n);
	     if(n == 0)
	        break;

	     if(iter != 0)
	       printf("\n");
	     iter++;

	     while(true){
	          scanf("%d",&num[0]); 
	          
	          if(num[0] == 0)
	             break;
	             
	          ff(i, 1, n)
	            scanf("%d",&num[i]);
	          if(rail())
	            printf("Yes\n");
	          else
	            printf("No\n");
	     
	     }
	}
	printf("\n");
}


