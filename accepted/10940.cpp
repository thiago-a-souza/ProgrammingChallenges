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

int main(){
int x, s, n;

	while(true){
		scanf("%d",&n);
		if(n == 0)
		   break;
		x = 1;
		while(x < n)
		      x = x*2;
		s = x%n;
		cout << n - s << endl;
	}

return 0;

}