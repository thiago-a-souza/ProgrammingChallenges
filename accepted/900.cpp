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

using namespace std;

main(){
int fib[51];
int n;

		fib[1] = 1;
		fib[2] = 2;
		for(int i=3; i<51; i++)
		   fib[i] = fib[i-1] + fib[i-2];
		 
	    while(true){
	          scanf("%d",&n);
	          if( n == 0 )
	              break; 
	          cout << fib[n] << endl;
	    }		  

}