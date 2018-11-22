#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 10000

using namespace std;

main(){
int A[MAX];
int n, T;
int sum;

	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		    scanf("%d",&A[i]);
		sum = 0;
		for(int i=1; i<n; i++)
		   for(int j=i-1; j>=0; j--)
		       if(A[j] <= A[i])
		          sum++;
		cout << sum << endl;
	}
	
}