#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>

#define MAX 20

using namespace std;

main(){
int vals[MAX];
int datasets, n, h;
bool first = true;

		scanf("%d",&datasets);
		while(datasets--){
		     scanf("%d %d",&n,&h);
		     if(!first)
		        printf("\n");
		     first = false;
		     for(int i=0; i<n; i++)
		         vals[i] = 0;
		     for(int i=n-1, j=0; j<h; j++, i--)
		         vals[i] = 1;
		     do {
		        for(int i=0; i<n; i++)
		           printf("%d",vals[i]);
		        printf("\n");
		     } while(next_permutation(vals, vals+n)); 
		}
	
}