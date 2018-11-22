#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

#define MAX 200000

using namespace std;

int p[MAX], sz[MAX];

int findSet(int x){
	if(x != p[p[x]])
	  p[x] = findSet(p[x]);
	return p[x];
}

void unionSet(int a, int b) {
int i = findSet(a);
int j = findSet(b);

	if(i == j)
	   return;

  // make smaller root point to larger one
    if(sz[i] < sz[j]){ 
      p[i] = j; sz[j] += sz[i]; 
    } else { 
      p[j] = i; sz[i] += sz[j]; 
    }

}

main(){
int tests, f; 
char nme1[30], nme2[30];
map< string, int> mp;
int id, a, b;
int root1, root2;

	scanf("%d",&tests);
	while(tests--){
		scanf("%d",&f);
		for(int i=1; i<MAX; i++){
		   p[i] = i;
		   sz[i] = 1;
		} 
		id = 1; mp.clear();
		for(int i=0; i<f; i++){
		    memset(nme1, '\0', sizeof(nme1));
		    memset(nme2, '\0', sizeof(nme2));
		    scanf("%s %s",nme1, nme2);
		    if(mp[nme1] == 0)
		       mp[nme1] = id++;
		    if(mp[nme2] == 0)
		       mp[nme2] = id++;
		    a = mp[nme1]; b = mp[nme2];
		    unionSet(a,b);
		    root1 = findSet(a);
		    root2 = findSet(b);
		    if(root1 > root2)
		      printf("%d\n",sz[root1]);
		    else
		      printf("%d\n",sz[root2]);
		    
		    
		    
		}
	}

}