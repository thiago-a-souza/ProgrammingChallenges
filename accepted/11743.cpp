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

int getSum(int n){
int ans;
    n = n - 48;
	n = n*2;
	ans = n%10;
	n = n/10;
	ans += n;
	return ans;
}


main(){
int t;
char card[4][5];
int sum1, sum2;
	scanf("%d",&t);
	for(int i=0; i<t; i++){
	     scanf("%s %s %s %s",card[0],card[1],card[2], card[3]);
	     sum1 = getSum(card[0][0]) + getSum(card[0][2]) +
	            getSum(card[1][0]) + getSum(card[1][2]) +
	            getSum(card[2][0]) + getSum(card[2][2]) +
	            getSum(card[3][0]) + getSum(card[3][2]);
	     
	     sum2 = ((int)card[0][1])+((int)card[0][3])+
	            ((int)card[1][1])+((int)card[1][3])+
                ((int)card[2][1])+((int)card[2][3])+
   	            ((int)card[3][1])+((int)card[3][3])-384;
   	     if((sum1+sum2)%10 != 0)
   	        printf("Invalid\n");
   	     else
   	        printf("Valid\n");
   	     
	}

	
}

