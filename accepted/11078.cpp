#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

#define MAX 999999999

using namespace std;

int main(){
int tests, n;
int maxVal, maxDiff;
int a, b, next;

	scanf("%d", &tests);
	while(tests--){
		scanf("%d",&n);
		scanf("%d",&a);
		scanf("%d",&b);
		maxVal = a;
		if(b > maxVal)
		   maxVal = b;
		
		maxDiff = a - b;
		for(int i=0; i<n-2; i++){
		    scanf("%d", &next);
		    if(maxVal - next > maxDiff)
		       maxDiff = maxVal - next;
		    if(next > maxVal)
		       maxVal = next;
		}
		printf("%d\n", maxDiff);
	
	}


	return 0;
	
}

