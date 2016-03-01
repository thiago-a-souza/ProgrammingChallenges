#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<queue>

#define MAX 100
using namespace std;

main(){
int T, N;
int walls[MAX];
int low, high;
int line = 1;

	scanf("%d",&T);
	while(T--){
	    scanf("%d",&N);
	    for(int i=0; i<N; i++)
	       scanf("%d",&walls[i]);

	    low = 0; high = 0;
	    for(int i=0; i<N-1; i++){
	        if(walls[i] < walls[i+1])
	           high++;
	        else if(walls[i] > walls[i+1])
	                low++;
	    }
	    printf("Case %d: %d %d\n",line,high,low);
	    line++;
	           
	}


}

