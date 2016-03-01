#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

using namespace std;

main(){
long long a, b, c;
int n, v;
int scenario = 1;

		scanf("%d",&n);
		while(n--){
		     scanf("%d",&v);
		     printf("Scenario #%d:\n", scenario);
		     scenario++;
		     if(v == 0){
		        printf("1\n\n");
		        continue;
		     }
		     else if(v == 1){
		             printf("2\n\n");
		             continue;
		     }
		    
		     a = 1; b = 2;
		     for(int i=2; i<=v; i++){
		         c = a + b;
		         a = b; 
		         b = c;
		     }
		     printf("%llu\n\n",c);
		}

}

