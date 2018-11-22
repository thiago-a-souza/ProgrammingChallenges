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
int a, b, c;
int tmp;
	while(true){
	     scanf("%d %d %d",&a,&b,&c);
	     if(a == 0 && b == 0 && c == 0)
	        break;
	     if(b >= a && b >= c){
	        tmp = a;
	        a = b;
	        b = tmp;
	     } 
	     if(c >= a && c >= b){
	        tmp = a;
	        a = c;
	        c = tmp;
	     }
	     if(b*b + c*c == a*a)
	        printf("right\n");
	     else
	        printf("wrong\n");
	     
	}
}

