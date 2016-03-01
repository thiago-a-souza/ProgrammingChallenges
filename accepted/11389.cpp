#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 10005

using namespace std;

int cmp1(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int cmp2(const void * a, const void * b){
  return ( *(int*)b - *(int*)a );
}

main(){
int morning[MAX], afternoon[MAX];
int n, d, r;
int ans;

	while(true){
		scanf("%d %d %d",&n,&d,&r);
		if(!n && !d && !r)
		   break;
		for(int i=0; i<n; i++)
		    scanf("%d",&morning[i]);
		for(int i=0; i<n; i++)
		    scanf("%d",&afternoon[i]);
		qsort(morning, n, sizeof(int), cmp1);
		qsort(afternoon, n, sizeof(int), cmp2);
		ans = 0;
		for(int i=0; i<n; i++){
			if(morning[i] + afternoon[i] > d)
			   ans += ((morning[i] + afternoon[i] - d)*r);
		}
		cout << ans << endl;
	}
}