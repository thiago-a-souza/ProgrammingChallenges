/* Relational Operators */
/* Category: ad hoc - very very very eaaaasy */
#include<iostream>

using namespace std;

main(){
int t;
long long v1, v2;

	scanf("%d",&t);
	while(t--){
	    scanf("%llu %llu",&v1,&v2);
		if(v1-v2 < 0)
		  printf("<\n");
		else if(v1-v2 > 0)
		        printf(">\n");
		else printf("=\n");
		
	}

}
