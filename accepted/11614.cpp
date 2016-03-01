#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(){
int tests;
double n;
long long ans;

	scanf("%d",&tests);
	while(tests--){
          scanf("%lf", &n);
          ans = (long)((-1.0 + sqrt(1.0+8.0*n))/2.0);
          printf("%llu\n", ans);
		
	}

}