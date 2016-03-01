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
int n, e, f, c;
int drinks, bottles;

	scanf("%d",&n);
	while(n--){
	     scanf("%d %d %d",&e,&f,&c);
	     drinks = 0;
	     bottles = e + f;
	     while(bottles - c >= 0){
	           bottles = bottles - c + 1;
	           drinks++;
	     }
	     printf("%d\n",drinks);
	}
}

