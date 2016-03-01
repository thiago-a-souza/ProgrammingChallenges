#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
int tests;
int n;
int call, tmp;
int line = 1;
int mile, juice;
	scanf("%d",&tests);
	while(tests--){
	     scanf("%d",&n);
	     mile = 0; juice = 0;
	     for(int i=0; i<n; i++){
	         scanf("%d",&call);
	         mile += ((call/30)*10) + 10;
	         juice += ((call/60)*15) + 15;
	         
	     }
	     if(mile < juice)
	        printf("Case %d: Mile %d\n",line, mile);
	     else if(juice < mile)
	             printf("Case %d: Juice %d\n", line, juice);
	     else printf("Case %d: Mile Juice %d\n", line, juice);
	     line++;
	     
	}

}

