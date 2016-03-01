#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 2005

using namespace std;

int v[MAX], n;
int lis[MAX], lds[MAX];

int max(int a, int b){
	if(a > b)
	  return a;
	return b;
}

void lds_lengths(){
int longest;

	memset(lds, 0, sizeof(lds));
	
	for(int i=0; i<n; i++){
		longest = 0;
		for(int j=0; j<i; j++)
		   if(v[j] < v[i] && lds[j] > longest)
		       longest = lds[j];
		lds[i] = longest + 1;
	}
}




void lis_lengths(){
int longest;

	memset(lis, 0, sizeof(lis));
	
	for(int i=0; i<n; i++){
		longest = 0;
		for(int j=0; j<i; j++)
		   if(v[j] > v[i] && lis[j] > longest)
		       longest = lis[j];
		lis[i] = longest + 1;
	}
}




main(){
int t;
int ans;
int aux;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		    scanf("%d",&v[i]);
		
		for(int i=0, j=n-1; i<n/2; i++, j--){
		    aux = v[i];
		    v[i] = v[j];
		    v[j] = aux;
		}
		lis_lengths();
		lds_lengths();
		
		ans = 0;
		for(int i=0; i<n; i++)
		   ans = max(ans, lis[i] + lds[i] - 1);
		cout << ans << endl;
		
	
	}
}