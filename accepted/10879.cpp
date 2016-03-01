#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

main(){
int t, line = 1;
long long n, val , a, b, c, d;

	scanf("%d",&t);
	while(t--){
	     cin >> n;
	     a = -1; b = -1; c = -1; d = -1;
	     for(int i=2; i<=10000000; i++){
	         if(n%i == 0){
	            if(a == -1){
	               a = i;
	               b = n/i;
	            } else if(a != i && a != n/i && b != i && b != n/i){
	                      c = i;
	                      d = n/i;
	                      break;
	            }
	         }
	     }
	     cout << "Case #" << line << ": " << n << " = " << a << " * " <<
	     b << " = " << c << " * " << d << endl;
	     line++;
	}
}

