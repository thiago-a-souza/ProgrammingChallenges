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
int n;
int drinks;
	while(true){
	    scanf("%d",&n);
	    if(n == 0)
	       break;
	    drinks = 0;
	    while(n - 3 >= 0){
	         n = n - 2;
	         drinks++;
	    }
	    if(n == 2)
	       drinks++;
	    printf("%d\n",drinks);
	}
}