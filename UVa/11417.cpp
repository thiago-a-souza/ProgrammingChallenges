#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

using namespace std;

int gcd(int a, int b){
      if( b == 0)
         return a;
    return gcd(b,a%b);
}

main(){
int n, g;
map< pair< int, int>, int> results;

    for(int i=1; i<501; i++)
       for(int j=i+1; j<=501; j++){
           results[make_pair(i,j)] = gcd(i,j);
        //   printf("(%d,%d) => %d => %d\n", i,j, results[make_pair(i,j)], gcd(i,j));
       }
           


	while(true){
	     scanf("%d",&n);
	     if(n == 0)
	        break;
	     g = 0;
	     for(int i=1; i<n; i++)
	        for(int j=i+1; j<=n; j++)
	            g += results[make_pair(i,j)];
	     printf("%d\n",g);
	}

}