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

using namespace std;

void sternBrocot(int x1, int y1){
int a = 0, b = 1, c = 1, d = 0;
int x = 1, y = 1;

    if(x1 == 0){
       cout << "L";
       return;
    }
    
    while((x != x1) || (y != y1)){
         if(x1*y < y1*x){
            cout << "L";
            c = x;
            d = y;
            x += a;
            y += b;
         } else {
            cout << "R";
            a = x; 
            b = y;
            x += c;
            y += d;
         }
    }
    
}

main(){
int m, n;

	while(true){
	     scanf("%d %d",&m,&n);
	     if(m == 1 && n == 1)
	        break;
	     sternBrocot(m,n);
	     printf("\n");
	     
	}

}

