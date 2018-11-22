#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 25000
using namespace std;


int cmp(const void * a, const void * b){
  return ( *(int*)b - *(int*)a );
}

int main(){
int tests, n, ans;
int v[MAX];

	scanf("%d", &tests);
	while(tests--){
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		   scanf("%d",&v[i]);
		qsort(v, n, sizeof(int), cmp);
		ans = 0;
		for(int i=2; i<n; i+=3)
		    ans += v[i];
		printf("%d\n", ans);
		
	}
	return 0;
}