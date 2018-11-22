#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 20001

using namespace std;

int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

main(){
int n, m;
int heads[MAX], knights[MAX];
int price, chopoff;
int index;
	while(true){
	    scanf("%d %d",&n,&m);
	    if(!n && !m)
	       break;
	    for(int i=0; i<n; i++)
	        scanf("%d",&heads[i]);
	    for(int i=0; i<m; i++)
	        scanf("%d",&knights[i]);
	    qsort(heads, n, sizeof(int), cmp);
	    qsort(knights, m, sizeof(int), cmp);
	    price = 0; index = 0; chopoff = 0;
	    for(int i=0; i<n; i++){
	       for(int j=index; j<m; j++){
	           if(knights[j] >= heads[i]){
	              price += knights[j];
	              chopoff++;
	              index = j + 1;
	              break;
	           }
	           index = j + 1;
	       }
	    }
	    if(chopoff == n)
	       cout << price << endl;
	    else
	       cout << "Loowater is doomed!" << endl;
	    
	}
}

