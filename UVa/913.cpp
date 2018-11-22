#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

using namespace std;

main(){
long long n, sum, an;

		while(scanf("%llu",&n) != EOF){
		      sum = ((1 + n)*(1+n/2))/2;
		      an = 1 + (sum-1)*2;
		      cout << 3*an - 6 << endl;
		}
}

