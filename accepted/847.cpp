#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 4294967295 


using namespace std;

main(){
long long p, s;
bool b;
		while(scanf("%llu",&s) != EOF){
		     b = false;
             p = 1; 
		     while(true){
		           if(!b)
		             p *= 9;
		           else
		             p *= 2;
		           if(p >= s)
		              break;
		           b = !b;
		     }
		     if(!b)
		       printf("Stan wins.\n");
		     else
		       printf("Ollie wins.\n");
		}
}

