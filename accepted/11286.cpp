#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

#define MAX 100

using namespace std;

int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

main(){
int n;
int v[5];
char str[MAX];
map<string, int> m;
map<string, int> :: iterator it;
int aux, maxval, ans;
	
	while(true){
		scanf("%d",&n);
		if( n == 0)
		   break;
		m.clear();
		maxval = 0;
		for(int lines=0; lines<n; lines++){
		   for(int i=0; i<5; i++)
		      scanf("%d",&v[i]);
		   qsort(v, 5, sizeof(int), cmp);
		   memset(str, '\0', sizeof(str));
		   sprintf(str, "%d%d%d%d%d",v[0],v[1],v[2],v[3],v[4],v[5]);
		   aux = m[str] + 1;

		   m[str] = aux;
		   if(aux > maxval)
		      maxval = aux;
		}
		ans = 0;
		for(it = m.begin(); it != m.end(); it++)
		   if(it->second == maxval)
		     ans += maxval;
		    
		printf("%d\n",ans);
		    
		
	}
	

}

